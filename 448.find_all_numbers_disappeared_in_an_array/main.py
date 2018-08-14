class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        dict = {}
        result = []
        for num in nums:
            dict[num] = 1
        for i in range(1, len(nums) + 1):
            if i not in dict:
                result.append(i)
        return result


if __name__ == '__main__':
    result = Solution()
    # input = [4, 3, 2, 7, 8, 2, 3, 1]
    # input = [10, 2, 5, 10, 9, 1, 1, 4, 3, 7]
    input = [1, 1]
    output = result.findDisappearedNumbers(input)
    print(output)
