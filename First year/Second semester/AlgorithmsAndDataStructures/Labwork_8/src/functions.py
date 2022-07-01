from classes import *
from math import sqrt


def read_input_file(file_name: str):
    file = open(file_name)

    text = file.read()

    file.close()

    return text


def calculate_distance(x1: int, y1: int, x2: int, y2: int):
    # рахуємо відстань за формулою
    distance = sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)

    return distance


def generate_empty_double_list(size: int):
    double_list = []

    for i in range(size):
        row = []
        for j in range(size):
            row.append(0)
        double_list.append(row)

    return double_list


def init_double_list(matrix_size: int, distances: list[str], double_list: list[list[int]]):
    for i in range(matrix_size):
        for j in range(matrix_size):
            x1 = int(distances[i][0])
            y1 = int(distances[i][1])

            x2 = int(distances[j][0])
            y2 = int(distances[j][1])

            distance = calculate_distance(x1, y1, x2, y2)

            double_list[i][j] = distance
            double_list[j][i] = distance


def split_coordinates(matrix_size: int, coordinates: list[str]):

    for i in range(matrix_size):
        coordinates[i] = coordinates[i].split(' ')


def parse_matrix(text: str):
    # "розрізаємо" текст по символу нового рядка
    lines = text.split("\n")
    # розмір матриці
    matrix_size = int(lines[0])

    # генеруємо порожній двовимірний масив
    double_list = generate_empty_double_list(matrix_size)

    # отримуємо з тексту координати точок
    coordinates = lines[1:]

    # "розрізаємо" координати по пробілу
    split_coordinates(matrix_size, coordinates)

    # ініціалізуємо двовимірний масив
    # а саме, переводимо координати в матрицю, яка збурігає вадстані між вершинами
    init_double_list(matrix_size, coordinates, double_list)

    # генеруємо об'єкт матриці на основі двовимірного масиву
    matrix = Matrix(double_list)

    return matrix


def find_min(arr: list[int], except_indexes: list[int]):
    # мінімальний елемент
    min_value = -1
    # індекс мінімального елементу
    index = -1

    # ініціалізуємо мінімальний елемент і його індекс
    # для цього ітеруємось по основному масиву
    for i in range(len(arr)):
        # ітеруємось по масиву виключень
        for j in range(len(except_indexes)):
            # якщо i != елементу в масиві виключені і != 0
            if i != except_indexes[j] and arr[i] != 0:
                # ініціалізуємо мінімальний елемент
                min_value = arr[i]
                # індекс мінімального елементу
                index = i

                # виходимо з циклу
                break

    # ітеруємось по основному масиву
    for i in range(1, len(arr)):
        # ітеруємось по масиву виключень
        for j in range(len(except_indexes)):
            # якщо i дорівнює елементу в масиві виключень, то пропускаємо цей хід циклу
            if i == except_indexes[j]:
                continue

        # якщо елемент масиву != 0 і елемент масиву менший за min value
        if arr[i] != 0 and arr[i] < min_value:
            # змінюємо мінімальний елемент
            min_value = arr[i]
            # змінюємо індекс мінімального елементу
            index = i

    return min_value, index


def find_route(matrix: Matrix):
    # маршрут обходу (починається завжди з 0 вершини)
    route = [0]
    # довжина маршруту
    route_value = 0

    # лічильник
    i = 0
    # масив з індексами виключень
    # зберігає вершини, в яких ми вже були
    except_indexes = [0]

    while len(route) < len(matrix):
        # рядок матриці
        row = matrix[i]
        # знаходимо мінімальний елемент і наступну вершину для обходу
        min_value, next_point = find_min(row, except_indexes)
        # змінюємо довжину маршруту
        route_value += min_value
        # додаємо вершину в маршрут
        route.append(next_point)
        # додаємо вершину в масив виключень
        except_indexes.append(next_point)

        # змінюємо лічильник
        i = next_point
    # додємо до маршруту першу вершину (так як ми вонинні в ній закінчити свій шлях)
    route.append(0)

    # передостанній елемент масиву зі шляхом
    penultimate_element = route[len(route) - 2]
    # останній елемент масиву зі шляхом
    last_element = route[len(route) - 1]

    # додаємо до довжини шляху довжину від останньої вершини до першої
    route_value += matrix[penultimate_element][last_element]

    return route, route_value


def fill_output_file(file_name: str, route: list[int], route_value: int):
    text = f"{int(route_value)}\n"

    for i in range(len(route)):
        text += f"{route[i]} "

    file = open(file_name, 'wt')
    file.write(text)

    file.close()
