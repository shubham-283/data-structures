class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        start = 0
        end = len(s) - 1
        
        
        while start < end:
            
            if not s[start].isalnum():
                start += 1
            elif not s[end].isalnum():
                end -= 1
            else:
                if s[start] != s[end] :
                    return False
                start += 1
                end -= 1
        return True

if __name__ == "__main__":
    solution = Solution()
    
    test_cases = [
        {"s": "A man, a plan, a canal: Panama", "expected": True},
        {"s": "race a car", "expected": False},
        {"s": " ", "expected": True},
        {"s": "0P", "expected": False}
    ]
    
    for i, test in enumerate(test_cases, 1):
        result = solution.isPalindrome(test["s"])
        expected = test["expected"]
        
        if result == expected:
            print(f"Test Case {i}: PASSED")
        else:
            print(f"Test Case {i}: FAILED")
            print(f"   Expected: {expected}")
            print(f"   Got:      {result}")