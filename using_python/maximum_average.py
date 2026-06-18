from typing import List

class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        
        cur_sum = sum(nums[:k])
        max_sum = cur_sum
        
        for i in range(k, len(nums)):
            cur_sum = cur_sum - nums[i-k] + nums[i]
            
            max_sum = max(max_sum, cur_sum)
        
        
        return max_sum/k
        
        
            
            

if __name__ == "__main__":
    solution = Solution()
    
    test_cases = [
        {"nums": [1, 12, -5, -6, 50, 3], "k": 4, "expected": 12.75},
        {"nums": [5], "k": 1, "expected": 5.0},
        {"nums": [-1, -2, -3, -4], "k": 2, "expected": -1.5}
    ]
    
    for i, test in enumerate(test_cases, 1):
        result = solution.findMaxAverage(test["nums"], test["k"])
        expected = test["expected"]
        
        # Using a small tolerance for safe floating-point comparison
        if result is not None and abs(result - expected) < 1e-5:
            print(f"Test Case {i}: PASSED")
        else:
            print(f"Test Case {i}: FAILED")
            print(f"   Expected: {expected}")
            print(f"   Got:      {result}")