class ProductOfNumbers {
public:
    vector<int> prefixProduct;

    ProductOfNumbers() {
        prefixProduct.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            prefixProduct = {1};
        } else {
            prefixProduct.push_back(prefixProduct.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = prefixProduct.size();
        if (n - 1 < k) {
            return 0;
        }
        return prefixProduct[n - 1] / prefixProduct[n - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
