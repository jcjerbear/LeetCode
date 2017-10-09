#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> hashTable;
        for (int i = 0; i < s.size(); ++hashTable[s[i]], --hashTable[t[i]], i++);
        for (auto it:hashTable) {
            if (it.second != 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution result;
    cout << result.isAnagram("anagram", "nagaram") << endl;
    return 0;
}