brown = 10
red = 2

# for i in range(brown, 0, -1):
#     if (brown+red) % i == 0:
#         if red % (i-2) == 0 and 2*int(red / (i - 2)) * (2*(i-4)) == red:
#             brown_long = i
#             break
#     brown_short = (brown - (2*(brown_long)))/2 + 2
#     answer = [brown_long, brown_short]
#
# print(answer)


flag = False
for i in range(int((brown-2)/2+1), 0, -1):
    if (brown+red) % i == 0:
        k = red % (i -2)
        j = int(red / (i -2))
        if k == 0 and (i-2)*j == red:
            flag = i
            break
short_side = int((brown - 2 * flag + 4) / 2)
answer = [flag, short_side]
print(answer)
