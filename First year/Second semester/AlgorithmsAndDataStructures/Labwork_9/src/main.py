from functions import *

file_content = read_input_file("input.txt")

backpack = parse_backpack(file_content)
items = parse_items(file_content)

max_items_price = find_max_items_price(backpack, items)

write_output_file("output.txt", max_items_price)