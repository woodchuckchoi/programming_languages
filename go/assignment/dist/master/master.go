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

func (m *Master) acknowledgeWorker(addr Address) {
	uid := uuid.New().String()

	newWorker := Worker{
		UID:  uid,
		Addr: addr,
	}
	m.Workers = append(m.Workers, newWorker)
}

func (m *Master) sortWorkers() {
	sort.Sort(m)
}

func getLeastBusyWorker(m *Master) *Worker {
	var (
		load      int     = 100
		leastBusy *Worker = nil
	)

	for _, worker := range m.Workers {
		if worker.Load < load {
			load = worker.Load
			leastBusy = &worker
		}
	}

	return leastBusy
}

func getLeastBusyWorkerWithKey(m *Master, key string, lastVisited *Worker) *Worker {
	workers := m.KeyWorkerMap[key]
	if len(workers) == 0 {
		return nil
	}

	leastBusy := getWorkerByUID(m, workers[0])

	for _, worker := range workers[1:] {
		if lastVisited != nil && worker == lastVisited.UID {
			continue
		}

		curWorker := getWorkerByUID(m, worker)

		if leastBusy == nil || leastBusy.Load > curWorker.Load {
			leastBusy = curWorker
		}
	}

	return leastBusy
}

func getWorkerByUID(m *Master, uid string) *Worker {
	start, end := 0, len(m.Workers)
	mid := (start + end) / 2
	stuck := mid
	ret := &(m.Workers[mid])

	for ret.UID != uid {
		if ret.UID > uid {
			end = mid
		} else {
			start = mid
		}
		mid = (start + end) / 2
		if mid == stuck {
			break
		}
		stuck = mid
		ret = &(m.Workers[mid])
	}

	if ret.UID != uid {
		return nil
	}

	return ret
}

// modules are pretty much done? Now distributed, cocurrnet service
