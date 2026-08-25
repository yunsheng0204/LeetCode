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
    bool isSymmetric(TreeNode* root) {
        vector<TreeNode*> stack_left(1001);
        vector<TreeNode*> stack_right(1001);
        TreeNode* temp_left = new TreeNode;
        TreeNode* temp_right = new TreeNode;
        int i_l = -1;
        int i_r = -1;

        if(root->left == nullptr && root->right == nullptr)
        {
            return true;
        }
        else if(root->left != nullptr && root->right == nullptr)
        {
            return false;
        }
        else if(root->left == nullptr && root->right != nullptr)
        {
            return false;
        }
        else
        {
            stack_left[++i_l] = root->left;
            stack_right[++i_r] = root->right;
            while(i_l >= 0)
            {
                temp_left = stack_left[i_l--];
                temp_right = stack_right[i_r--];
                cout<<temp_left<<" "<<temp_right<<endl;
                if(temp_left == nullptr ||  temp_right == nullptr)
                {
                    if(temp_left != nullptr  &&  temp_right == nullptr)
                    {
                        return false;
                    }
                    else if(temp_left == nullptr  &&  temp_right != nullptr)
                    {
                        return false;
                    }
                }
                else if(temp_left->val != temp_right->val)
                {
                    return false;
                }
                if(temp_left != nullptr)
                {
                    stack_left[++i_l] = temp_left->left;
                    stack_left[++i_l] = temp_left->right;
                    stack_right[++i_r] = temp_right->right;
                    stack_right[++i_r] = temp_right->left;
                }
            }

        }
        return true;
    }
};