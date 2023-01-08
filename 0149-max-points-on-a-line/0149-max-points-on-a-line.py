class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        N = len(points)
        if N < 3: return N

        max_points = 0
        for i in range(N):
            slopes = Counter()
            for j in range(i + 1, N):
                dx, dy = map(lambda x, y: x - y, points[j], points[i])

                # a vertical line will have an undefined slope
                slope = dy / dx if dx else float(inf)
                slopes[slope] += 1

                max_points = max(max_points, slopes[slope])
        return max_points + 1