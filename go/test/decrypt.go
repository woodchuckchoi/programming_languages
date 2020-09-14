package main

import (
	"fmt"
	"io"
	"io/ioutil"
	"os"
	"path/filepath"
	"time"

	"github.com/woodchuckchoi/crypto"
)

func main() {
	var DIR string

	if dir := os.Getenv("CRYPTO"); dir != "" {
		DIR = dir
	} else {
		DIR = "/crypto/"
	}

	SAVE := filepath.Join(DIR, "cracked")

	if _, err := os.Stat(SAVE); os.IsNotExist(err) {
		os.Mkdir(SAVE, os.FileMode(0777))
	}

	for {
		files, err := ioutil.ReadDir(DIR)
		if err != nil {
			panic(err)
		}
		if len(files) == 1 && files[0].Name() == "cracked" {
			fmt.Println("NO JOBS IN THE QUEUE!")
		} else {
			for _, fileInfo := range files {
				if fileInfo.IsDir() {
					continue
				}
				file := fileInfo.Name()
				abs := filepath.Join(DIR, file)

				fo, err := os.Open(abs)
				if err != nil {
					panic(err)
				}

				buf := make([]byte, 128)

				fi, err := os.Create(filepath.Join(SAVE, file+"_cracked"))

				for {
					n, err := fo.Read(buf)

					if err != nil && err != io.EOF {
						panic(err)
					}

					if n == 0 {
						fi.Close()
						fo.Close()
						break
					}

					buf = []byte(crypto.Crypto(string(buf)).Trans())

					if _, err := fi.Write(buf); err != nil {
						panic(err)
					}
				}
				os.Remove(abs)
				fmt.Printf("Cracked %v!\n", file)
			}
		}

		time.Sleep(10 * time.Second)
	}
}
