package graphics

import (
	"fmt"
	"os"
	"os/exec"
	"strings"

	"golang.org/x/crypto/ssh/terminal"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func getTerminalSize() (int, int) {
	width, height, _ := terminal.GetSize(0)
	return width, height
}

func clearScreen() {
	clear := exec.Command("clear")
	clear.Stdout = os.Stdout
	clear.Run()
}

func filler(width, height int) [][]byte {
	ret := [][]byte{}
	row := []byte(strings.Repeat(" ", width))
	for i := 0; i < height; i++ {
		ret = append(ret, row)
	}

	return ret
}

/*
   Z
   |
   |____Y
  /
 /
X
*/

func addAxes(filler [][]byte) [][]byte {
	width_centre, height_centre := len(filler[0])/2, len(filler)/2

	for i := 0; i < len(filler); i++ {
		// Z-axis
		if i < height_centre {
			filler[i][width_centre] = '|'

			// Y-axis
			if i == height_centre-1 {
				for j := width_centre + 1; j < len(filler[0]); j++ {
					filler[i][j] = '_'
				}
			}
		} else {
			// X-axis
			if cur := width_centre - (i - height_centre); cur >= 0 {
				filler[i][cur] = '/'
			}
		}
	}

	return filler
}

func printByteSlice(graphics [][]byte) {
	for i := 0; i < len(graphics); i++ {
		line := string(graphics[i])
		fmt.Println(line)
	}
}
