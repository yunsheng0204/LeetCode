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
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;

        TreeNode* root_avg = new TreeNode();
        TreeNode* root_num = new TreeNode();

        function(root, root_avg, root_num, ans);

        return ans;
    }
    void function(TreeNode* root, TreeNode* root_avg, TreeNode* root_num, int &ans)
    {
        bool le = false;
        bool ri = false;

        int num_left = 0, num_right = 0;
        int val_left = 0, val_right = 0;

        if(le == false)
        {
            le = true;
            if(root->left != nullptr)
            {
                root_avg->left = new TreeNode();
                root_num->left = new TreeNode();
                function(root->left, root_avg->left, root_num->left, ans);
                num_left = root_num->left->val;
                val_left = root_avg->left->val;
            }
            else
            {
                num_left = 0;
                val_left = 0;
            }
        }
        if(ri == false)
        {
            ri = true;
            if(root->right != nullptr)
            {
                root_avg->right = new TreeNode();
                root_num->right = new TreeNode();
                function(root->right, root_avg->right, root_num->right, ans);   
                num_right = root_num->right->val;
                val_right = root_avg->right->val;
            }
            else
            {
                num_right = 0;
                val_right = 0;
            }
        }

        root_num->val = 1 + num_right + num_left;
        root_avg->val = (root->val + val_right + val_left);
        

        if(root_avg->val / root_num->val  == root->val)
        {
            ans++;
        }
    }
};