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
    void flatten(TreeNode* root) {
        TreeNode *previous = new TreeNode;
        TreeNode *temp = new TreeNode;

        vector<TreeNode*> queue;
        int num = 0;

        if(root == nullptr)
        {
            return;
        }
        previous = root;
        if(previous->right != nullptr)
        {
            queue.insert(queue.begin(), previous->right);
            previous->right = nullptr;
        }
        if(previous->left != nullptr)
        {
            queue.insert(queue.begin(), previous->left);
            previous->left = nullptr;
        }

        while(queue.size()!=0)
        {
            temp = queue[0];
            queue.erase(queue.begin());
            previous->right = temp;
            previous = temp;

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
};