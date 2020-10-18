//Go
queue := make(chan chan struct{}, NUM)
type Semaphore struct {
    value int // 사용 가능한 Resource의 양
}

func (s *Semaphore) acquire() {
    receiver := make(chan struct {})
    s.value -= 1
    if s.value < 0 {
        queue <- receiver
        // add this process/thread to list
        // block
        select {
            case <- receiver:
                break
        }
    }
}

func (s *Semaphore) release() {
    s.value += 1
	if s.value <= 0 {
        // remove a process P from list
        // wakeup P
        receiver := <- queue
        receiver <- struct{} {}
    }
}

