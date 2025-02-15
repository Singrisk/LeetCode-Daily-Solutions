#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> colorTheBalls(int limit, vector<vector<int>>& queries) {
    unordered_map<int, int> ballColors;   // Stores color of each ball
    unordered_map<int, int> colorCount;   // Tracks frequency of colors
    int uniqueColors = 0;                 // Number of distinct colors
    vector<int> result;

    for (const auto& query : queries) {
        int ball = query[0], color = query[1];

        // If the ball already has a color, update its count
        if (ballColors.count(ball)) {
            int oldColor = ballColors[ball];
            colorCount[oldColor]--;
            if (colorCount[oldColor] == 0) {
                uniqueColors--;  // Remove color if no more balls have it
            }
        }

        // Assign new color
        ballColors[ball] = color;
        if (colorCount[color] == 0) {
            uniqueColors++;  // New color added
        }
        colorCount[color]++;

        // Store the result
        result.push_back(uniqueColors);
    }

    return result;
}

// Driver Code
int main() {
    int limit = 4;
    vector<vector<int>> queries = {{1, 3}, {2, 3}, {3, 2}, {1, 2}, {4, 1}};

    vector<int> result = colorTheBalls(limit, queries);

    // Print output
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
