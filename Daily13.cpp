#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> product_count;
        int result = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                
                // If product already exists
                if (product_count.find(product) != product_count.end()) {
                    result += product_count[product] * 8;
                }
                
                product_count[product]++;
            }
        }
        
        return result;
    }
};
