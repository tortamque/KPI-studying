import random


def fill_matrix(matrix: list[list[int]]):
    size = int(input("Enter size of your matrix: "))

    mode = input("Would you like to generate matrix randomly or enter it manually?\nR - randomly, M - manually:")

    while mode != "r" and mode != "R" and mode != "m" and mode != "M":
        mode = input("Error, enter either M or R\nR - randomly, M - manually:")

    if mode == 'm' or mode == 'M':
        print("Now enter wight matrix of your matrix\n(if there's no path in vertex enter \"-1\", on diagonal elemets enter \"0\"):")
        for i in range(size):
            row = []

            for j in range(size):
                element = int(input(f"Enter element ({i + 1},{j + 1}): "))
                if element == -1:
                    element = float("inf")
                row.append(element)

            matrix.append(row)

    elif mode == 'r' or mode == 'R':
        for i in range(size):
                row = []

                for j in range(size):
                    if i == j:
                        row.append(0)
                    else:
                        element = random.randint(1, 10)

                        row.append(element)

                matrix.append(row)


def generate_empty_matrix(size: int):
    matrix = []

    for i in range(size):
        row = []

        for j in range(size):
            row.append(0)

        matrix.append(row)

    return matrix

def generate_empty_path_matrix(size: int):
    matrix = []

    for i in range(size):
        row = []

        for j in range(size):
            row.append("")

        matrix.append(row)

    return matrix

