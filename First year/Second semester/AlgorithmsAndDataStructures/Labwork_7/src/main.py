from functions import *

linked_list = DoublyLinkedList()

n = 1000

for i in range(n-1, -1, -1):
    linked_list.push(i)

element = 435

index = fibonacci_search_DoublyLinkedList(linked_list, element, n)
print(f"Found {element} at index {index}")
