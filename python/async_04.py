import asyncio
import time

async def time_consuming(num):
    result = list()
    start_time = time.time()
    for i in range(1, num):
        if (num%i) == 0:
            result.append(i)
        if int(time.time() - start_time) % 2 == 0:
            await asyncio.sleep(0)
    print(f'{num}\'s dividable by {result}')

async def main():
    '''
    task =list()
    task.append(asyncio.create_task(time_consuming(52000000)))
    task.append(asyncio.create_task(time_consuming(36000000)))
    task.append(asyncio.create_task(time_consuming(5600)))

    for i in task:
        await i
    '''

    await asyncio.gather(time_consuming(530000), time_consuming(67000), time_consuming(25))

asyncio.run(main())
