class Matrix:
    def __init__(self, data: list[list[int]]):
        self.__data = data

    def __getitem__(self, index):
        return self.__data[index]

    def __len__(self):
        return len(self.__data)