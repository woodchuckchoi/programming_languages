package main

import "fmt"

var (
	packageName = flag.String(
		"package_name",
		"main",
		"package name",
	)
	multisetTypename = flag.String(
		"multiset_typename",
		"MultiSet",
		"container type",
	)
	elementTypename = flag.String(
		"element_typename",
		"string",
		"element type",
	)
	output = flag.String(
		"output",
		"",
		"output filename",
	)
)

var tmpl = template.Must(template.New("multiset").Parse(`package {{.PackageName}}`))

type {{.MultisetTypename}} map[{{.ElementTypename}}]int

func New{{.MultisetTypename}}() {{.MultisetTypename}} {
	...
}
