from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        m = {}
        
        
        for i, num in enumerate(nums):
            complement = target - num
            if complement in m:
                return [m[complement], i]
            else:
                m[num] = i
        
        return [-1, -1]
            

if __name__ == "__main__":
    solution = Solution()
    
    test_cases = [
        {"nums": [2, 7, 11, 15], "target": 9, "expected": [0, 1]},
        {"nums": [3, 2, 4], "target": 6, "expected": [1, 2]},
        {"nums": [3, 3], "target": 6, "expected": [0, 1]}
    ]
    
    for i, test in enumerate(test_cases, 1):
        result = solution.twoSum(test["nums"], test["target"])
        expected = test["expected"]
        
        # We sort the results before comparing because the problem 
        # states you can return the answer in any order.
        if result and sorted(result) == sorted(expected):
            print(f"Test Case {i}: PASSED")
        else:
            print(f"Test Case {i}: FAILED")
            print(f"   Expected: {expected}")
            print(f"   Got:      {result}")