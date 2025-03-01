class Solution {
public:
    bool canBeValid(string s, string locked) {
        int len = s.size();

        if(len % 2 == 1)
        {
            return false;
        }

        int Up_unlock_count = 0;
        int Up_lock_count = 0;

        for(int i = 0; i<len; i++)
        {
            if(s[i] == '(')
            {
                if(locked[i] == 0)
                {
                    Up_unlock_count++;
                }
                else
                {
                    Up_lock_count++;
                }
            }
            else
            {
                if(locked[i] == '1')
                {
                    if(Up_lock_count == 0)
                    {
                        if(Up_unlock_count == 0)
                        {
                            return false;
                        }
                        else
                        {
                            Up_unlock_count--;
                        }
                    }
                    else
                    {
                        Up_lock_count--;
                    }
                }
                else
                {
                    Up_unlock_count++;
                }
            }
        }
        
        Up_unlock_count = 0;
        Up_lock_count = 0;
        for(int i = len-1; i>=0; i--)
        {
            if(s[i] == ')')
            {
                if(locked[i] == 0)
                {
                    Up_unlock_count++;
                }
                else
                {
                    Up_lock_count++;
                }
            }
            else
            {
                if(locked[i] == '1')
                {
                    if(Up_lock_count == 0)
                    {
                        if(Up_unlock_count == 0)
                        {
                            return false;
                        }
                        else
                        {
                            Up_unlock_count--;
                        }
                    }
                    else
                    {
                        Up_lock_count--;
                    }
                }
                else
                {
                    Up_unlock_count++;
                }
            }
        }
        return true;
    }
};