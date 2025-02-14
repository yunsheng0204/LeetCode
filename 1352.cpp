class ProductOfNumbers {
    public:
        vector<int> product;
        int s = 1;
        ProductOfNumbers() {
            
        }
        
        void add(int num) {
            s *= num;
            product.push_back(s);
            if(num == 0)
            {
                product = {};
                s = 1;
            }
        }
        
        int getProduct(int k) {
            int len = product.size();
            if( k > len)
            {
                return 0;
            }
            else
            {
                if(k == len)
                {
                    return product[len - 1];
                }
                return product[len - 1] / product[len - 1 - k];
            }
        }
    };