package main

import (
	"fmt"
	"math/rand"
	"os"
	"time"

	"github.com/woodchuckchoi/crypto"
)

var (
	// PRE defines the prefix of the content
	PRE = [...]string{"singing", "whistling", "awkward", "decomposing", "crawling", "melancholic", "marvelous", "graceful", "mighty", "gagging", "agile"}
	// NOUN defines the noun part of the content
	NOUN = [...]string{"beaver", "mocking bird", "mink", "dolphin", "pigeon", "iguana", "jaguar", "fox", "possum", "gorilla", "goose", "hog", "wasp", "cod"}
)

func genText() string {
	rand.Seed(int64(time.Now().Minute() * time.Now().Second()))

	ret := ""

	ret += PRE[rand.Intn(len(PRE))] + " "
	ret += NOUN[rand.Intn(len(NOUN))]

	return ret
}

func main() {
	var DIR string

	if dir := os.Getenv("CRYPTO"); dir != "" {
		DIR = dir
	} else {
		DIR = "/crypto/"
	}

	for {
		now := time.Now()
		suffix := fmt.Sprintf("%v:%v:%v", now.Day(), now.Hour(), now.Minute())

		f, err := os.Create(DIR + suffix)
		if err != nil {
			panic(err)
		}
		defer f.Close()

		content := crypto.Crypto(genText())

		_, err = f.Write([]byte(content.Trans()))
		if err != nil {
			panic(err)
		}

		time.Sleep(10 * time.Second)
	}

}
