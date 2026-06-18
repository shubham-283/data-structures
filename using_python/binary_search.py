from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        
        while left <= right:
            mid = left + (right - left)//2
            
            if(nums[mid] == target):
                return mid
            elif nums[mid] < target:
                left = mid+1
            else:
                right = mid-1
            
        return -1
                
        
        
        
if __name__ == "__main__":
    solution = Solution()
    
    test_cases = [
        {"nums": [-1, 0, 3, 5, 9, 12], "target": 9, "expected": 4},
        {"nums": [-1, 0, 3, 5, 9, 12], "target": 2, "expected": -1},
        {"nums": [5], "target": 5, "expected": 0},
        {"nums": [2, 5], "target": 0, "expected": -1}
    ]
    
    for i, test in enumerate(test_cases, 1):
        result = solution.search(test["nums"], test["target"])
        expected = test["expected"]
        
        if result == expected:
            print(f"Test Case {i}: PASSED")
        else:
            print(f"Test Case {i}: FAILED")
            print(f"   Expected: {expected}")
            print(f"   Got:      {result}")