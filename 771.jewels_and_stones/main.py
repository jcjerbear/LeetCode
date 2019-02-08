class Solution:
    def numJewelsInStones(self, J: 'str', S: 'str') -> 'int':
        jewels = [str(jewel) for jewel in J]
        jewels_dict = dict.fromkeys(jewels, 0)
        for stone in S:
            if stone in jewels:
                jewels_dict[stone] += 1
        return sum(jewels_dict.values())


if __name__ == '__main__':
    jewels = Solution()
    print(jewels.numJewelsInStones("aA", "aAAbbbb"))
    print(jewels.numJewelsInStones("z", "ZZ"))
