#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
        bool areAlmostEqual(string s1, string s2) {
            if(s1==s2)
                return true;
            
            vector<int> diffindex;
            
            for(int i=0; i<s1.length(); i++)
            {
                if(s1[i]!=s2[i])diffindex.push_back(i);
            }
    
            if(diffindex.size()==2 && s1[diffindex[0]]==s2[diffindex[1]] && s1[diffindex[1]]==s2[diffindex[0]]) return true;
            
            return false;
        }
    };

    int main()
    {
        string first = "bank", second = "kanb";
        Solution ans1, ans2, ans3;

        bool result1 = ans1.areAlmostEqual(first, second);

        if(result1)
            cout<<"One String swap can make Strings equal. "<<endl;

        else
            cout<<"One String swap can'nt make Strings equal. "<<endl;
            
        string third = "attack", fourth = "defend";
    	
        bool result2 = ans2.areAlmostEqual(third, fourth);

        if(result2)
    		cout<<"One String swap can make Strings equal. "<<endl;

    	else
            cout<<"One String swap can'nt make Strings equal. "<<endl;
        
        string fifth = "kelb", sixth = "kelb";
        
        bool result3 = ans3.areAlmostEqual(fifth, sixth);

    	if(result3)
            cout<<"One String swap can make Strings equal. "<<endl;

        else
            cout<<"One String swap can'nt make Strings equal. "<<endl;
}
