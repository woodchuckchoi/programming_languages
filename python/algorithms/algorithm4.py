s = 'aslkdfjqoiwefhjlkaxncvl;kncvl;aksnds;flijqoiwehrfksdjlnf,v;xlcjknvg;jkalsdjngf;aidufgnqew'
start = 0
longest = 0
used = dict()

for i, char in enumerate(s):
    if char in used and start <= used[char]:
        start = used[char] + 1
    else:
        longest = max(longest, i - start + 1)

    used[char] = i

return longest
'''
* for 문을 쓰지만 start는 for 문에서의 인덱스와 다름

해당 인덱스의 글자가 이미 used 딕셔너리에 있꼬, 현재 start(실질적 인덱스)가 해당 인덱스의 '현재' 중복되는 값보다 작거나 같을 때

스타트를 겹친 글자의 '현재' 인덱스 보다 한 글자 앞으로 옮김 (for 문은 그대로 다음 인덱스를 가리키게됨)

예를 들어 'dick in a box' 라는 string이 있을 때, [5]의 i를 for 문이 가리키는 시점에서 used 딕셔너리는 {'d':0, 'i':1, 'c':2, 'k':3, ' ':4,} 를 가지고 있고,

'i'는 현재 딕셔너리의 키 값이고, start는 여전히 0, longest는 5인 상태에서, start는 겹쳐진 단어의 다음 인덱스인 1이 되고, 딕셔너리는 {'d':0, 'i':5, 'c':2, 'k':3, ' ':4,}

가 됨. 이 원리 그대로 딕셔너리는 항상 스타트 인덱스가 가리키는 글자부터 지금의 for문의 인덱스까지를 가리키게 되고, 딕셔너리는 지금까지 쓰인 모든 글자들의 가장 최신 인덱스를 기록하게 되지만

if 의 조건이 'start가 used[char]보다 작을 때'이기 때문에, 스타트보다 작은 인덱스는 무시하게 된다. 롱기스트는 단어가 겹치지 않는 상황에서 계속해서 현재의 단어 길이와 역대 최장을

비교하며 업데이트 한다.
'''
