from pprint import pprint
from queue import *


class Solution:
    def numIslands(self, grid: 'List[List[str]]') -> 'int':
        num_of_rows = len(grid)
        if num_of_rows is 0:
            return 0
        num_of_columns = len(grid[0])

        num_of_islands = 0
        for row in range(num_of_rows):
            for column in range(num_of_columns):
                # if the current visited node is 1, then it is a root of the island tree
                # if the current visited node is 0, then it is not a root of the island tree, it is just a leaf
                if grid[row][column] is "1":
                    num_of_islands += 1
                    self.dfs(grid, row, column)
                    print("---")

        return num_of_islands

    def dfs(self, grid: 'List[List[str]]', row: 'int', column: 'int') -> 'None':
        num_of_rows = len(grid)
        num_of_columns = len(grid[0])

        print(row, column)
        grid[row][column] = "0"
        if row-1 >= 0 and grid[row-1][column] is "1":
            self.dfs(grid, row-1, column)
        if row+1 < num_of_rows and grid[row+1][column] is "1":
            self.dfs(grid, row+1, column)
        if column-1 >= 0 and grid[row][column-1] is "1":
            self.dfs(grid, row, column-1)
        if column+1 < num_of_columns and grid[row][column+1] is "1":
            self.dfs(grid, row, column+1)

    def bfs(self, grid: 'List[List[str]]', row: 'int', column: 'int') -> 'None':
        num_of_rows = len(grid)
        num_of_columns = len(grid[0])

        land_queue = Queue()
        land_queue.put((row, column))
        while land_queue.qsize() > 0:
            current_row, current_column = land_queue.get()
            print(current_row, current_column)
            grid[current_row][current_column] = "0"
            if current_row-1 >= 0 and grid[current_row-1][current_column] is "1":
                land_queue.put((current_row-1, current_column))
                grid[current_row-1][current_column] = "0"
            if current_row+1 < num_of_rows and grid[current_row+1][current_column] is "1":
                land_queue.put((current_row+1, current_column))
                grid[current_row+1][current_column] = "0"
            if current_column-1 >= 0 and grid[current_row][current_column-1] is "1":
                land_queue.put((current_row, current_column-1))
                grid[current_row][current_column-1] = "0"
            if current_column+1 < num_of_columns and grid[current_row][current_column+1] is "1":
                land_queue.put((current_row, current_column+1))
                grid[current_row][current_column+1] = "0"

    def gridPrint(self, grid: 'List[List[str]]') -> 'None':
        pprint(grid)
        # print(grid[row][column] for row in range(len(grid))
        #       for column in range(len(grid[row])))


if __name__ == '__main__':
    islands = Solution()
    grid = [["1", "1", "1", "1", "0"], ["1", "1", "0", "1", "0"],
            ["1", "1", "0", "0", "0"], ["0", "0", "0", "0", "0"]]
    islands.gridPrint(grid)
    print(islands.numIslands(grid))
    grid = [["1", "1", "0", "0", "0"], ["1", "1", "0", "0", "0"],
            ["0", "0", "1", "0", "0"], ["0", "0", "0", "1", "1"]]
    islands.gridPrint(grid)
    print(islands.numIslands(grid))
