from functions import fill_matrix, generate_empty_matrix, generate_empty_path_matrix


class Matrix:
    __data = []
    __shortest_ways_matrix = []
    __path_matrix = []

    def __init__(self):
        # заповнюємо матрицю за допомогою функції
        fill_matrix(self.__data)

    def show_matrix(self):
        print("Matrix:")
        for i in range(len(self.__data)):
            for j in range(len(self.__data)):
                print(f"{self.__data[i][j]} ", end='')
            print("\n", end='')
        print("\n", end='')

    def show_shortest_path_weight_matrix(self):
        print("Shortest path weight matrix:")
        for i in range(len(self.__shortest_ways_matrix)):
            for j in range(len(self.__shortest_ways_matrix)):
                print(f"{self.__shortest_ways_matrix[i][j]} ", end='')
            print("\n", end='')
        print("\n", end='')

    def show_shortest_path_matrix(self):
        print("Shortest path weight matrix:")
        for i in range(len(self.__path_matrix)):
            for j in range(len(self.__path_matrix)):
                if self.__path_matrix[i][j] == "":
                    print('%30s' % ('-'), end='')
                else:
                    print('%30s' % (self.__path_matrix[i][j]), end='')
            print("\n", end='')
        print("\n", end='')


    def search_all_shortest_ways(self):
        # ліст з матрицями розміру 1,2,3,...
        # потрібен для реалізації алгоритму Данцига
        matrix_list = []
        # порожня матриця
        path_matrix = generate_empty_path_matrix(len(self.__data))
        # розмір матриці
        main_matrix_size = len(self.__data)

        # створюємо порожні матриці (готуємо масиви для реалізації алгоритму Данцига)
        for i in range(1, main_matrix_size + 1):
            empty_matrix = generate_empty_matrix(i)
            matrix_list.append(empty_matrix)

        # алгоритм Данцига
        # лічильник для масиву matrix_list
        for matrices in range(1, main_matrix_size):
            # розмір кожної матриці
            m = len(matrix_list[matrices]) - 1

            # спочатку ітеруємо по крайнім елементам матриць
            for i in range(len(matrix_list[matrices])):
                for j in range(len(matrix_list[matrices])):
                    # якщо i == j, то залишаєм елемент нулем
                    if i == j:
                        matrix_list[matrices][i][j] = 0
                    # m == i, то обчислюємо елемент за відповідною формулою Данцига
                    elif m == i:
                        # значення
                        values = []
                        # найменше значення (для початку дорівнює нескінченності)
                        lowest_value = float("inf")
                        # індекс найменшого значення (для початку дорівнює -1)
                        lowest_value_index = -1

                        # ітеруємось по розміру матриці (потрібно для формули)
                        for k in range(m):
                            # рахуємо значення за відповідною формулою
                            value = self.__data[i][k] + matrix_list[matrices - 1][k][j]
                            # додаємо обчислене значення в масив
                            values.append(value)

                            # якщо значення менше за вже найменше значення
                            if value < lowest_value:
                                lowest_value = value
                                lowest_value_index = k

                        # знаходимо мінімальне значення
                        min_value = min(values)
                        # замінюємо елемент матриці найменшим значенням
                        matrix_list[matrices][i][j] = min_value

                        # заповнюємо матрицю шляху
                        if min_value < self.__data[i][j]:
                            path_matrix[i][j] += f"({i + 1}->{lowest_value_index + 1})->({lowest_value_index + 1}->{j + 1})"
                        else:
                            path_matrix[i][j] += f"({i + 1}->{j + 1})"
                    # m == j, то обчислюємо елемент за відповідною формулою Данцига
                    elif m == j:
                        # значення
                        values = []
                        # найменше значення (для початку дорівнює нескінченності)
                        lowest_value = float("inf")
                        # індекс найменшого значення (для початку дорівнює -1)
                        lowest_value_index = -1

                        # ітеруємось по розміру матриці (потрібно для формули)
                        for k in range(m):
                            # рахуємо значення за відповідною формулою
                            value = matrix_list[matrices - 1][i][k] + self.__data[k][j]
                            # додаємо обчислене значення в масив
                            values.append(value)

                            # якщо значення менше за вже найменше значення
                            if value < lowest_value:
                                lowest_value = value
                                lowest_value_index = k

                        # знаходимо мінімальне значення
                        min_value = min(values)
                        # замінюємо елемент матриці найменшим значенням
                        matrix_list[matrices][i][j] = min_value

                        # заповнюємо матрицю шляху
                        if min_value < self.__data[i][j]:
                            path_matrix[i][j] += f"({i + 1}->{lowest_value_index + 1})->({lowest_value_index + 1}->{j+1})"
                        else:
                            path_matrix[i][j] += f"({i + 1}->{j+1})"

            # теперь ітеруємо ще раз
            for i in range(len(matrix_list[matrices])):
                for j in range(len(matrix_list[matrices])):
                    # але зараз обчислюємо не крайні елементи
                    if i != j and m != i and m != j:
                        # значення 1
                        value1 = matrix_list[matrices - 1][i][j]
                        # значення 2
                        value2 = matrix_list[matrices][i][m] + matrix_list[matrices][m][j]

                        # знаходимо мінімальне значення
                        min_value = min(value1, value2)

                        matrix_list[matrices][i][j] = min_value

                        # заповнюємо матрицю шляху
                        if value2 < value1:
                            path_matrix[i][j] = f"({i + 1}->{m + 1})->({m + 1}->{j + 1})"

        self.__shortest_ways_matrix = matrix_list[len(matrix_list) - 1]
        self.__path_matrix = path_matrix

