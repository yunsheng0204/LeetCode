/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool left_b, right_b;
        if(p == nullptr && q != nullptr)
        {
            return 0;
        }
        if(p != nullptr && q == nullptr)
        {
            return 0;
        }
        if(p == nullptr && q == nullptr)
        {
            return 1;
        }
        if(p->val != q->val)
        {
            return 0;
        }
        if(p->left == nullptr && q->left != nullptr)
        {
            return 0;
        }
        if(p->right == nullptr && q->right != nullptr)
        {
            return 0;
        }

        left_b = isSameTree(p->left, q->left);
        if(left_b==0)
        {
            return 0;
        }

        right_b = isSameTree(p->right, q->right);
        if(right_b==0)
        {
            return 0;
        }

        return 1;
    }
};