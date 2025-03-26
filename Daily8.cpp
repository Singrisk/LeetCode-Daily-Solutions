#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
        int tupleSameProduct(vector<int>& nums) {
            unordered_map<int, vector<pair<int, int>>> product_map;
            int n = nums.size();
        
            // Generate all possible unordered pairs and their products
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    int product = nums[i] * nums[j];
                    product_map[product].emplace_back(nums[i], nums[j]);
                }
            }
        
            int total = 0;
            for (const auto& entry : product_map) {
                int m = entry.second.size();
                if (m >= 2) {
                    int combinations = m * (m - 1) / 2;
                    total += 8 * combinations;
                }
            }
        
            return total;

        }
};

int main()
{
	vector<int> product = {1, 2, 10, 5};
	Solution sol;
	
	int nooftuple;
	nooftuple = sol.tupleSameProduct(product);
	
	cout<<"No. of tuples "<<nooftuple<<endl;
}
