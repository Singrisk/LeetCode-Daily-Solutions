class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        cnt = [0] * 26
        l = 0
        res = 0
        for r, c in enumerate(s):
            ch = ord(c) - ord("a")
            cnt[ch] += 1
            while cnt[ch] > 2:
                left = ord(s[l]) - ord("a")
                cnt[left] -= 1
                l += 1
            res = max(res, r-l+1)
        return res
