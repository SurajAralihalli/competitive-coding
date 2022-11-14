// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/product-of-the-last-k-numbers/
// Date: 14th Nov, 2021
// Tags: data-stream, prefix-product, prefix-sum

class ProductOfNumbers {
public:
    vector<int> prefixProduct;
    ProductOfNumbers() {
         prefixProduct = {1};
    }
    
    void add(int num) {
       if(num>0)
       {
         prefixProduct.push_back(prefixProduct.back()*num);  
       }
       else
       {
         prefixProduct = {1};
       }
        
    }
    
    int getProduct(int k) {
        if(prefixProduct.size()>k)
        {
            return prefixProduct.back() / prefixProduct[prefixProduct.size()-k-1];
        }
        else
        {
            return 0;
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
