#include <iostream>
#include <bitset>
#include <string>
using namespace std;

class Solution {
public:
    int findComplement(int num){
        int onesPosition;
        string numString;
        
        bitset<32> numBinary (num);
        numString = numBinary.to_string();
        // cout<<"1:"<<numString<<endl;
        onesPosition = numString.find("1");
        // cout<<"pos:"<<onesPosition<<endl;
        if(onesPosition!=string::npos) numString = numString.substr(onesPosition);
        else return 1;
        // cout<<"2:"<<numString<<endl;
        for(int i=0; i<numString.length(); ++i)
        {
            if(numString[i]=='0') numString[i]='1';
            else numString[i]='0';
        }
        // cout<<"3:"<<numString<<endl;
        return stoi(numString,nullptr,2);
    }
};

int main(int argc, char* argv[])
{
    Solution result;
    cout<<result.findComplement(5)<<endl;
    return 0;
}