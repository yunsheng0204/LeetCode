class Solution {
    public:
        int longestPalindrome(string s, string t) {
            int len_s = s.size();
            int len_t = t.size();
            int len = 0;
            int left = 0;
            int right = 0;
            int ans = 0;
            bool check = true;
    
            vector<string> s_sub;
            vector<string> t_sub;
    
            s_sub.push_back("");
            t_sub.push_back("");
    
            string temp = "";
    
            for(int i = 0; i<len_s; i++)
            {
                for(int j = i; j<len_s; j++)
                {
                    temp = s.substr(i, j - i + 1);
                    s_sub.push_back(temp);
                }
            }
    
            for(int i = 0; i<len_t; i++)
            {
                for(int j = i; j<len_t; j++)
                {
                    temp = t.substr(i, j - i + 1);
                    t_sub.push_back(temp);
                }
            }
    
            len_s = s_sub.size();
            len_t = t_sub.size();
    
            for(int i = 0; i<len_s; i++)
            {
               for(int j = 0; j<len_t; j++)
               {
                   check = true;
                   
                   temp = s_sub[i] + t_sub[j];
                   
                   len = temp.size();
                   left = 0;
                   right = len - 1;
                   
                   while(left <= right)
                   {
                       if(temp[left] != temp[right])
                       {
                           check = false;
                           break;
                       }
                       left++;
                       right--;
                   }
    
                   if(check == true)
                   {
                       // cout<<temp<<endl;
                       ans = max(len, ans);
                       continue;
                   }
                   
                   // check = true;
    
                   // temp = t_sub[j] + s_sub[i];
    
                   // left = 0;
                   // right = len - 1;
                   
                   // while(left <= right)
                   // {
                   //     if(temp[left] != temp[right])
                   //     {
                   //         check = false;
                   //         break;
                   //     }
                   //     left++;
                   //     right--;
                   // }
    
                   // if(check == true)
                   // {
                   //     cout<<temp<<endl;
                   //     ans = max(len, ans);
                   //     continue;
                   // }
               }
            }
            
            return ans;
        }
    };