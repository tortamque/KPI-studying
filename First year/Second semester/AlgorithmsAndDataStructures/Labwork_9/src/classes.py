class Backpack:
    def __init__(self, capacity):
        self.__capacity = capacity

    def get_capacity(self):
        return self.__capacity


class Item:
    def __init__(self, price, weight):
        self.__price = price
        self.__weight = weight

    def get_price(self):
        return self.__price

    def get_weight(self):
        return self.__weight
