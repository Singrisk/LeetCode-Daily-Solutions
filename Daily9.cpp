#include <iostream>
#include <vector>
using namespace std;

int tupleSameProduct(vector<int>& nums) {
    int count = 0;

    for(int i : nums){
        for(int j : nums){
            if(i!=j){
                int M=i*j;
                for(int k : nums){
                    for(int l : nums){
                        if(k!=l){
                            int N=k*l;
                            if(k!=i && k!=j){
                                if(l!=i && l!=j){
                                    if(M==N){
                                        count += 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return count;
}

int main(){
	vector<int> nums = {2,3,4,6};
	
	int sameProduct = tupleSameProduct(nums);
	cout<<"The number of arrangements of four numbers from vector that gives equal product during multiplication "<<sameProduct<<". "<<endl;
}

