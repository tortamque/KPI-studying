from functions import *

a, b, c, d = capture_values()

tree = build_tree(a,b,c,d)

tree_value = tree.calculate_tree(None)
print(f"Tree value: {tree_value}\n")

print("Tree representation:\n")
tree_root = tree.get_root()
tree.print_tree(tree_root)