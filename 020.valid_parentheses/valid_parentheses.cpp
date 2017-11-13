#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> Stack;
        int size = s.size();

        for (int i = 0; i < size; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                Stack.push(s[i]);
            } else if (s[i] == ')') {
                if (Stack.empty() || Stack.top() != '(') return false;
                Stack.pop();
            } else if (s[i] == ']') {
                if (Stack.empty() || Stack.top() != '[') return false;
                Stack.pop();
            } else if (s[i] == '}') {
                if (Stack.empty() || Stack.top() != '{') return false;
                Stack.pop();
            }
        }

        return Stack.empty();
    }
};

int main() {
    Solution result;
    cout << result.isValid("()}") << endl;
    return 0;
}