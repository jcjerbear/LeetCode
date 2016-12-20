#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> indices;
		for(vector<int>::size_type i=0;i<nums.size();i++)
		{
			for(vector<int>::size_type j=i+1;j<nums.size();j++)
			{
				//if the difference of target-nums[i] equals to the current checking value
				if(nums[j] == target-nums[i])
				{
					indices.push_back(i);
					indices.push_back(j);
					return indices;
				}
			}
		}
		indices.clear();
		return indices;
	}
};

int main(int argc, char* argv[])
{
	Solution twosum;
	int array[] = {3,2,4};
	vector<int> nums(array, array+sizeof(array)/sizeof(int));
	vector<int> result;
	
	// for(vector<int>::size_type i=0; i<nums.size(); i++)
	// {
	// 	cout<<i<<":"<<nums[i]<<" ";
	// }
	result = twosum.twoSum(nums, 6);
	for(vector<int>::iterator item=result.begin(); item!=result.end(); ++item)
	{
		cout<<*item<<" ";
	}
	cout<<endl;
	return 0;
}
