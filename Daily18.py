"""
2213. Longest Substring of One Repeating Character
You are given a 0-indexed string s. You are also given a 
0-indexed string queryCharacters of length k and 
a 0-indexed array of integer indices queryIndices of length k, 
both of which are used to describe k queries.

The ith query updates the character in s at index 
queryIndices[i] to the character queryCharacters[i].

Return an array lengths of length k where lengths[i] 
is the length of the longest substring of s consisting 
of only one repeating character after the ith query is performed.
"""

from typing import List


class Node:
    __slots__ = ("lch", "rch", "pref", "suff", "best", "length")

    def __init__(self, ch="", length=0):
        self.lch = ch
        self.rch = ch
        self.pref = length
        self.suff = length
        self.best = length
        self.length = length


class SegmentTree:
    def __init__(self, s: str):
        self.n = len(s)
        self.s = list(s)
        self.tree = [Node() for _ in range(4 * self.n)]
        self.build(1, 0, self.n - 1)

    def merge(self, left: Node, right: Node) -> Node:
        if left.length == 0:
            return right
        if right.length == 0:
            return left

        res = Node()
        res.length = left.length + right.length
        res.lch = left.lch
        res.rch = right.rch

        res.pref = left.pref
        if left.pref == left.length and left.rch == right.lch:
            res.pref = left.length + right.pref

        res.suff = right.suff
        if right.suff == right.length and left.rch == right.lch:
            res.suff = right.length + left.suff

        res.best = max(left.best, right.best)
        if left.rch == right.lch:
            res.best = max(res.best, left.suff + right.pref)

        return res

    def build(self, idx: int, l: int, r: int):
        if l == r:
            self.tree[idx] = Node(self.s[l], 1)
            return

        m = (l + r) // 2
        self.build(idx * 2, l, m)
        self.build(idx * 2 + 1, m + 1, r)
        self.tree[idx] = self.merge(self.tree[idx * 2], self.tree[idx * 2 + 1])

    def update(self, idx: int, l: int, r: int, pos: int, ch: str):
        if l == r:
            self.s[pos] = ch
            self.tree[idx] = Node(ch, 1)
            return

        m = (l + r) // 2
        if pos <= m:
            self.update(idx * 2, l, m, pos, ch)
        else:
            self.update(idx * 2 + 1, m + 1, r, pos, ch)

        self.tree[idx] = self.merge(self.tree[idx * 2], self.tree[idx * 2 + 1])

    def set_char(self, pos: int, ch: str):
        self.update(1, 0, self.n - 1, pos, ch)

    def answer(self) -> int:
        return self.tree[1].best


class Solution:
    def longestRepeating(
        self,
        s: str,
        queryCharacters: str,
        queryIndices: List[int],
    ) -> List[int]:

        st = SegmentTree(s)
        ans = []

        for ch, idx in zip(queryCharacters, queryIndices):
            st.set_char(idx, ch)
            ans.append(st.answer())

        return ans
