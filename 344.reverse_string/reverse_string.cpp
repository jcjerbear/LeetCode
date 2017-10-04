#include <iostream>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        string answer = "";
        while (s != "") {
            answer.push_back(s.back());
            s.pop_back();
        }
        return answer;
    }
};

int main() {
    Solution result;
    cout << result.reverseString("JerryChen") << endl;
    return 0;
}