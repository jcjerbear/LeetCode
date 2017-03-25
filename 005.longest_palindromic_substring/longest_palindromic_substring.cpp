#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        if(s.size() == 1) return s;

        vector<char> str;
        int i = 0;
        int j = 0;

        

    }
};

int main(int argc; char* argv[])
{
	string str = "babad";
	string result;
	Solution instance;
	result = instance.longestPalindrome(str);
	cout<<result<<endl;
	return 0;
}