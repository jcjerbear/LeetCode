class Solution:
    def productExceptSelf(self, nums):
        product = 1
        result = []
        length = len(nums)
        for i in range(length):
            result.append(product)
            product *= nums[i]
        product = 1
        for i in range(length-1, -1, -1):
            result[i] *= product
            product *= nums[i]
        return result


if __name__ == '__main__':
    product = Solution()
    nums = [1, 2, 3, 4]
    print(product.productExceptSelf(nums))
