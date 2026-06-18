from typing import Optional, List

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None:
            return head
        past = None
        cur = head
        pre = head.next
        
        while cur != None:
            cur.next = past
            past = cur
            cur = pre
            if pre != None:
                pre = pre.next
        
        return past

def build_list(arr: List[int]) -> Optional[ListNode]:
    if not arr: return None
    head = ListNode(arr[0])
    curr = head
    for val in arr[1:]:
        curr.next = ListNode(val)
        curr = curr.next
    return head

def list_to_array(head: Optional[ListNode]) -> List[int]:
    arr = []
    while head:
        arr.append(head.val)
        head = head.next
    return arr

if __name__ == "__main__":
    solution = Solution()
    
    test_cases = [
        {"arr": [1, 2, 3, 4, 5], "expected": [5, 4, 3, 2, 1]},
        {"arr": [1, 2], "expected": [2, 1]},
        {"arr": [], "expected": []}
    ]
    
    for i, test in enumerate(test_cases, 1):
        # Build the linked list from the array
        head = build_list(test["arr"])
        
        # Run the solution
        reversed_head = solution.reverseList(head)
        
        # Convert back to array for easy comparison
        result = list_to_array(reversed_head)
        expected = test["expected"]
        
        if result == expected:
            print(f"Test Case {i}: PASSED")
        else:
            print(f"Test Case {i}: FAILED")
            print(f"   Expected: {expected}")
            print(f"   Got:      {result}")