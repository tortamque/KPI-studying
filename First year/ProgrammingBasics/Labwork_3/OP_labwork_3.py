n = int(input("Enter n: "))  # введення n
x = float(input("Enter x (0 < x < 1): "))  # введення x

counter = 1  # створюємо лічильник
result = 1.0  # створюєму змінну для результату (1, тому що так задано в умові)

while counter <= n:  # цикл буде працювати до поки лічильник меньше або дорівнює n
    # добавляємо значення до результату
    result += pow(-1, counter) * ((pow(x, 2 * counter) + 1) / (pow(2, counter) + 1))
    counter += 1  # збільшуєм лічильник на 1

# виводим результат в консоль, попереднью його округливши до 5-ї цифри після коми
print(f"The result is {round(result, 5)}")