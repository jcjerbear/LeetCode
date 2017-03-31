#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        vector<int> indexVector;
        // testbit for shifting purposes
        bitset<32> testBit (1);
        cout<<"testBit: "<<testBit<<endl;
        // converting integer input values into binary
        bitset<32> xInBinary (x);
        bitset<32> yInBinary (y);
        cout<<x<<" in binary is "<< xInBinary<<endl;
        cout<<y<<" in binary is "<< yInBinary<<endl;
        // XOR result in binary
        bitset<32> bitwiseXOR (xInBinary ^ yInBinary);
        cout<<"XOR result in binary is "<<bitwiseXOR<<endl;
        // at this point, bit positions that have been set as 1 corresponds to the bits that are different
        // let's use a for loop to keep shifting from the right to the left while checking if the bit is 1
        for(int i=0;i<32;i++, bitwiseXOR >>= 1)
        {
            // if the AND of bitwiseXOR and testBit is 1 which means this bit position corresponds to the bit that is different between the two inputs
            if((bitwiseXOR & testBit) == 0x00000001)
            {
                if(indexVector.size() == 2) break;
                else indexVector.push_back(i);
            }
            cout<<i<<": bitwiseXOR: "<<bitwiseXOR<<endl;
        }
        // after the for loop we have 2 indexes recorded so then we now calculate their difference
        return indexVector[1]-indexVector[0];
    }
};

int main(int argc, char* argv[])
{
    Solution result;
    int x = 1073741824;
    int y = 1;
    int outcome;
    outcome = result.hammingDistance(x, y);
	cout<<outcome<<endl;
    return 0;
}