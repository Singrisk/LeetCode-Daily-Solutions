#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> product_count;
        int count = 0;
        int n = nums.size();

        for(int i = 0; i<n; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                int product=nums[i]*nums[j];
                
                count+=product_count[product];
                product_count[product]++;
            }
        }

        return count*8;
    }
};

int main()
{
    vector<int> nums1 = [2, 3, 4, 6];
    Solution ans1, ans2;

    int result1 = ans1.tupleSameProduct(nums1);
    cout<<"No. of valid tuples, which make same product with first two numbers and last two numbers are "<<result1<<endl;
           
    vector<int> nums2 = [1, 2, 4, 5, 10];

    bool result2 = ans2.tupleSameProduct(nums2);
    cout<<"No. of valid tuples, which make same product with first two numbers and last two numbers are "<<result1<<endl;
}
