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
	for i := 0; i < height; i++ {
		ret = append(ret, []byte(strings.Repeat(" ", width)))
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
	widthCentre, heightCentre := len(filler[0])/2, len(filler)/2

	// Y-axis
	for j := widthCentre + 1; j < len(filler[0]); j++ {
		filler[heightCentre][j] = '_'
	}

	for i := 0; i < len(filler); i++ {
		// Z-axis
		if i <= heightCentre {
			filler[i][widthCentre] = '|'
		} else {
			// X-axis
			if cur := widthCentre - (i - heightCentre); cur >= 0 {
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
