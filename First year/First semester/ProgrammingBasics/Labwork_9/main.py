def sort_array(array):
    """
    Сортує слова в масиві за зростанням їх довжини методом сортування вставками
    :param array: Масив
    """

    # довжина масиву
    array_size = len(array)

    # цикл проходу
    for i in range(1, array_size):
        j = i - 1
        tmp = array[i]

        # пошук елемента в масиві
        while j >= 0 and len(array[j]) > len(tmp):
            # рухаємо елемент вправо, поки він не досягне своєї позиції
            array[j+1] = array[j]
            j -= 1

        # місце елемента знайдено, вствляємо його на позицію j+1
        array[j+1] = tmp


def print_array(array):
    '''
    Виводить елементи масиву в консоль
    :param array: Масив
    '''

    print("Sorted string:")
    for i in range(len(array)):
        print(f"{i + 1}) {array[i]}")


user_input = input("Enter a string:")

# Ділимо рядок на окремі слова
words = user_input.split(" ")

# Сортуємо масив
sort_array(words)
# Виводимо результат в консоль
print_array(words)
