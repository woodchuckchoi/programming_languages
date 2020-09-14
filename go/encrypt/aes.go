package main

import (
	"fmt"
	"crypto/aes"
)

func main() {
	key := "hello, key 12345"
	s := "hello, world! 12"

	block, err := aes.NewCipher([]byte(key))
	if err != nil {
		fmt.Println(err)
		return
	}

	ciphertext := make([]byte, len(s))
	block.Encrypt(ciphertext, []byte(s))
	fmt.Printf("%x\n", ciphertext)

	plaintext := make([]byte, len(s))
	block.Decrypt(plaintext, ciphertext)
	fmt.Println(string(plaintext))
}