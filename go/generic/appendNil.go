package main

import (
	"errors"
	"fmt"
	"reflect"
)

func AppendNilError(f interface{}, err error) (interface{}, error) {
	t := reflect.TypeOf(f)
	if t.Kind() != reflect.Func {
		return nil, errors.New("AppendNilError: f is not a function")
	}
	in, out := []reflect.Type{}, []reflect.Type{}
	for i := 0; i < t.NumIn(); i++ {
		in = append(in, t.In(i))
	}
	for i := 0; i < t.NumOut(); i++ {
		out = append(out, t.Out(i))
	}
	out = append(out, reflect.TypeOf((*error)(nil)).Elem())
	funcType := reflect.FuncOf(in, out, t.IsVariadic())
	v := reflect.ValueOf(f)
	funcValue := reflect.MakeFunc(funcType, func(args []reflect.Value) []reflect.Value {
		results := v.Call(args)
		results = append(results, reflect.ValueOf(&err).Elem())
		return results
	})
	return funcValue.Interface(), nil
}

func main() {
	f := func() {
		fmt.Println("called")
	}
	f2, err := AppendNilError(f, errors.New("test error"))
	fmt.Println("AppendNilError.err:", err)
	fmt.Println(f2.(func() error)())
}
