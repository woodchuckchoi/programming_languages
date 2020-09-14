tmp = ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
ari = ('+', '-', '*', '/')

'''
for i, val in enumerate(tmp):
    if val in ari:
        result = eval(tmp[i-2] + val + tmp[i-1])
        if val == '/': result = int(result)
        result = str(result)
        for j in range(3):
            tmp.pop(i - j)
        tmp.insert(i-2, result)

if len(tmp) > 1:
    tmp = eval(tmp[0] + tmp[2] + tmp[1])

print(tmp)
'''
output = list()
for i in tmp:
    if i in ari:
        result = eval(output[-2] + i + output[-1])
        if len(output) > 2:
            output = output[:-2]
        if i == '/': result = int(result)
        result = str(result)
        output.append(result)
    else:
        output.append(i)

print(output[-1])
