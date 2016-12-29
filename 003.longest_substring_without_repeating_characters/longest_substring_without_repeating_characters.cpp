#include <iostream>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // cout<<s<<endl;
        int count=0;
        int temp=1;
        set<char> str;

        // str.insert('a');
        // for(set<char>::iterator iter=str.begin(); iter!=str.end(); ++iter)
        // {
        // 	cout<<*iter<<" "<<endl;
        // }

        for(int i=0;i<s.length()-1;i++)
        {
        	// cout<<s[i]<<endl;
        	str.insert(s[i]);
        	// for(set<char>::iterator iter=str.begin(); iter!=str.end(); ++iter)
        	// {
        	// 	cout<<*iter<<" "<<endl;
        	// }

        	for(int j=i+1;j<s.length();j++)
        	{
        		// cout<<"count:"<<count<<endl;
        		// cout<<"temp:"<<temp<<endl;        		
        		// cout<<"s["<<i<<"]: "<<s[i]<<", s["<<j<<"]: "<<s[j]<<endl;
        		
        		// if(s[i]!=s[j]) temp++;
        		// cout<<s[j]<<endl;
        		if(str.insert(s[j]).second) temp++;
        		else break;
        	}
        	// cout<<"count:"<<count<<endl;
        	// cout<<"temp:"<<temp<<endl;
        	if(temp>count) count=temp;
        	// for(set<char>::iterator iter=str.begin(); iter!=str.end(); ++iter)
        	// {
        	// 	cout<<*iter<<" "<<endl;
        	// }

        	str.clear();
        	temp=1;
        	// cout<<"count:"<<count<<endl;
        	// cout<<"temp:"<<temp<<endl;
        	// cout<<endl;
        }
        return count;
    }
};

int main(int argc, char* argv[])
{
	Solution result;
	int length;
	string str = "abcabcbb";
	length = result.lengthOfLongestSubstring(str);
	cout<<length<<endl;
	return 0;
}