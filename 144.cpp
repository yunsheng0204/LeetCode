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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<TreeNode*>queue;
        vector<int> ans;
        TreeNode *temp = new TreeNode;
        if(root == nullptr)
        {
            return ans;
        }
        else
        {
            queue.push_back(root);
            while(queue.size()!=0)
            {
                temp = queue[0];
                ans.push_back(temp->val);
                queue.erase(queue.begin());
                if( temp->right != nullptr )
                {
                    queue.insert(queue.begin(),temp->right);
                }
                if( temp->left != nullptr )
                {
                    queue.insert(queue.begin(),temp->left);
                }
            }
            return ans;
        }
    }
};