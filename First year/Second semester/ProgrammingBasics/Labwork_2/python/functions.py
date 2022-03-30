import sys
import datetime
import time


def read_todays_date():
    date = input("Enter today's date (in format dd.mm.yy): ")

    return date


def capture_text():
    """
    Читає текст з консолі, поки не буде натиснуто клавішу Ctrl + D
    :return: текст з консолі
    """
    print('Enter your text\nPress Enter to go to the next line\nPress Ctrl + D - to end writing')

    text = sys.stdin.read()

    # відкидаємо зайвий символ \n
    text = text[:len(text) - 1]

    print(f"Whole text:\n{text}\n")

    return text


def read_file(file_name: str):
    """
    Читає текст з файлу
    :param file_name: назва файлу
    :return:          текст з файлу
    """
    read_input_file = open(file_name, 'rt')
    text = read_input_file.read()
    read_input_file.close()

    return text


def split_lines(text: str):
    """
    Ділить речення у тексті
    :param text: текст
    :return:     список з реченнями
    """
    lines = text.split('\n')

    for i in range(len(lines)):
        # перевіряеємо, чи є у списку "пусті речення" (потрібно для того, щоб у список не заносився пустий елемент)
        if lines[i] == '':
            lines.pop(i)

    return lines


def split_information(lines: list[str]):
    # двовимірний масив  із загальною інформацією (назва товару, дата покупки, термін гарантії)
    general_information = []

    for i in range(len(lines)):
        information_array = lines[i].split(',')
        general_information.append(information_array)

    return general_information


def write_to_file(file_name: str, string_to_write: str):
    write_file = open(file_name, 'at')
    write_file.write(string_to_write)
    write_file.close()


def check_warranty(information: list[list[str]], todays_date: str):
    """
    Формує файл із назвами виробів, у яких закінчився термін гарантії
    :param information: масив з інформацією про вироби
    :param todays_date: сьогоднішня дата
    """
    for i in range(len(information)):
        # дата покупки товару
        buy_date = information[i][1]
        # дата покупки в форматі datetime (потрібно для того, щоб перевести дату в unix формат)
        buy_date_datetime = datetime.datetime.strptime(buy_date, '%d.%m.%y')
        # переводимо дату покупки в unix формат
        buy_date_unix = time.mktime(buy_date_datetime.timetuple())

        # термін гарантії
        warranty_term = int(information[i][2])
        # термін закінчення гарантії (в unix форматі): дата покупки + термін гарантії * к-сть секунд в терміні гарантії
        warranty_expire_date = buy_date_unix + warranty_term * 86400

        # сьогоднішня дата в форматі datetime
        todays_datetime = datetime.datetime.strptime(todays_date, '%d.%m.%y')
        # сьогоднішня дата в форматі unix
        todays_date_unix = time.mktime(todays_datetime.timetuple())

        # якщо сьогоднішня дата більша за дату закінчення гарантії (в форматах unix)
        if todays_date_unix > warranty_expire_date:
            print(f"Warranty have been expired for product {information[i][0]}")

            string_to_write = f"Warranty have been expired for product: {information[i][0]},{information[i][1]},{information[i][2]}\n"
            write_to_file("output.txt", string_to_write)


def write_empty_file(file_name: str, text: str):
    """
    Записує текст у файл
    :param file_name: назва файлу
    :param text:      текст
    """
    write_file = open(file_name, 'wt')
    write_file.write(text)
    write_file.close()
