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
 class FindElements {
    private:
        vector<bool> hashTable;
        queue<TreeNode*> q;
        queue<long long int> values;
        TreeNode *temp = new TreeNode;
        long long int temp_val;
    
    public:
    
        FindElements(TreeNode* root)  : hashTable(10000001, false), temp(nullptr) {
    
            q.push(root);
            values.push(0);
    
            while(q.empty() == false)
            {
                temp = 	q.front();
                temp_val = 	values.front();
                cout<<temp_val<<" ";
                hashTable[temp_val] = true;
    
                q.pop();
                values.pop();
                
                if(temp->left != nullptr)
                {
                    q.push(temp->left);
                    values.push(2 * temp_val + 1);
                }
                if(temp->right != nullptr)
                {
                    q.push(temp->right);
                    values.push(2 * temp_val + 2);
                }
            }
        }
        
        bool find(int target) {
            return hashTable[target];
        }
    };
    
    /**
     * Your FindElements object will be instantiated and called as such:
     * FindElements* obj = new FindElements(root);
     * bool param_1 = obj->find(target);
     */