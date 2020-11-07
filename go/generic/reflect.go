package main

import (
	"fmt"
	"reflect"
)

func NewMap(key, value interface{}) interface{} {
	keyType := reflect.TypeOf(key)
	valueType := reflect.TypeOf(value)
	/* beneath won't work since keyType and valueType have not been set as in
	type keyType reflect.Typeof(key) which cannot be done
	m := map[keyType]valueType{}
	return m
	*/
	mapType := reflect.MapOf(keyType, valueType)
	mapValue := reflect.MakeMap(mapType)
	return mapValue.Interface()
}

func main() {
	t := NewMap("something", 123)
	fmt.Printf("%T %v", t, t)
}
