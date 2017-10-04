#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long answer = 0;
        while (x != 0) {
            answer = answer * 10 + x % 10;
            x /= 10;
        }
        return (answer < INT32_MIN || answer > INT32_MAX) ? 0 : answer;
    }
};

int main(int argc, char *argv[]) {
    Solution result;
    cout << result.reverse(1) << endl;
    return 0;
}