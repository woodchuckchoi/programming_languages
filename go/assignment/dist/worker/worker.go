package worker

import (
	kv "github.com/woodchuckchoi/assignment/keyvaluestore"
)

type Worker struct {
	KV kv.KeyValueStorage
}
