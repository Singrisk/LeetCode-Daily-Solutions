#include <iostream>
#include <vector>
using namespace std;

int locatePivot(vector<int>& nums, int pivot){
    int k;

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == pivot){
            k=i;

            break;
        }
    }

    return k;
}

vector<int> pivotArray(vector<int>& nums, int pivot) {
    int p = locatePivot(nums, pivot);

    for(int j = 0; j <= 99*nums.size()/100+1; j++){
        if((j==1 && p==nums.size()-1) || (j==2 && p==nums.size()-2)){
            for(int j = 0; j <= nums.size(); j++){

                if(p!=0){
                    if(nums[p-1]>pivot){
                        nums[p]=nums[p-1];
                        nums[p-1]=pivot;
                        p = p-1;
                    }
                }

                if(p!=nums.size()-1){
                    if(nums[p+1]<pivot){
                        nums[p]=nums[p+1];
                        nums[p+1]=pivot;
                        p=p+1;
                    }
                }

                for(int i = p-1; i >= 0; i--){
                    if(nums[i]>=pivot && nums[i]>nums[i+1]){
                        int x = nums[i];
                        nums[i]=nums[i+1];
                        nums[i+1]=x;

                        if(i+1==p)
                            p=i;
                    }
                }
            }
        }

        if((j==1 && p==0) || (j==2 &&  p==1)){
            for(int j = 0; j <= nums.size(); j++){
                if(p!=0){
                    if(nums[p-1]>pivot){
                        nums[p]=nums[p-1];
                        nums[p-1]=pivot;
                        p = p-1;
                    }
                }

                if(p!=nums.size()-1){
                    if(nums[p+1]<pivot){
                        nums[p]=nums[p+1];
                        nums[p+1]=pivot;
                        p=p+1;
                    }
                }

                for(int i = p+1; i < nums.size(); i++){
                    if(nums[i]<=pivot && nums[i]<nums[i-1]){
                        int x = nums[i];
                        nums[i]=nums[i-1];
                        nums[i-1]=x;

                        if(i-1==p)
                            p=i;
                    }
                }
            }
        }

        if(p!=0){
            if(nums[p-1]>pivot){
                nums[p]=nums[p-1];
                nums[p-1]=pivot;
                p = p-1;
            }
        }

        if(p!=nums.size()-1){
            if(nums[p+1]<pivot){
                nums[p]=nums[p+1];
                nums[p+1]=pivot;
                p=p+1;
            }
        }

        for(int i = p-1; i >= 0; i--){
            if(nums[i]==pivot){
                for(int j = i; j < p; j++){
                    if(nums[j]>nums[j+1] && nums[j]==pivot){
                        int x = nums[j];
                        nums[j]=nums[j+1];
                        nums[j+1]=x;
                    }
                }
            }

            if(nums[i]>pivot && nums[i]>nums[i+1]){
                int x = nums[i];
                nums[i]=nums[i+1];
                nums[i+1]=x;
            

                if(i+1==p)
                    p=i;
            }
        }

        for(int i = p+1; i < nums.size(); i++){
            if(nums[i]==pivot){
                for(int j = i; j > p; j--){
                    if(nums[j]<nums[j-1] && nums[j]==pivot){
                        int x = nums[j];
                        nums[j]=nums[j-1];
                        nums[j-1]=x;
                    }
                }
            }
            
            if(nums[i]<=pivot && nums[i]<nums[i-1]){
                int x = nums[i];
                nums[i]=nums[i-1];
                nums[i-1]=x;

                if(i-1==p)
                    p=i;
            }
        }
    }
    return nums;
}

int main(){
	vector<int> nums = {2,3,4,6,8,-9, -10, 2, 100};
	int pivot = 6;
	
	vector<int> ans = pivotArray(nums, pivot);
	cout<<"The pivoted array around a pivot [";
	for(int i:ans)
		cout<<i<<" ";
	cout<<"]"<<endl;
}
