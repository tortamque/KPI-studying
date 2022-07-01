from classes import *


def capture_values():
    a = float(input("Enter a value: "))
    b = float(input("Enter b value: "))
    c = float(input("Enter c value: "))
    d = float(input("Enter d value: "))

    return a, b, c, d


def build_tree(a: float, b: float, c: float, d: float):
    # перший вузол (корінь): ділення
    root = Leaf("/")

    # ініціалізуємо дерево з цим коренем
    tree = Tree(root)

    # праве значення кореня: d
    root.right_leaf = Leaf(d)
    # ліве значення кореня: множення
    root.left_leaf = Leaf("*")

    # ліве значення попередньої вершини: a
    root.left_leaf.left_leaf = Leaf(a)
    # праве значення попередньої вершини: +
    root.left_leaf.right_leaf = Leaf("+")

    # ліве значення попередньої вершини: b
    root.left_leaf.right_leaf.left_leaf = Leaf(b)
    # праве значення попередньої вершини: c
    root.left_leaf.right_leaf.right_leaf = Leaf(c)

    return tree
