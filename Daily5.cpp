#include <iostream>
#include <vector>

using namespace std;

bool backtrack(int index, vector<int>& sequence, vector<bool>& used, int n) {
    if (index == sequence.size()) {
        return true; // All positions are filled
    }
    if (sequence[index] != 0) {
        return backtrack(index + 1, sequence, used, n); // Move to the next position
    }
    for (int i = n; i >= 1; --i) {
        if (i == 1) {
            if (!used[i]) {
                sequence[index] = i;
                used[i] = true;
                if (backtrack(index + 1, sequence, used, n)) {
                    return true;
                }
                sequence[index] = 0;
                used[i] = false;
            }
        } else {
            if (!used[i] && index + i < sequence.size() && sequence[index + i] == 0) {
                sequence[index] = i;
                sequence[index + i] = i;
                used[i] = true;
                if (backtrack(index + 1, sequence, used, n)) {
                    return true;
                }
                sequence[index] = 0;
                sequence[index + i] = 0;
                used[i] = false;
            }
        }
    }
    return false; // No valid placement found
}

vector<int> constructSequence(int n) {
    vector<int> sequence(2 * n - 1, 0); // Initialize the sequence with zeros
    vector<bool> used(n + 1, false);     // Track used numbers
    backtrack(0, sequence, used, n);      // Start backtracking from index 0
    return sequence;
}

int main() {
    int n = 3;
    vector<int> result = constructSequence(n);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl; // Output: 3 1 2 3 2

    n = 5;
    result = constructSequence(n);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl; // Output: 5 3 1 4 3 5 2 4 2

    return 0;
}