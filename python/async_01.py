import asyncio
import random

async def coroutine(id):
    process_time = random.randint(1,5)
    await asyncio.sleep(process_time)
    print(f'Coroutine {id} has successfully copleted the task after {process_time} seconds!')

async def main():
    tasks = []
    for i in range(10):
        tasks.append(asyncio.ensure_future(coroutine(i)))

    await asyncio.gather(*tasks)

loop = asyncio.get_event_loop()

loop.run_until_complete(main())
loop.close()
