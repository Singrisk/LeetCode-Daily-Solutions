""" 
3514. Number of Unique XOR Triplets II
You are given an integer array nums.

A XOR triplet is defined as the XOR of three elements nums[i] XOR nums[j] XOR nums[k] where i <= j <= k.

Return the number of unique XOR triplet values from all possible triplets (i, j, k).
"""

class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        n = len(nums)

        if n == 1:
            return 1

        pair_xor = set()

        # XOR of every pair (i <= j)
        for i in range(n):
            for j in range(i, n):
                pair_xor.add(nums[i] ^ nums[j])

        triplets = set()

        # pair XOR ^ third element
        for x in pair_xor:
            for num in nums:
                triplets.add(x ^ num)

        return len(triplets)