#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
     *  Algorithm:
     *
     *  Go through every char in the string O(n) and map it to a hash table(unordered_map). After mapping is done, then
     *  we iterate over the hash table and find the keys that have only size 1 vector as its second. Every time we find
     *  a key then we store it into result only when its value is less than the one we found from before. Otherwise we
     *  return -1
     *
     */
    int firstUniqChar(string s) {
        int result = INT_MAX;
        unordered_map<char, vector<int>> hashTable;

        if (s.size() == 0) return -1;
        for (int i = 0; i < s.size(); i++) {
            if (hashTable.find(s[i]) == hashTable.end()) {
                hashTable.emplace(s[i], vector<int>(1, i));
            } else {
                hashTable.at(s[i]).push_back(i);
            }
        }
        for (auto it = hashTable.begin(); it != hashTable.end(); ++it) {
            if (it->second.size() == 1) {
                if (result > it->second[0]) result = it->second[0];
            }
        }
        if (result == INT_MAX) return -1;
        return result;
    }
};

int main() {
    Solution result;
    cout << result.firstUniqChar("loveleetcode") << endl;
    cout << result.firstUniqChar("cc") << endl;
    cout << result.firstUniqChar("") << endl;

    return 0;
}