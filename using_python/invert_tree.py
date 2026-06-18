from typing import Optional, List
from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root == None:
            return None
        
        temp = self.invertTree(root.left)
        root.left = self.invertTree(root.right)
        root.right = temp
        
        return root
        
        
        
        
def build_tree(values: List[int]) -> Optional[TreeNode]:
    if not values: return None
    root = TreeNode(values[0])
    queue = deque([root])
    i = 1
    while queue and i < len(values):
        current = queue.popleft()
        if values[i] is not None:
            current.left = TreeNode(values[i])
            queue.append(current.left)
        i += 1
        if i < len(values) and values[i] is not None:
            current.right = TreeNode(values[i])
            queue.append(current.right)
        i += 1
    return root

def tree_to_list(root: Optional[TreeNode]) -> List[int]:
    if not root: return []
    result, queue = [], deque([root])
    while queue:
        current = queue.popleft()
        if current:
            result.append(current.val)
            queue.append(current.left)
            queue.append(current.right)
        else:
            result.append(None)
    while result and result[-1] is None:
        result.pop()
    return result

if __name__ == "__main__":
    solution = Solution()
    
    test_cases = [
        {"arr": [4, 2, 7, 1, 3, 6, 9], "expected": [4, 7, 2, 9, 6, 3, 1]},
        {"arr": [2, 1, 3], "expected": [2, 3, 1]},
        {"arr": [], "expected": []}
    ]
    
    for i, test in enumerate(test_cases, 1):
        root = build_tree(test["arr"])
        inverted_root = solution.invertTree(root)
        result = tree_to_list(inverted_root)
        expected = test["expected"]
        
        if result == expected:
            print(f"Test Case {i}: PASSED")
        else:
            print(f"Test Case {i}: FAILED")
            print(f"   Expected: {expected}")
            print(f"   Got:      {result}")