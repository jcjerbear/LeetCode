class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []
        nums.sort()
        length = len(nums)
        for i in range(length-2):  # [8]
            if nums[i] > 0:
                break  # [7]
            if i > 0 and nums[i] == nums[i-1]:
                continue  # [1]

            l, r = i+1, length-1  # [2]
            while l < r:
                total = nums[i]+nums[l]+nums[r]

                if total < 0:  # [3]
                    l += 1
                elif total > 0:  # [4]
                    r -= 1
                else:  # [5]
                    result.append([nums[i], nums[l], nums[r]])
                    while l < r and nums[l] == nums[l+1]:  # [6]
                        l += 1
                    while l < r and nums[r] == nums[r-1]:  # [6]
                        r -= 1
                    l += 1
                    r -= 1
        return result


if __name__ == '__main__':
    three_sum = Solution()
    array = [-1, 0, 1, 2, -1, -4]
    print(three_sum.threeSum(array))
