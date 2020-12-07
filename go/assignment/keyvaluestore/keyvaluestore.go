package keyvalustore

import (
	"log"
	"regexp"
	"strings"
)

type KeyValueStorage struct {
	KV        map[string]int `json:"values"`
	Partition string         `json:"partition"`
}

func (k *KeyValueStorage) AssignPartition(p string) {
	k.Partition = p
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

func InitKeyValueStorage() *KeyValueStorage {
	k := KeyValueStorage{
		KV:        map[string]int{},
		Partition: "",
	}

	return &k
}
