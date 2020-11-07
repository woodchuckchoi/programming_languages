package test

import (
	"errors"
	"fmt"
	"reflect"
)

func FieldNames(s interface{}) ([]string, error) {
	t := reflect.TypeOf(s)
	if t.Kind() != reflect.Struct {
		return nil, errors.New("FiledNames: s is not a struct")
	}
	names := []string{}
	n := t.NumField()
	for i := 0; i < n; i++ {
		names = append(names, t.Field(i).Name)
	}
	return names, nil
}

func main() {
	s := struct {
		ID   int
		Name string
		Age  int
	}{}
	fmt.Println(FieldNames(s))
	// Output: [ID Name Age] <nil>
}
