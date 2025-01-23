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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr)
        {
            return ans;
        }
        else
        {
            vector<TreeNode*> queue;
            TreeNode *temp = new TreeNode;
            temp = root;
            queue.insert(queue.begin(), temp);
            while(queue.size() != 0)
            {
                temp = queue[0];

                if(temp->right == nullptr && temp->left == nullptr)
                {
                    ans.push_back(temp->val);
                    queue.erase(queue.begin());
                    continue;
                }
                else
                {
                    if(temp->right != nullptr)
                    {
                        queue.insert(queue.begin(), temp->right);
                        temp->right = nullptr;
                    }
                    if(temp->left != nullptr)
                    {
                        queue.insert(queue.begin(), temp->left);
                        temp->left = nullptr;
                    }
                }
            }
            return ans;
        }
    }
};