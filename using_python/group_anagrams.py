from typing import List

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = {}
        for s in strs:
            key = ''.join(sorted(s))
            if key not in d:
                d[key] = []
            d[key].append(s)
        return list(d.values())
        
        
        
        
if __name__ == "__main__":
    solution = Solution()
    
    test_cases = [
        {
            "strs": ["eat","tea","tan","ate","nat","bat"], 
            "expected": [["bat"],["nat","tan"],["ate","eat","tea"]]
        },
        {"strs": [""], "expected": [[""]]},
        {"strs": ["a"], "expected": [["a"]]}
    ]
    
    for i, test in enumerate(test_cases, 1):
        result = solution.groupAnagrams(test["strs"])
        expected = test["expected"]
        
        # Helper to sort nested lists for order-agnostic comparison
        def normalize(lst_of_lsts):
            if not lst_of_lsts: return []
            return sorted([sorted(l) for l in lst_of_lsts])
        
        if result is not None and normalize(result) == normalize(expected):
            print(f"Test Case {i}: PASSED")
        else:
            print(f"Test Case {i}: FAILED")
            print(f"   Expected: {normalize(expected)}")
            print(f"   Got:      {normalize(result) if result else None}")