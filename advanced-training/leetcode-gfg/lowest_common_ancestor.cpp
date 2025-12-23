#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:


    // FOR BST ONLY
    TreeNode* lowestCommonAncestorBST(TreeNode* root, TreeNode* p, TreeNode* q) {

        while(root){
            if(p->val < root->val && q->val < root->val)
                root = root->left;
            else if(p->val > root->val && q->val > root->val)
                root = root->right;
            else
                return root;
        }
        return nullptr;
    }



    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q)
            return root;

        TreeNode* leftPart  = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightPart = lowestCommonAncestor(root->right, p, q);

        if (leftPart && rightPart)
            return root;

        return leftPart ? leftPart : rightPart;
    }
};

int main() {
    
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    TreeNode* p = root->left->left; 
    TreeNode* q = root->left->right;

    Solution sol;
    TreeNode* ans = sol.lowestCommonAncestor(root, p, q);

    if (ans)
        cout << "LCA: " << ans->val << endl;
    else
        cout << "LCA not found" << endl;

    return 0;
}
