package main

import (
	"fmt"
	"log"
	"regexp"
	"strings"

	"github.com/woodchuckchoi/assignment/server"
)

type KeyValueStorage struct {
	KV        map[string]int `json:"values"`
	Partition string         `json:"partition"`
}

func (k *KeyValueStorage) AssignPartition(p string) error {
	k.Partition = p
	return nil
}

func (k *KeyValueStorage) Preprocess() error {
	k.Partition = strings.ToLower(k.Partition)

	regexp, err := regexp.Compile(`[^a-zA-Z0-9*]`)
	if err != nil {
		log.Fatal(err)
		panic(err)
	}
	k.Partition = regexp.ReplaceAllString(k.Partition, " ")

	return nil
}

func (k *KeyValueStorage) Process() error {
	_ = k.Preprocess()
	left, right := 0, 0
	for right < len(k.Partition) {
		if k.Partition[right] == ' ' {
			if left < right {
				k.KV[strings.ToLower(k.Partition[left:right])]++

				left = right + 1
				for left < len(k.Partition) && k.Partition[left] == ' ' {
					left++
				}
			}
		}
		right++
	}

	if left < right {
		k.KV[k.Partition[left:right]]++
	}

	return nil
}

func (k *KeyValueStorage) GetValue(key string) int {
	return k.KV[key]
}

func InitKeyValueStorage(p string) *KeyValueStorage {
	k := KeyValueStorage{
		KV:        map[string]int{},
		Partition: p,
	}

	return &k
}

func main() {

	k := InitKeyValueStorage("This is the example sentence. This sentence may contain unexpected symbols, such as comma and period.\nHow would it turn out to be?")
	k.Process()
	fmt.Println(k.KV)

	server.InitServer()
}
