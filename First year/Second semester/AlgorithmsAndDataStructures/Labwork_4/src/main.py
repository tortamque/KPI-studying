from classes import *

# створюємо матрицю
matrix = Matrix()
# виводимо її в консоль
matrix.show_matrix()

# шукаємо всі найкоротші шляхи
matrix.search_all_shortest_ways()

# виводимо в консоль матрицю усіх найкоротших шляхів
matrix.show_shortest_path_weight_matrix()
# виводимо в консоль усіх найкоротші шляхи
matrix.show_shortest_path_matrix()