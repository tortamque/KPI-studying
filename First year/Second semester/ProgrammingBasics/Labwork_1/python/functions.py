def capture_text():
    """
    Читає текст з консолі, поки не буде натиснуто клавішу Esc
    :return: текст з консолі
    """
    print('Enter your text\nPress Enter to go to the next line\nPress Ctrl + D - to end writing')
    text = ''

    #import sys
    #text = sys.stdin.read()

    while True:
        # зчитуємо текст, поки не буде помилки EOFError
        # ця помилка означае, що функція input() отримала символ End Of File (Ctrl + D)
        try:
            line = input()
        except EOFError:
            break
        text += line + '\n'
        print(f'\nCurrent text:\n{text}\nEnter another line:')


    # відкидаємо зайвий символ \n
    text = text[:len(text) - 1]

    print(f"Whole text:\n{text}\n")

    return text


def write_empty_file(file_name: str, text: str):
    """
    Записуємо текст у файл
    :param file_name: назва файлу
    :param text:      текст
    """
    write_file = open(file_name, 'wt')
    write_file.write(text)
    write_file.close()


def get_longest_words(sentences: list[str]):
    """
    Отримує найдовші слова із списку речень
    :param sentences: список з реченнями
    :return:          список з найдовшими словами
    """
    # список з найдовшими словами
    longest_words = []

    for i in range(len(sentences)):
        # заміняємо у реченні коми на пробіли (потрібно для того, щоб корректно відділити слова)
        new_sentence = sentences[i].replace(',', ' ')
        # список із словами
        words = new_sentence.split(' ')
        # найдовше слово (перше слово у реченні)
        longest_word = words[0]

        for j in range(1, len(words)):
            # якщо довжина слова більша за довжину longest_word
            if len(words[j]) > len(longest_word):
                longest_word = words[j]

        # добавляємо найдовше слово у вектор
        longest_words.append(longest_word)

    return longest_words


def print_longest_words(longest_words: list[str]):
    """
    Виводить в консоль найдовші слова і їй довжину
    :param longest_words: список із словами
    """
    print('\n')
    for i in range(len(longest_words)):
        print(f'Longest word in sentence #{i+1} is: "{longest_words[i]}" and its length: {len(longest_words[i])}')
    print('\n')


def split_sentences(text: str):
    """
    Ділить речення у тексті
    :param text: текст
    :return:     список з реченнями
    """
    text = text.replace('\n', '.')
    sentences = text.split('.')

    for i in range((len(sentences))):
        # перевіряеємо, чи є у списку "пусті речення" (потрібно для того, щоб у список не заносився пустий елемент)
        if sentences[i] == '':
            sentences.pop(i)

    return sentences


def write_to_file(file_name: str, longest_words: list[str], sentences: list[str]):
    """
    Записує текст у файл
    :param file_name:     найзва файлу
    :param longest_words: список з найдовшими словами речень
    :param sentences:     список з реченнями
    :return:
    """
    write_file = open(file_name, 'wt')

    for i in range(len(longest_words)):
        write_file.write(f"{len(longest_words[i])} {longest_words[i]} | {sentences[i]}\n")

    write_file.close()


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
