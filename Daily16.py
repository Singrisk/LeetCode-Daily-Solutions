"""
2996. Smallest Missing Integer Greater Than Sequential Prefix Sum
You are given a 0-indexed array of integers nums.

A prefix nums[0..i] is sequential if, for all 1 <= j <= i, nums[j] = nums[j - 1] + 1. In particular, the prefix consisting only of nums[0] is sequential.

Return the smallest integer x missing from nums such that x is greater than or equal to the sum of the longest sequential prefix.""
"""

class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        s = 0
        e = len(nums) - 1
        if nums[0]+e == nums[e]:
            last = e + 1

        while s<=e:
            mid = s + (e-s)//2

            if nums[mid] == nums[0]+mid and (nums[mid - 1] == nums[0]+mid-1 or mid == 0):
                s = mid + 1
            
            else:
                last = mid
                e = mid - 1
        
        d = 0
        if nums[0] != 1:
            d = nums[0]*(nums[0]-1)//2
        
        p = nums[0]+last
        sum = p*(p-1)//2 - d
        
        nums.sort()
        found = True
        while found:
            s = 0
            e = len(nums) - 1
            while s<=e:
                mid = s + (e-s)//2

                if nums[mid] == sum:
                    break
                
                elif nums[mid] < sum:
                    s = mid + 1
                
                else:
                    e = mid - 1
            
            if s>e:
                ans = sum
                found = False
            
            
            sum += 1
        
        return ans

