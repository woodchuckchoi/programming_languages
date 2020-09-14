package main

import (
	"io/ioutil"
	"fmt"
	
	"github.com/woodchuckchoi/crypto"
)

func main() {
	files, _ := ioutil.ReadDir("/Users/woohyuckchoi/")
	fmt.Println(files[0].Name())
	temp := "string"
	crpt := crypto.Crypto(temp)
	fmt.Println(crpt)
	fmt.Println(crpt.Trans())
}
