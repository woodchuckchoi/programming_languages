def prime_verification(target):

    target = int(target)
    flag = True
    answer = [2,3,5]

    for entry in answer:
        limit = target/entry
        if entry == answer[-1] and limit > entry:
            answer.append(entry+1)
        if limit.is_integer():
            flag = False
            break

    return flag

tmp = int(input('Give me the upper limit :'))
results = [2,3,5]
for i in range(6, tmp+1):
    if prime_verification(i):
        results.append(i)

print(results)
