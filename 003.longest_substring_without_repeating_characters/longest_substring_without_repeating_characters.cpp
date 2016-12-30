#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	/*
	//submission1 - runtime error
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

        for(int i=0;i<s.length();i++)
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
        	// 	cout<<*iter<<" ";
        	// }
        	// cout<<endl<<endl;

        	str.clear();
        	temp=1;
        	// cout<<"count:"<<count<<endl;
        	// cout<<"temp:"<<temp<<endl;
        	// cout<<endl;
        }
        return count;
    }
    */

    //submission2 - runtime128ms
    int lengthOfLongestSubstring(string s) {
        vector<char> str;
        int count=0;
        int i=0;
        int j=0;
        
        while(i<s.length() && j<s.length())
        {
        	cout<<"Beginning of errLoop"<<endl<<"print vector:"<<endl;
        	for(vector<char>::iterator item=str.begin(); item!=str.end(); ++item)
			{
				cout<<*item<<" ";
			}
			cout<<endl;

        	if(isUnique(str, s[j]))
        	{
        		cout<<"insert success"<<endl;
        		str.push_back(s[j++]);
        		for(vector<char>::iterator item=str.begin(); item!=str.end(); ++item)
				{
					cout<<*item<<" ";
				}
				cout<<endl;
        		if((j-i)>count) count=j-i;
        	}
        	else
        	{
        		cout<<"insert failed"<<endl;
        		str.erase(str.begin());
        		for(vector<char>::iterator item=str.begin(); item!=str.end(); ++item)
				{
					cout<<*item<<" ";
				}
				cout<<endl;

        		i++;
        	}
        	cout<<"i:"<<i<<endl;
        	cout<<"j:"<<j<<endl;
        	cout<<"count:"<<count<<endl;
        	cout<<endl;
        }
        return count;
    }

    bool isUnique(vector<char> str, char element)
    {
    	cout<<"element:"<<element<<endl;
    	cout<<"print vector:"<<endl;
		for(vector<char>::iterator item=str.begin(); item!=str.end(); ++item)
		{
			cout<<*item<<" ";
		}
		cout<<endl;
		// if(str.empty()) return 1;
    	for(vector<char>::iterator item=str.begin(); item!=str.end(); ++item)
    	{
    		if(*item==element) return 0;
    	}
    	return 1;
    }
};

int main(int argc, char* argv[])
{
	Solution result;
	int length;
	string str = "pwwkew";
	length = result.lengthOfLongestSubstring(str);
	cout<<length<<endl;
	return 0;
}