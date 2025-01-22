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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<TreeNode*> queue;
        vector<TreeNode*> queue1;

        vector<int> temp_ans;

        vector<int> level;
        vector<int> level1;

        int l;
        TreeNode *temp = new TreeNode;
        vector<vector<int>> ans;

        if(root == nullptr)
        {
            return ans;
        }
        else
        {
            temp = root;

            queue.push_back(temp);
            level.push_back(0);

            queue1.push_back(temp);
            level1.push_back(0);

            while(queue.size() != 0)
            {
                temp = queue[0];
                l = level[0];

                queue.erase(queue.begin());
                level.erase(level.begin());

                if(temp->left != nullptr)
                {
                    queue.push_back(temp->left);
                    level.push_back(l + 1);

                    queue1.push_back(temp->left);
                    level1.push_back(l + 1);
                }
                if(temp->right != nullptr)
                {
                    queue.push_back(temp->right);
                    level.push_back(l + 1);

                    queue1.push_back(temp->right);
                    level1.push_back(l + 1);
                }
            }
            int check = 0;
            while(queue1.size() != 0)
            {
                temp = queue1[0];
                l = level1[0];

                queue1.erase(queue1.begin());
                level1.erase(level1.begin());

                flag: 
                if(check == l)
                {
                    temp_ans.push_back(temp->val);
                }
                else
                {
                    ans.push_back(temp_ans);
                    temp_ans.clear();
                    check++;

                    goto flag;
                }
            }
            ans.push_back(temp_ans);
            temp_ans.clear();
        }
        return ans;
    }
};