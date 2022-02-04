from random import randrange, random


def generate_coordinate(max: int) -> float:
    return randrange(0, max - 1) + random()


def generate_coordinates(size: int) -> list:
    list = []
    for i in range(size):
        list.append([generate_coordinate(500), generate_coordinate(500)])
    list.sort(key=lambda a: a[0])
    return list


for size in range(1, 21):
    with open(f'points/{size}.txt', 'w') as f:
        f.write(f'{2**size}\n')
        for i in range(1, 6):
            list = generate_coordinates(2**size)
            for item in list:
                f.write(f'{item[0]}\n{item[1]}\n')
