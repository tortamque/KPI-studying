class Node:
    def __init__(self, data):
        self.data = data
        self.next_node = None
        self.previous_node = None


class DoublyLinkedList:
    def __init__(self):
        self.head_node = None

    # Додаємо елемент в кінець двохзв'язного списку
    def push(self, new_value):
        # ініціалізуємо новий вузол
        new_node = Node(new_value)
        # ініціалізуємо наступний вузол
        new_node.next_node = self.head_node

        # якщо перший вузол не порожній
        if self.head_node is not None:
            # ініціалізуємо попередній вузол
            self.head_node.previous_node = new_node

        # ініціалізуємоновий вузол
        self.head_node = new_node

    # Print the Doubly Linked list
    def print(self, node):
        while node is not None:
            print(node.data),
            node = node.next_node

    def get_node(self, index):
        temp_node = self.head_node

        for i in range(index):
            temp_node = temp_node.next_node

        return temp_node

