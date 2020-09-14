package main

import (
	"encoding/json"
	"fmt"
)

func main() {
	data := make(map[string]interface{})

	data["name"] = "maria"
	data["age"] = 10

	doc, _ := json.Marshal(data)

	fmt.Println(string(doc))
}

// package main

// import (
// 	"fmt"
// 	"encoding/json"
// )

// func main() {
// 	doc := `
// 	{
// 		"name":"maria",
// 		"age":10
// 	}
// 	`

// 	var data map[string]interface{}

// 	json.Unmarshal([]byte(doc), &data)
// 	fmt.Println(data, data["name"], data["age"])
// }