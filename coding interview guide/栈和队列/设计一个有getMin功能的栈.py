class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.data_stack = list()
        self.min_stack = list()

    def push(self, x: int) -> None:
        if len(self.min_stack) == 0:
            self.min_stack.insert(0, x)
        elif x <= self.getMin():
            self.min_stack.insert(0, x)

        self.data_stack.insert(0, x)

    def pop(self) -> None:
        if (len(self.data_stack) == 0):
            assert RuntimeError("your stack is empty")
        num = self.data_stack[0]
        del self.data_stack[0]
        if (num == self.getMin()):
            del self.min_stack[0]

    def top(self) -> int:
        if (len(self.data_stack) == 0):
            assert RuntimeError("your stack is empty")
        else:
            return self.data_stack[0]

    def getMin(self) -> int:
        if (len(self.min_stack) == 0):
            assert RuntimeError("your stack is empty")
        else:
            return self.min_stack[0]

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()