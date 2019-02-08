class Solution:
    def countPrimes(self, n: 'int') -> 'int':
        # if n is less than 3 meaning there are at most 0 and 1 under consideration which are all non primes, then we return 0 immediately
        if n < 3:
            return 0
        # create a Sieve of Eratosthenes table(using a list of 1's here) to record the primes and non primes
        primes = [True] * n
        # mark slots with index 0 and 1 as false cause they are not primes
        primes[0] = primes[1] = False
        # iterate through the list using index from 2 to square root of n(**0.5) because we only need to consider factors up to sqrt(n)
        for i in range(2, int(n ** 0.5) + 1):
            # start iterating from i=2, and if primes[i] = True(all entries in the list were all initialized as True), then we mark the multiples of primes[i] as non primes in the list(marking them as False)
            if primes[i]:
                primes[i * i: n: i] = [False] * len(primes[i * i: n: i])
        # and eventually the leftover True entries in the table are all prime numbers, so we sum them up and return it
        return sum(primes)


if __name__ == '__main__':
    prime_count = Solution()
    print(prime_count.countPrimes(10))
