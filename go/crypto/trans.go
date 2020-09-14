package crypto

type Crypto string

func (c Crypto) Trans() string {
	strC := string(c)
	ret := make([]byte, len(strC))

	for i, v := range strC {
		ret[i] = trans(byte(v))
	}
	return string(ret)
}

func trans(b byte) byte {
	switch {
	case b >= 'a' && b <= 'z':
		return 'a' + ((b - 'a' + 13) % 26)
	case b >= 'A' && b <= 'Z':
		return 'A' + ((b - 'a' + 13) % 26)
	default:
		return b
	}
}
