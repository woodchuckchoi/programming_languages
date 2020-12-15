package master

import (
	"github.com/google/uuid"
)

type Address struct {
	IP   string
	PORT int
}

type Worker struct {
	UID  string
	Addr Address
	Load int
}

type Master struct {
	Workers      []Worker
	KeyWorkerMap map[string][]string
}

func (m *Master) AcknowledgeWorker(addr Address) {
	uid := uuid.New().String()

	newWorker := Worker{
		UID:  uid,
		Addr: addr,
	}
	m.Workers = append(m.Workers, newWorker)
}

func GetLeastBusyWorkerWithKey(m *Master, key string, lastVisited Worker) *Worker {
	workers := m.KeyWorkerMap[key]
	var leastBusy *Worker

	for _, worker := range workers {
		if worker == lastVisited.UID {
			continue
		}

		curWorker := GetWorkerByUID(m, worker)

		if leastBusy == nil || leastBusy.Load > curWorker.Load {
			leastBusy = curWorker
		}
	}

	return leastBusy
}

func GetWorkerByUID(m *Master, uid string) *Worker {
	// need to implement B-Tree and binary search on the master's workers
	panic("Not Implemented")
}
