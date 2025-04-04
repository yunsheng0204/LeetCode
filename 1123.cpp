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
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            vector<TreeNode*> queue;
            TreeNode *temp = new TreeNode;
            int max = 0;
            int depth = 0;
            temp = root;
            queue.insert(queue.begin(), root);
            put_node(root, queue, max, 0, temp);
            return temp;
        }
    
        int put_node(TreeNode* root, vector<TreeNode*> &queue, int &max, int depth, TreeNode* &temp)
        {
            int left_max = 0;
            int right_max = 0;
            if(root->right != nullptr)
            {
                queue.insert(queue.begin(), root->right);
            }
            if(root->left != nullptr)
            {
                queue.insert(queue.begin(), root->left);
                left_max = put_node(root->left, queue, max, depth + 1, temp);
            }
            else
            {
                left_max = depth;
            }
            if(root->right != nullptr)
            {
                right_max = put_node(root->right, queue, max, depth + 1, temp);
            }
            else
            {
                right_max = depth;
            }
            if(left_max == right_max && max <= left_max)
            {
                temp = queue[0];
                max = left_max;
            }
            queue.erase(queue.begin());
            cout<<root->val<<" ";
            if(left_max>right_max)
            {
                return left_max;
            }
            else
            {
                return right_max;
            }
        }
    };