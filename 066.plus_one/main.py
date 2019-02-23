class Solution:
    def plusOne(self, digits: 'List[int]') -> 'List[int]':
        number = 0
        # faster iterative approach
        for i in range(len(digits)):
            number = number*10 + digits[i]

        # slower exponential approach
        # for i in range(len(digits)):
        #     number += digits[i] * 10**(len(digits)-1-i)
        return [int(digit) for digit in str(number+1)]


if __name__ == '__main__':
    plusone = Solution()
    digits = [9, 9, 9]
    print(plusone.plusOne(digits))
