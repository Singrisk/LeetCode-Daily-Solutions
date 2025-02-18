#include <iostream>
#include <stack>
#include <string>

using namespace std;

string smallestNumber(string pattern) {
    stack<int> st;
    string result = "";
    int num = 1; // Start with 1 (smallest available digit)

    for (int i = 0; i <= pattern.size(); i++) {
        st.push(num++); // Push current number

        // If we reach end of pattern or encounter 'I', pop from stack
        if (i == pattern.size() || pattern[i] == 'I') {
            while (!st.empty()) {
                result += to_string(st.top());
                st.pop();
            }
        }
    }
    
    return result;
}

// Example test cases
int main() {
    cout << smallestNumber("IIIDIDDD") << endl;  // Output: "123549876"
    cout << smallestNumber("DDD") << endl;      // Output: "4321"
    return 0;
}
