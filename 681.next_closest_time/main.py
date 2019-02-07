class Solution(object):
    def nextClosestTime(self, time):
        """
        :type time: str
        :rtype: str
        """
        current_time_in_min = 60 * int(time[:2]) + int(time[3:])
        allowed_time_list = {int(x) for x in time if x != ':'}
        while True:
            current_time_in_min = (current_time_in_min+1) % (24*60)
            if all(digit in allowed_time_list
                    for block in divmod(current_time_in_min, 60)
                    for digit in divmod(block, 10)):
                return "{:02d}:{:02d}".format(*divmod(current_time_in_min, 60))


if __name__ == '__main__':
    result = Solution()
    print(result.nextClosestTime("19:34"))
