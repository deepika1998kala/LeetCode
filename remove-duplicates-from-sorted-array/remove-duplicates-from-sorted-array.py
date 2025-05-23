class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
#         if not nums:
#             return 0
#         st = set(nums)
#         n = len(nums)
#         i = len(st)
#         res = list(st)
#         while(i<n):
#             res.append(_)
#         return res
        if not nums:
            return 0

        # Use sorted set to maintain order
        unique = sorted(set(nums))
        k = len(unique)

        # Overwrite nums with unique elements
        for i in range(k):
            nums[i] = unique[i]

        # Optional: simulate underscores (just for your understanding, not for submission)
        for i in range(k, len(nums)):
            nums[i] = "_"

        return k
        
        