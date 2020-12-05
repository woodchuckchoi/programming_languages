package main

import (
	"fmt"
	"log"
	"regexp"
	"strings"
)

type KeyValueStorage struct {
	Keys      []string       `json:"keys"`
	Values    map[string]int `json:"values"`
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
				k.Values[strings.ToLower(k.Partition[left:right])]++

				left = right + 1
				for left < len(k.Partition) && k.Partition[left] == ' ' {
					left++
				}
			}
		}
		right++
	}

	if left < right {
		k.Values[k.Partition[left:right]]++
	}

	return nil
}

func (k *KeyValueStorage) GetValue(key string) int {
	return k.Values[key]
}

func InitKeyValueStorage(p string) *KeyValueStorage {
	k := KeyValueStorage{
		Keys:      []string{},
		Values:    map[string]int{},
		Partition: p,
	}

	return &k
}

func main() {
	k := InitKeyValueStorage("This is the example sentence. This sentence may contain unexpected symbols, such as comma and period.\nHow would it turn out to be?")

	k.Process()

	fmt.Println(k.Values)
}
