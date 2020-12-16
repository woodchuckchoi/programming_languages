package master

import (
	"sort"

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

func (m *Master) Len() int {
	return len(m.Workers)
}

func (m *Master) Swap(i, j int) {
	m.Workers[i], m.Workers[j] = m.Workers[j], m.Workers[i]
}

func (m *Master) Less(i, j int) bool {
	return m.Workers[i].UID < m.Workers[j].UID
}

func (m *Master) AcknowledgeWorker(addr Address) {
	uid := uuid.New().String()

	newWorker := Worker{
		UID:  uid,
		Addr: addr,
	}
	m.Workers = append(m.Workers, newWorker)
}

func (m *Master) SortWorkers() {
	sort.Sort(m)
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

	panic("Not Implemented")
}
