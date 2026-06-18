from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_p = 0
        min_stock = float('inf')
        
        for price in prices:
            
            min_stock = min(min_stock, price)
            max_p = max(max_p, price-min_stock)
        
        return max_p
            

if __name__ == "__main__":
    solution = Solution()
    
    test_cases = [
        {"prices": [7, 1, 5, 3, 6, 4], "expected": 5},
        {"prices": [7, 6, 4, 3, 1], "expected": 0},
        {"prices": [2, 4, 1], "expected": 2},
        {"prices": [2, 1, 2, 1, 0, 1, 2], "expected": 2}
    ]
    
    for i, test in enumerate(test_cases, 1):
        result = solution.maxProfit(test["prices"])
        expected = test["expected"]
        
        if result == expected:
            print(f"Test Case {i}: PASSED")
        else:
            print(f"Test Case {i}: FAILED")
            print(f"   Expected: {expected}")
            print(f"   Got:      {result}")