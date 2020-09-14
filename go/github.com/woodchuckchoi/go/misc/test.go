package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
)

func main() {
	resp, err := http.Get("https://www.naver.com")
	if err != nil {
		fmt.Println(err)
		return
	}
	fmt.Println(resp)
	defer resp.Body.Close()
	ioutil.ReadAll(resp.Body)
}
