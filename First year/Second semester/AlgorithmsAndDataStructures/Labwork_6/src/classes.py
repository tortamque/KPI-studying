class Leaf:
    def __init__(self, value):
        self.left_leaf = None
        self.right_leaf = None

        self.value = value


class Tree:
    def __init__(self, root: Leaf):
        self.root = root

    def get_root(self):
        return self.root

    def __is_empty(self):
        if self.root is None:
            return True
        else:
            return False

    def __evaluate_operator(self, leaf, left_sum, right_sum):
        # якщо підкорінь має значення '+', то додаємо ліву і праву суму значень
        if leaf.value == '+':
            sum = left_sum + right_sum
            return sum
        # якщо підкорінь має значення '-', то віднімаємо ліву і праву суму значень
        elif leaf.value == '-':
            sub = left_sum - right_sum
            return sub
        # якщо підкорінь має значення '*', то множимо ліву і праву суму значень
        elif leaf.value == '*':
            mult = left_sum * right_sum
            return mult
        # якщо підкорінь має значення '/', то ділимо ліву і праву суму значень
        else:
            div = left_sum / right_sum
            return div

    def calculate_tree(self, leaf: Leaf or None):
        # якщо користувач не задав вузол, то вузлом буде корінь дерева
        if leaf is None:
            leaf = self.root

        # якщо дерево пусте, то повертаємо 0
        if self.__is_empty():
            return 0
        # якщо ж дерево не пусте
        else:
            # якщо лівий листок вузла порожній і правий листок вузла порожній
            # (тобто вузол є листком (має нульовий степінь))
            if leaf.left_leaf is None and leaf.right_leaf is None:
                # повертаємо значення вузла
                return leaf.value

            # рекурсивно рахуємо суму лівих листків вузла
            left_sum = self.calculate_tree(leaf.left_leaf)

            # рекурсивно рахуємо суму правих листків вузла
            right_sum = self.calculate_tree(leaf.right_leaf)

            # рахуємо загальну суму
            sum = self.__evaluate_operator(leaf, left_sum, right_sum)

            return sum

    def print_tree(self, leaf: Leaf, depth = 0):
        # якщо дерево пусте, то повертаємо 0
        if self.__is_empty():
            return 0
        # якщо ж дерево не пусте
        else:
            # якщо вузол не пустий
            if leaf is not None:
                # рекурсивно йдемо до лівого листка вузла
                self.print_tree(leaf.left_leaf, depth + 1)
                # виводимо значення в консоль
                print(f"{' ' * 4 * depth} -> {leaf.value}")
                # рекурсивно йдемо до правого листка вузла
                self.print_tree(leaf.right_leaf, depth + 1)

