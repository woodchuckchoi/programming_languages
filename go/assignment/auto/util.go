package auto

var (
	korHead = [...]rune{'ㄱ', 'ㄲ', 'ㄴ', 'ㄷ', 'ㄸ', 'ㄹ', 'ㅁ', 'ㅂ', 'ㅃ', 'ㅅ', 'ㅆ', 'ㅇ', 'ㅈ', 'ㅉ', 'ㅊ', 'ㅋ', 'ㅌ', 'ㅍ', 'ㅎ'}
	korMid  = [...]rune{'ㅏ', 'ㅐ', 'ㅑ', 'ㅒ', 'ㅓ', 'ㅔ', 'ㅕ', 'ㅖ', 'ㅗ', 'ㅠ', 'ㅘ', 'ㅛ', 'ㅙ', 'ㅚ', 'ㅜ', 'ㅝ', 'ㅞ', 'ㅟ', 'ㅡ', 'ㅢ', 'ㅣ'}
	korEnd  = [...]rune{' ', 'ㄱ', 'ㄲ', 'ㄳ', 'ㄴ', 'ㄵ', 'ㄶ', 'ㄷ', 'ㄹ', 'ㄺ', 'ㄻ', 'ㄼ', 'ㄽ', 'ㄾ', 'ㄿ', 'ㅀ', 'ㅁ', 'ㅂ', 'ㅄ', 'ㅅ', 'ㅆ', 'ㅇ', 'ㅈ', 'ㅊ', 'ㅋ', 'ㅌ', 'ㅍ', 'ㅎ'}
)

func KorRuneToCodePoints(r rune) []rune {
	kor := int(r - '가')

	head := korHead[kor/(len(korMid)*len(korEnd))]
	mid := korMid[kor%(len(korHead)*len(korEnd))/len(korEnd)]
	end := korEnd[kor%len(korEnd)]

	ret := []rune{head, mid}
	if end != ' ' {
		ret = append(ret, end)
	}

	return ret
}

func StringToCodePoints(s string) []rune {
	ret := []rune{}
	for _, val := range s {
		if val >= '가' && val <= '힣' { // 완성형 한글인 경우
			ret = append(ret, KorRuneToCodePoints(val)...)
		} else {
			ret = append(ret, val)
		}
	}
	return ret
}
