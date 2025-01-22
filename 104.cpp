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
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
        {
            return 0;
        }
        else
        {
            vector<int> depth;
            vector<TreeNode*> queue;
            TreeNode *temp = new TreeNode;
            int tem = 0;
            int max = 1;
            temp = root;
            queue.push_back(temp);
            depth.push_back(1);
            while(queue.size() != 0)
            {
                temp = queue[0];
                tem = depth[0];
                queue.erase(queue.begin());
                depth.erase(depth.begin());
                if(temp->left != nullptr)
                {
                    queue.push_back(temp->left);
                    depth.push_back(tem + 1);
                    if(tem + 1 > max)
                    {
                        max = tem + 1;
                    }
                }
                if(temp->right != nullptr)
                {
                    queue.push_back(temp->right);
                    depth.push_back(tem + 1);
                    if(tem + 1 > max)
                    {
                        max = tem + 1;
                    }
                }
            }
            return max;
        } 
    }
};