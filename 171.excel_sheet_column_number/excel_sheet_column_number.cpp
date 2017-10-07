#include <iostream>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        // Decimal value of A-Z on ASCII Table is 65-90
        for (int i = 0; i < s.size(); result = result * 26 + (s.at(i) - 'A' + 1), i++);
        return result;
    }
};

int main() {
    Solution result;
    cout << result.titleToNumber("AB") << endl;
    return 0;
}