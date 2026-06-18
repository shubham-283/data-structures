class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        
        for char in s:
            if char in '({[':
                stack.append(char)
            else:
                if not stack:
                    return False
                
                top = stack[-1]
                if (char == ')' and top == '(') | (char == '}' and top == '{') | (char == ']' and top == '['):
                    stack.pop()
                else :
                    return False
                
                
        return len(stack) == 0
        

if __name__ == "__main__":
    solution = Solution()
    
    test_cases = [
        {"s": "()", "expected": True},
        {"s": "()[]{}", "expected": True},
        {"s": "(]", "expected": False},
        {"s": "([)]", "expected": False},
        {"s": "{[]}", "expected": True},
        {"s": "]", "expected": False}
    ]
    
    for i, test in enumerate(test_cases, 1):
        result = solution.isValid(test["s"])
        expected = test["expected"]
        
        if result == expected:
            print(f"Test Case {i}: PASSED")
        else:
            print(f"Test Case {i}: FAILED")
            print(f"   Expected: {expected}")
            print(f"   Got:      {result}")