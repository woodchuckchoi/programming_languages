package server

import (
	"log"
	"net"
)

type Server struct {
	Conn net.PacketConn
}

func InitServer(port string) *Server {
	if port == "" {
		port = ":7777"
	}
	conn, err := net.ListenPacket("udp", port)
	if err != nil {
		log.Fatal(err)
		panic(err)
	}

	server := Server{
		Conn: conn,
	}

	return &server
}

func (s *Server) Close() {
	_ = s.Conn.Close()
}
