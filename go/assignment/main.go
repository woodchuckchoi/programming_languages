package main

type KeyValueStorage struct {
	Keys      []string       `json:"keys"`
	Values    map[string]int `json:"values"`
	Partition string         `json:"partition"`
}

func (k *KeyValueStorage) AssignPartition(p string) error {
	k.Partition = p
	return nil
}

func (k *KeyValueStorage) Process() error {
	left, right := 0, 0
	for right < len(k.Partition) {
		if k.Partition[right] == ' ' {
			if left < right {
				k.Values[k.Partition[left:right]]++

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
