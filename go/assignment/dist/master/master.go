package master

type Address struct {
	IP   string
	PORT int
}

type Worker struct {
	UID  string
	Addr Address
}

type Master struct {
	Workers      []Worker
	KeyWorkerMap map[string]UID
}
