#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s){
    	string temp;
    	string result;
    	for(string::reverse_iterator rit=s.rbegin(); rit!=s.rend(); ++rit)
    	{
    		// case if the next char is not a space
    		if(*(rit+1)!=' '){
    			temp+=*rit;
    			// if this char is also the last char of the entire sentence, we add temp to result as well
    			if(rit==s.rend()-1)
    			{
    				result.insert(0,temp);
    				temp.clear();
    			}
    			// case if the next char is a space
    		}else{
    			temp+=*rit++; // we still have to add the current one into temp
    			result.insert(0,temp);
    			result.insert(0," ");
    			temp.clear();
    		}
    		// cout<<temp<<endl;
    		// cout<<result<<endl;
		}
        return result;
    }
};

int main(int argc, char* argv[])
{
    Solution result;
    string str ("Let's take LeetCode contest");
	cout<<result.reverseWords(str)<<endl;
    return 0;
}