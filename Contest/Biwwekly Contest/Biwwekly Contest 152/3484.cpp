class Spreadsheet {
                temp = 10 * temp + (formula[index2] - '0');
                index2++;
                if(index2 == len)
                {
                    break;
                }
            }
            num2 = sheet[ formula[index] - 'A' ][ temp ];
        }
        else
        {
            num2 = formula[len-1] - '0';
            index = len-2;
            count = 1;
            while(formula[index] - '0' >= 0 && formula[index] - '0' <= 9)
            {
                num2 = num2 + pow(10, count) * (formula[index] - '0');
                count++;
                index--;
            }
        }
        cout<<num1<<" "<<num2;
        return num1 + num2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */©leetcode