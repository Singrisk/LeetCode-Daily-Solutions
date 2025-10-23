#include <bits/stdc++.h>
using namespace std;

bool sameFinalDigits(string s) {
    // Repeat until only two digits remain
    while (s.length() > 2) {
        string next = "";
        for (int i = 0; i < (int)s.length() - 1; i++) {
            int a = s[i] - '0';
            int b = s[i + 1] - '0';
            next += to_string((a + b) % 10);
        }
        s = next; // update string
    }

    // Check final two digits
    return s[0] == s[1];
}

int main() {
    string s1 = "3902";
    cout << (sameFinalDigits(s1) ? "true" : "false") << endl;  // true

    string s2 = "34789";
    cout << (sameFinalDigits(s2) ? "true" : "false") << endl;  // false
}
