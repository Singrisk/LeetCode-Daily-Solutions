"""
3536. Maximum Product of Two Digits
You are given a positive integer n.

Return the maximum product of any two digits in n.

Note: You may use the same digit twice if it appears more than once in n.
"""

class Solution:
    def maxProduct(self, n: int) -> int:
        first = second = 0

        while n:
            digit = n % 10

            if digit >= first:
                second = first
                first = digit
            elif digit > second:
                second = digit

            n //= 10

        return first * second
