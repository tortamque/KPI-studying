from functions import *

file_content = read_input_file("input.txt")
matrix = parse_matrix(file_content)

route, route_value = find_route(matrix)

fill_output_file("output.txt", route, route_value)
