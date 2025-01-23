class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int temp1 = 0, temp2 = 0, sum = 0;
        int c = 0;
        char tem1 = 0, tem2 = 0;

        while(a!="" && b!="")
        {
            tem1 = a.back();
            tem2 = b.back();

            a.pop_back();
            b.pop_back();

            if(tem1 == '0')
            {
                temp1 = 0;
            }
            else
            {
                temp1 = 1;
            }

            if(tem2 == '0')
            {
                temp2 = 0;
            }
            else
            {
                temp2 = 1;
            }

            sum = temp1 + temp2 + c;

            if(sum == 0)
            {
                ans.insert(0, "0");
                c = 0;
            }
            else if(sum == 1)
            {
                ans.insert(0, "1");
                c = 0;
            }
            else if(sum == 2)
            {
                ans.insert(0, "0");
                c = 1;
            }
            else if(sum == 3)
            {
                ans.insert(0, "1");
                c = 1;
            }
        }
        while(a!="" && b=="")
        {
            tem1 = a.back();
            a.pop_back();

            if(tem1 == '0')
            {
                temp1 = 0;
            }
            else
            {
                temp1 = 1;
            }

            sum = temp1 + c;
            
            if(sum == 0)
            {
                ans.insert(0, "0");
                c = 0;
            }
            else if(sum == 1)
            {
                ans.insert(0, "1");
                c = 0;
            }
            else if(sum == 2)
            {
                ans.insert(0, "0");
                c = 1;
            }
        }

        while(a=="" && b!="")
        {
            tem2 = b.back();
            b.pop_back();

            if(tem2 == '0')
            {
                temp2 = 0;
            }
            else
            {
                temp2 = 1;
            }
            
            sum = temp2 + c;
            
            if(sum == 0)
            {
                ans.insert(0, "0");
                c = 0;
            }
            else if(sum == 1)
            {
                ans.insert(0, "1");
                c = 0;
            }
            else if(sum == 2)
            {
                ans.insert(0, "0");
                c = 1;
            }
        }
        if(c == 1)
        {
            ans.insert(0, "1");
        }
        return ans;
    }
};