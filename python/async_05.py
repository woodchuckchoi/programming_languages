import asyncio
import time

async def factorial(para):
    start = time.time()
    num = 1
    for i in range(2, para):
        num *= i
        if i % 10 == 0:
            await asyncio.sleep(0)
            print(f'{para} is now passing its turn to the next one after {i} iterations!')
    return print(f'{para}! is {num}')

async def main():
    '''
    task = list()

    task.append(asyncio.create_task(factorial(100)))
    task.append(asyncio.create_task(factorial(80)))
    task.append(asyncio.create_task(factorial(30)))

    for i in task:
        await i
    '''

    await asyncio.gather(
        factorial(100),
        factorial(70),
        factorial(40)
    )

asyncio.run(main())
