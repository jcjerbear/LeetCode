class Solution:
    def islandPerimeter(self, grid: 'List[List[int]]') -> 'int':
        nrows = len(grid)
        if nrows == 0:
            return 0
        ncolumns = len(grid[0])

        perimeter_count = 0
        for row in range(nrows):
            for column in range(ncolumns):
                if grid[row][column] == 1:
                    # we are looking at adjacent nodes that are 0 to spot boundaries
                    # it is important here to put the potential index overflow detection statement first
                    if row-1 < 0 or grid[row-1][column] == 0:
                        perimeter_count += 1
                    if row+1 >= nrows or grid[row+1][column] == 0:
                        perimeter_count += 1
                    if column-1 < 0 or grid[row][column-1] == 0:
                        perimeter_count += 1
                    if column+1 >= ncolumns or grid[row][column+1] == 0:
                        perimeter_count += 1
        return perimeter_count

    # def dfs(self, grid: 'List[List[int]]', row: 'int', column: 'int', perimeter_count: 'int') -> 'int':
    #     nrows = len(grid)
    #     ncolumn = len(grid[0])

    #     if row-1 >= 0 and


if __name__ == '__main__':
    perimeter = Solution()
    island_map = [[0, 1, 0, 0], [1, 1, 1, 0], [0, 1, 0, 0], [1, 1, 0, 0]]
    print(perimeter.islandPerimeter(island_map))
