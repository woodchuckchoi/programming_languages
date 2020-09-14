import asyncio
import time

async def time_consuming(para):
    start = time.time()
    result = list()
    for i in range(1, para):
        if para % i == 0:
            result.append(i)
        if int(time.time()-start) % 5 == 0:
            await asyncio.sleep(0)
    return print(f'{para} is dividable by {result}.')

async def main():
    '''
    task = list()
    task.append(asyncio.create_task(time_consuming(3000)))
    task.append(asyncio.create_task(time_consuming(1500)))
    task.append(asyncio.create_task(time_consuming(700)))

    for i in task:
        await i
    '''
    await asyncio.gather(
        time_consuming(7000),
        time_consuming(5000),
        time_consuming(3000),
    )

asyncio.run(main())
