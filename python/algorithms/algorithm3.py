s = '"heloobdflgdxyrdcvobnsckbxdoexybgcnvsoaychbbfveksulhpnrqlwfptdsahfxbwxbye"'

longest = 0

for i in range(len(s)):
    for j in range(len(s), i, -1):
        check = set(s[i:j])
        check = list(map(lambda x: 1 if s[i:j].count(x) != 1 else 0, check))
        if 1 in check:
            continue
        else:
            if j - i > longest: longest = j - i
            break

print(longest)
