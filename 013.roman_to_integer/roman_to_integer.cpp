#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hashTable = {{'I', 1},
                                              {'V', 5},
                                              {'X', 10},
                                              {'L', 50},
                                              {'C', 100},
                                              {'D', 500},
                                              {'M', 1000}};

        int sum = hashTable[s.back()];
        for (int i = s.size() - 2; i >= 0; --i) {
            if (hashTable[s[i]] < hashTable[s[i + 1]]) {
                sum -= hashTable[s[i]];
            } else {
                sum += hashTable[s[i]];
            }
        }

        return sum;
    }
};

int main() {
    Solution result;
    cout << result.romanToInt("X") << endl;
    cout << result.romanToInt("XV") << endl;
    cout << result.romanToInt("XXI") << endl;
    cout << result.romanToInt("DCXXI") << endl;

    return 0;
}