from classes import *


def read_input_file(file_name: str):
    file = open(file_name)

    text = file.read()

    file.close()
    return text


def parse_backpack(text: str):
    first_line = text.split('\n')[0]
    backpack_capacity = int(first_line.split(' ')[0])

    backpack = Backpack(backpack_capacity)

    return backpack


def parse_items(text: str):
    first_line = text.split('\n')[0]
    amount = int(first_line.split(' ')[1])
    items_content = text.split('\n')[1:]

    items = []

    for i in range(amount):
        price = int(items_content[i].split(' ')[0])
        weight = int(items_content[i].split(' ')[1])

        item = Item(price, weight)

        items.append(item)

    return items


def generate_items_weights(items: list[Item]):
    weights = [item.get_weight() for item in items]

    return weights


def generate_items_prices(items: list[Item]):
    prices = [item.get_price() for item in items]

    return prices


def generate_empty_table(backpack_capacity: int, items_amount: int):
    table = []

    for i in range(items_amount + 1):
        row = []

        for j in range(backpack_capacity + 1):
            row.append(0)

        table.append(row)

    return table


def find_max_items_price(backpack: Backpack, items: list[Item]):
    backpack_capacity = backpack.get_capacity()
    items_amount = len(items)

    # таблиця із значеннями розв'язків
    # рядки - ціна об'єктів
    # стовпці - межі ваги об'єктів
    table = generate_empty_table(backpack_capacity, items_amount)

    # ітеруємось по стовпцям
    for i in range(1, items_amount + 1):
        # ітеруємось по елементам
        for j in range(1, backpack_capacity + 1):
            # перевіряємо що б вага об’єкта i була меншою за загальну вагу допустиму для комірки j
            item_weight = items[i - 1].get_weight()

            if item_weight <= j:
                # перший елемент (обчислюється за формулою)
                value1 = items[i - 1].get_price() + table[i - 1][j - items[i - 1].get_weight()]
                # загальний розмір предметів (обчислюється за формулою)
                value2 = table[i - 1][j]

                # обираємо максимальний з двох варіантів
                table[i][j] = max(value1, value2)
            # якщо вага об’єкта i перевищує допустиму вагу j.
            else:
                table[i][j] = table[i - 1][j]

    # повертаємо останню клітинку таблиці
    # (вона має найбільшу сумарну вартість предметів, які не перевищують розмірність рюкзака)
    return table[items_amount][backpack_capacity]


def write_output_file(file_name: str, max_items_price: int):
    text = str(max_items_price)

    file = open(file_name, 'wt')
    file.write(text)

    file.close()
