import asyncio

async def time_consuming(number, divisible):
    print(f'Start looking for numbers smaller than {number} dividable by {divisible}')
    result = list()
    for i in range(number):
        if i % divisible == 0:
            result.append(i)
        if i % 10000 == 0:
            await asyncio.sleep(0)

    print(f'Found {len(result)} numbers before {number} that are dividable by {divisible}')
    return result

async def multi():
    part1 = loop.create_task(time_consuming(5000000, 3241))
    part2 = loop.create_task(time_consuming(2000000, 3241))
    part3 = loop.create_task(time_consuming(54000, 6000))
    await asyncio.wait([part1, part2, part3])
    return part1, part2, part3


if __name__ == '__main__':
    try:
        loop = asyncio.get_event_loop()
        loop.run_until_complete(multi())
    except Exception as e:
        pass
    finally:
        loop.close()
