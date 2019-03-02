class Solution:
    def longestPalindrome(self, s: str) -> str:
        # get length of input string
        n = len(s)
        if n == 0:
            return ""
        if n == 1:
            return s

        # table[i][j] will be false if substring
        # s[i..j] is not palindrome. Else
        # table[i][j] will be true
        table = [[0 for x in range(n)] for y in range(n)]

        # All substrings of length 1 are
        # palindromes
        maxLength = 1
        for i in range(n):
            table[i][i] = True

        # check for sub-string of length 2.
        start = 0
        for i in range(n-1):
            if s[i] == s[i+1]:
                table[i][i+1] = True
                start = i
                maxLength = 2

        # Check for lengths greater than 2.
        # k is length of substring
        for k in range(3, n+1):
            # Fix the starting index
            for i in range(n-k+1):
                # Get the ending index of
                # substring from starting
                # index i and length k
                j = i + k - 1

                # checking for sub-string from
                # ith index to jth index iff
                # s[i+1] to s[(j-1)] is a
                # palindrome
                if table[i + 1][j - 1] and s[i] == s[j]:
                    table[i][j] = True

                    if (k > maxLength):
                        start = i
                        maxLength = k
        return s[start:start+maxLength]


if __name__ == '__main__':
    palindrome = Solution()
    test = "cbbd"
    print(palindrome.longestPalindrome(test))
