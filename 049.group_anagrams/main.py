from collections import defaultdict


class Solution:
    def groupAnagrams(self, strs: 'List[str]') -> 'List[List[str]]':
        anagrams = defaultdict(list)
        for word in strs:
            sorted_word = ''.join(sorted(word))
            anagrams[tuple(sorted_word)].append(word)
        return list(anagrams.values())


if __name__ == '__main__':
    anagrams = Solution()
    test = ["eat", "tea", "tan", "ate", "nat", "bat"]
    print(anagrams.groupAnagrams(test))
