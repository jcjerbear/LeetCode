class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []
        nums.sort()
        length = len(nums)
        if length < 3:
            return []
        # starting from i == 0 till the third last int, because the last 2 spots are for l and r
        for i in range(length-2):  # [8]
            # after we sort it, the negative numbers should be at front
            # if the current iterated number is positive already, then the integers
            # located with index l and index r adding together with the current iterated integer
            # will obviously be greater than 0
            if nums[i] > 0:
                # so if current iterated integer is >0
                # then there is no point keep iterating
                # so we break the for loop
                break  # [7]
            # In the case when the current iterated integer
            # is the same as the last one, then we can skip the rest of the code
            # and jump into the next for loop iteration
            if i > 0 and nums[i] == nums[i-1]:
                continue  # [1]

            # now starting with pointer l pointing at the
            # next integer of the current iterated integer,
            # and pointer r pointing at the last integer in nums
            l, r = i+1, length-1  # [2]
            while l < r:
                total = nums[i]+nums[l]+nums[r]

                if total < 0:  # [3]
                    l += 1
                elif total > 0:  # [4]
                    r -= 1
                else:  # [5]
                    result.append([nums[i], nums[l], nums[r]])
                    # we need to move the left and right pointers
                    # to the next different numbers, so we dont get
                    # repeating results
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
