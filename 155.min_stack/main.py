import sys


class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.min = sys.maxsize

    def push(self, x: 'int') -> 'None':
        # push element x onto stack
        # append x into the back of the stack list
        self.stack.append(x)
        if x < self.min:
            self.min = sys.maxsize

    def pop(self) -> 'None':
        # removes the element on top of the stack
        if self.min is self.stack[-1]:
            self.min = sys.maxsize
        self.stack = self.stack[:-1]

    def top(self) -> 'int':
        # get the top element of the stack
        return self.stack[-1]

    def getMin(self) -> 'int':
        # retrieve the minimum element in the stack
        # slow sorting way
        # temp_stack = self.stack.copy()
        # temp_stack.sort()
        # return temp_stack[0]
        # fast indexing way
        if self.min is sys.maxsize and self.stack is not None:
            self.min = min(self.stack)
        return self.min


if __name__ == '__main__':
    obj = MinStack()
    obj.push(-10)
    obj.push(14)
    obj.getMin()
    obj.getMin()
    obj.push(-20)
    obj.getMin()
    obj.getMin()
    obj.top()
    obj.getMin()
    obj.pop()
    obj.push(10)
    obj.push(-7)
    obj.getMin()
    obj.push(-7)
    obj.pop()
    obj.top()
    obj.getMin()
    obj.pop()
