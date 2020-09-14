from multiprocessing import Process

def time_consuming(number, divisible):
    print(f'Start looking for numbers smaller than {number} dividable by {divisible}')
    result = list()
    for i in range(number):
        if i % divisible == 0:
            result.append(i)
        # if i % 10000 == 0:
            #await asyncio.sleep(0.0001)

    print(f'Found {len(result)} numbers before {number} that are dividable by {divisible}')
    return result

p1 = Process(target=time_consuming, args=(500000, 230))
p2 = Process(target=time_consuming, args=(300000, 230))
p3 = Process(target=time_consuming, args=(10000, 230))

for i in (p1, p2, p3):
    i.start()
