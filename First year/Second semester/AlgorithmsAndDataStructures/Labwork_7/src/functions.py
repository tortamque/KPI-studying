from classes import DoublyLinkedList

def fibonacci_search(input_array: list[int], num_to_find: int):
    array_size = len(input_array)

    # ініціалізуємо числа Фібоначчі
    fib1 = 0
    fib2 = 1
    fib3 = 1

    # якщо число Фібоначчі менше за розмірність масиву
    while fib3 < array_size:
        # йдемо далі по числам Фібоначчі
        fib1 = fib2
        fib2 = fib3
        fib3 = fib2 + fib1

    # Зміщення
    offset = -1

    while fib3 > 1:
        # індекс (найменше значення між offset + fib1 і array_size - 1)
        index = min(offset + fib1, array_size - 1)

        # якщо число в масиві за індексом index менше за шукане число
        if input_array[index] < num_to_find:
            offset = index
            # змінюємо числа Фібоначчі
            fib3 = fib2
            fib2 = fib1
            fib1 = fib3 - fib2
        # якщо число в масиві за індексом index більше за шукане число
        elif input_array[index] > num_to_find:
            fib3 = fib1
            fib2 = fib2 - fib1
            fib1 = fib3 - fib2
        # якщо число в масиві за індексом index дорівнює шуканому числу
        else:
            return index

    if fib2 and input_array[array_size - 1] == num_to_find:
        return array_size - 1,

    # якщо шукане число в масиві не знайшли, то повертаємо -1
    return -1,


def fibonacci_search_DoublyLinkedList(linked_list: DoublyLinkedList, num_to_find: int, list_size: int):
    # ініціалізуємо числа Фібоначчі
    fib1 = 0
    fib2 = 1
    fib3 = 1

    # якщо число Фібоначчі менше за розмірність масиву
    while fib3 < list_size:
        # йдемо далі по числам Фібоначчі
        fib1 = fib2
        fib2 = fib3
        fib3 = fib2 + fib1

    # Зміщення
    offset = -1

    while fib3 > 1:
        # індекс (найменше значення між offset + fib1 і array_size - 1)
        index = min(offset + fib1, list_size - 1)

        # якщо число в масиві за індексом index менше за шукане число
        if linked_list.get_node(index).data < num_to_find:
            offset = index
            # змінюємо числа Фібоначчі
            fib3 = fib2
            fib2 = fib1
            fib1 = fib3 - fib2
        # якщо число в масиві за індексом index більше за шукане число
        elif linked_list.get_node(index).data > num_to_find:
            fib3 = fib1
            fib2 = fib2 - fib1
            fib1 = fib3 - fib2
        # якщо число в масиві за індексом index дорівнює шуканому числу
        else:
            return index

    if fib2 and linked_list.get_node(list_size - 1).data == num_to_find:
        return list_size - 1

    # якщо шукане число в масиві не знайшли, то повертаємо -1
    return -1