package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
)

type Author struct {
	Name  string `json:"name"` // 값을 저장할 구조체 슬라이스 생성
	Email string `json:"email"`
}

type Comment struct {
	Id      uint64 `json:"id"`
	Author  Author `json:"author"`
	Content string `json:"content"`
}

type Article struct {
	Id         uint64    `json:"id"`
	Title      string    `json:"title"`
	Author     Author    `json:"author"`
	Content    string    `json:"content"`
	Recommends []string  `json:"recommends"`
	Comments   []Comment `json:"comments"`
}

func main() {
	b, err := ioutil.ReadFile("./articles.json")
	if err != nil {
		fmt.Println(err)
		return
	}

	var data []Article

	json.Unmarshal(b, &data)
	
	fmt.Println(data)
}