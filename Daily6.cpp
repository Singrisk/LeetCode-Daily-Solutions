#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
        for (char c : tiles) freq[c]++;
        
        return backtrack(freq);
    }

private:
    int backtrack(unordered_map<char, int>& freq) {
        int total = 0;
        for (auto& [ch, count] : freq) {
            if (count > 0) {
                
                freq[ch]--;
                total += 1 + backtrack(freq);
                
                freq[ch]++;
            }
        }
        return total;
    }
};

int main() {
    Solution sol;
    cout << sol.numTilePossibilities("AAB") << endl;
    cout << sol.numTilePossibilities("AAABBC") << endl;
    cout << sol.numTilePossibilities("V") << endl;
    return 0;
}
