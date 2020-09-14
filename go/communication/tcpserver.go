package main

import (
	"fmt"
	"net"
)

const (
	BANDWIDTH int = 4096
)

func requestHandler(c net.Conn) {
	data := make([]byte, BANDWIDTH)

	for {
		n, err := c.Read(data)
		if err != nil {
			fmt.Println(err)
			return
		}

		fmt.Println(string(data[:n]))

		_, err = c.Write(data[:n])
		if err != nil {
			fmt.Println(err)
			return
		}
	}
}

func main() {
	ln, err := net.Listen("tcp", ":8000")
	if err != nil {
		fmt.Println(err)
		return
	}
	defer ln.Close()

	for {
		conn, err := ln.Accept()
		if err != nil {
			fmt.Println(err)
			return
		}
		defer conn.Close()

		go requestHandler(conn)
	}
}