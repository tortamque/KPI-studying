from functions import *

# читаємо текст з консолі, поки не буде натиснуто клавішу Esc
text_to_write = capture_text()
# записуємо цей текст у файл input.txt
write_empty_file("input.txt", text_to_write)

# читаємо текст з файлу input.txt у змінну text
text = read_file("input.txt")
print(f"Text on input:\n{text}\n")

# список з реченнями тексту
sentences = split_sentences(text)
print("Sentences list:")
print(*sentences, sep='\n')

# вектор з найдовшими словами кожного реченя
longest_words = get_longest_words(sentences)
print_longest_words(longest_words)

# записуємо текст у файл output.txt
write_to_file("output.txt", longest_words, sentences)
output_text = read_file("output.txt")
print(output_text)
