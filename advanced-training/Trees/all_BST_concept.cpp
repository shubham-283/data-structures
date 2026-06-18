#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

class BST
{
private:
    int tree_diameter = 0;

    Node *root = nullptr;

    Node *insertNode(Node *root, int val)
    {
        if (!root)
            return new Node(val);

        if (val < root->data)
            root->left = insertNode(root->left, val);
        else if (val > root->data)
            root->right = insertNode(root->right, val);

        return root;
    }

    // traversal
    void preOdrerTraversal(Node *root)
    {
        if (!root)
            return;

        cout << root->data << " ";

        preOdrerTraversal(root->left);
        preOdrerTraversal(root->right);
    }
    void inOrderTraversal(Node *root)
    {
        if (!root)
            return;
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
    void postOrderTraversal(Node *root)
    {
        if (!root)
            return;
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";
    }

    // bfs - traversal
    void bfsTraversal(Node *root)
    {
        if (!root)
            return;
        queue<Node *> que;

        que.push(root);
        int level = 0;

        while (!que.empty())
        {
            int level_size = que.size();
            cout << "LEVEL " << level << " => ";

            for (int i = 0; i < level_size; i++)
            {
                Node *cur = que.front();
                que.pop();

                cout << cur->data << " ";

                if (cur->left)
                    que.push(cur->left);
                if (cur->right)
                    que.push(cur->right);
            }
            // cout<<endl;
            // for(int i=0; i<level_size; i++){
            //     cout<<"/  \\";
            // }
            level++;
            cout << endl;
        }
    }

    // searching
    bool searchNode(Node *root, int target)
    {
        if (!root)
            return false;
        if (root->data == target)
            return true;
        if (target < root->data)
        {
            return searchNode(root->left, target);
        }
        return searchNode(root->right, target);
    }
    Node *findNode(Node *root, int target)
    {
        if (!root)
            return nullptr;
        if (root->data == target)
            return root;
        if (target < root->data)
        {
            return findNode(root->left, target);
        }
        return findNode(root->right, target);
    }

    // height
    int treeHeight(Node *root)
    {
        if (!root)
            return 0;

        int left_height = treeHeight(root->left);
        int right_height = treeHeight(root->right);

        tree_diameter = max(tree_diameter, left_height + right_height);
        return 1 + max(left_height, right_height);
    }

    // successor
    Node *successorNode(Node *root)
    {
        root = root->right;
        while (root->left)
            root = root->left;
        return root;
    }

    Node *predecessorNode(Node *root)
    {
        root = root->left;
        while (root->right)
            root = root->right;
        return root;
    }

    // delete Node
    Node *deleteNode(Node *root, int target, bool &deleted)
    {
        if (!root)
            return nullptr;

        if (target < root->data)
            root->left = deleteNode(root->left, target, deleted);
        else if (target > root->data)
            root->right = deleteNode(root->right, target, deleted);
        else
        {
            deleted = true;
            // node with 2 children
            if (root->left && root->right)
            {
                Node *temp = successorNode(root);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data, deleted);
            }
            // node with only left child
            else if (root->left && !root->right)
            {
                Node *left_subtree = root->left;
                delete root;
                return left_subtree;
            }
            // node with only right child
            else if (!root->left && root->right)
            {
                Node *right_subtree = root->right;
                delete root;
                return right_subtree;
            }
            // leaf node
            else
            {
                delete root;
                return nullptr;
            }
        }
        return root;
    }

    // minimum - maximum
    Node *minimumNode(Node *root)
    {
        while (root->left)
            root = root->left;
        return root;
    }
    Node *maximumNode(Node *root)
    {
        while (root->right)
            root = root->right;
        return root;
    }

    bool isValidBST(Node *root)
    {
        if (!root)
            return true;

        queue<pair<Node *, pair<long long, long long>>> que;

        que.push({root, {LLONG_MIN, LLONG_MAX}});

        while (!que.empty())
        {
            auto cur = que.front();
            que.pop();

            Node *node = cur.first;
            long long low = cur.second.first;
            long long high = cur.second.second;

            if (node->data <= low || node->data >= high)
                return false;

            if (node->left)
                que.push({node->left, {low, node->data}});
            if (node->right)
                que.push({node->right, {node->data, high}});
        }

        return true;
    }

    Node *LowestCommonAncestor(Node *root, int a, int b)
    {
        if (!root)
            return nullptr;

        if ((a < root->data && b > root->data) || (a > root->data && b < root->data) || a == root->data || b == root->data)
            return root;

        if (a < root->data && b < root->data)
            return LowestCommonAncestor(root->left, a, b);

        return LowestCommonAncestor(root->right, a, b);
    }

    void clear(Node *root)
    {
        if (!root)
            return;
        clear(root->left);
        clear(root->right);

        delete root;
    }

public:
    ~BST()
    {
        clear(root);
    }

    void insert(int val)
    {
        root = insertNode(root, val);
    }

    void preOrder()
    {
        cout << "PREORDER: ";
        preOdrerTraversal(root);
        cout << endl;
    }
    void inOrder()
    {
        cout << "INORDER: ";
        inOrderTraversal(root);
        cout << endl;
    }
    void postOrder()
    {
        cout << "POSTORDER: ";
        postOrderTraversal(root);
        cout << endl;
    }
    void bfs()
    {
        cout << endl
             << "BFS Traversal: " << endl;
        bfsTraversal(root);
        cout << endl;
    }

    void search(int target)
    {
        if (searchNode(root, target))
            cout << "ELEMENT FOUND" << endl;
        else
            cout << "ELEMENT NOT FOUND" << endl;
    }
    void searchNew(int target)
    {
        if (findNode(root, target))
            cout << "ELEMENT FOUND" << endl;
        else
            cout << "ELEMENT NOT FOUND" << endl;
    }
    void height()
    {
        cout << "Height of Tree = " << treeHeight(root) << endl;
    }
    void diameter()
    {
        tree_diameter = 0;
        treeHeight(root);
        cout << "Diameter of Tree  = " << tree_diameter << endl;
    }

    void successor(int target)
    {
        Node *cur = findNode(root, target);
        Node *suc = successorNode(cur);
        cout << "Successor = " << suc->data << endl;
    }

    void predecessor(int target)
    {
        Node *cur = findNode(root, target);
        Node *pre = predecessorNode(cur);
        cout << "Predecessor = " << pre->data << endl;
    }

    void deleteNodeTree(int target)
    {
        bool deleted = false;
        root = deleteNode(root, target, deleted);
        if (deleted)
            cout << "Node Deleted" << endl;
        else
            cout << "Node does not exist" << endl;
    }

    void minimum()
    {
        Node *temp = minimumNode(root);
        cout << "Minimum = " << temp->data << endl;
    }
    void maximum()
    {
        Node *temp = maximumNode(root);
        cout << "Maximum = " << temp->data << endl;
    }

    void validateBST()
    {
        bool temp = isValidBST(root);
        if (temp)
            cout << "It's valid Binary Search Tree";
        else
            cout << "It's not a valid Binary Search Tree";

        cout << endl;
    }

    void LCA(int a, int b)
    {
        Node *temp = LowestCommonAncestor(root, a, b);
        if (temp)
            cout << "LCA = " << temp->data;
        else
            cout << "LCA Not Found";

        cout << endl;
    }
};

int main()
{
    BST bst;
    vector<int> nums = {8, 3, 10, 1, 6, 14, 4, 7, 13, 1, 2, 5};
    for (int num : nums)
    {
        bst.insert(num);
    }
    // bst.preOrder();
    // bst.minimum();
    // bst.maximum();
    // bst.inOrder();
    // bst.postOrder();
    bst.bfs();

    // bst.search(12);
    // bst.searchNew(5);
    // bst.height();
    // bst.diameter();

    // bst.deleteLeaf(25);
    // bst.deleteSingle(14);
    // bst.deleteNodeTree(14);
    // bst.bfs();

    // bst.deleteNodeTree(8);
    // bst.bfs();
    // bst.successor(6);
    // bst.predecessor(6);

    // bst.successor(10);
    bst.validateBST();
    bst.LCA(5, 4);
}
