from random import randrange, random


def generate_coordinate(max: int) -> float:
    return randrange(0, max - 1) + random()


for size in range(1, 16):
    list = []
    for i in range(1, 6):
        for j in range(2**size):
            list.append([generate_coordinate(500), generate_coordinate(500)])
        list.sort(key=lambda a: a[0])
        with open(f'points/{i}/{size}.txt', 'w') as f:
            f.write(f'{2**size}\n')
            for item in list:
                f.write(f'{item[0]}\n{item[1]}\n')
