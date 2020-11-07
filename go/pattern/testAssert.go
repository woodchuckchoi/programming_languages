package main

import (
	"fmt"
	"reflect"
	"testing"
)

// for string only
func assertEqualString(t *testing.T, expected, actual string) {
	if expected != actual {
		t.Errorf("%s != %s", expected, actual)
	}
}

// all datatype
func assertEqual(t *testing.T, expected, actual interface{}) {
	if !reflect.DeepEqual(expected, actual) {
		t.Errorf("%v != %v", expected, actual)
	}
}

// Table test
func TestSomething(t *testing.T) {
	examples := []struct {
		desc, expected, input string
	}{{
		desc:     "empty case",
		expected: "",
		input:    "",
	}, {
		desc:     "my test",
		expected: "something",
		input:    "something",
	},
	}
	for _, ex := range examples {
		actual := fmt.Sprintf("%v", ex.input)
		if ex.expected != actual {
			t.Errorf("%s: %s != %s", ex.desc, ex.expected, actual)
		}
	}
}
