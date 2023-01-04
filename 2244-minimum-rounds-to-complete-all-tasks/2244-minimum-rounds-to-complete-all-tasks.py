class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        return max(sum(v // 3 + (not not v % 3) if v != 1 else -inf for v in Counter(tasks).values()), -1)