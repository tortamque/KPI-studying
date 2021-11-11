from math import sqrt


def third_root(num, precision):
    # Повертає корінь третьої степені з числа num

    result = num

    for i in range(precision):
        result = 1.0 / 3.0 * ((num / pow(result, 2)) + 2 * result)

    return result


# створюємо змінну "а" і присвоюємо їй значення
a = int(input("Enter value a: "))
# створюємо змінну "b" і присвоюємо їй значення
b = int(input("Enter value b: "))
# створюємо змінну "n"(точність) і присвоюємо їй значення
n = int(input("Enter value n (precision): "))

''' за умовою задачі потрібно знайти корінь дев'ятої степені з а
    для цього візьмемо корінь третьої степені з а
    потім вьзмемо корінь третьої степені з минулого кореня
    таким чином отримаємо корінь дев'ятої степені   '''

# рахуємо корінь третьої степені з а
third_root_a = third_root(a, n)
# рахуємо корінь третьої степені з минулого кореня
ninth_root_a = third_root(third_root_a, n)

''' для обчислення кореня шостої степені з b
    візьмемо корінь третьої степені з b
    потім вьзмемо квадратний корінь з минулого кореня
    таким чином отримаємо корінь шостої степені   '''

# рахуємо корінь третьої степені з b
third_root_b = third_root(b, n)
# рахуємо квадратний корінь з минулого кореня
sixth_root_b = sqrt(third_root_b)

# рахуємо корінь третьої степені з суми a і b (a+b)
third_root_sum = third_root(a + b, n)

# рахуємо Y
Y = ninth_root_a + sixth_root_b + third_root_sum

# виводимо обчислення в консоль
print(f"Ninth root of a = {round(ninth_root_a, 3)}\nSixth root of b = {round(sixth_root_b, 3)}\nThird root of sum = {round(third_root_sum, 3)}\nY = {round(Y, 3)}")
