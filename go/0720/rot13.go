package main

import (
	"io"
	"os"
	"strings"
	"fmt"
)

func decipher(b byte) byte {
	if b >= 'A' && b <= 'Z' {
		return 'A' + ((b - 'A' + 13) % 26)
	} else if b >= 'a' && b <= 'z' {
		return 'a' + ((b - 'a' + 13) % 26)
	} else { return b }
}

type rot13Reader struct {
	r io.Reader
}

func (r rot13Reader) Error() string {
	b := []byte{}
	_, _ = r.r.Read(b)
	return fmt.Sprintf("%v is not a valid rot13Reader format", string(b))
}

func (r rot13Reader) Read(b []byte) (int, error) {
	ret := make([]byte, 1024)
	num, ok := r.r.Read(ret)
	if ok != nil {
		return num, r
	}

	for i, val := range ret {
		b[i] = decipher(val)
	}
	return num, ok
}

func main() {
	s := strings.NewReader("Lbh penpxrq gur pbqr!")
	r := rot13Reader{s}
	io.Copy(os.Stdout, &r)
}

