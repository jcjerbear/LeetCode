#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int totalLength = nums1Size+nums2Size;
	int pivotIndex = totalLength/2+1;

	if(totalLength%2 == 0){ //even length case
		
	}else{ //odd length case
		pivotIndex 
		//when the pivotIndex is within nums1 array's range
		if(pivotIndex <= nums1Size) return nums1[pivotIndex];
		//when the pivotIndex is within nums2 array's range
		else
		{
			pivotIndex-=nums1Size;
			return nums2[pivotIndex];
		}
	}
}

int main(int argc, char* argv[])
{
	int arrayA[] = {1,2};
	int arrayB[] = {3,4};
	int nums1Size = sizeof(arrayA)/sizeof(arrayA[0]);
	int nums2Size = sizeof(arrayB)/sizeof(arrayB[0]);
	double median;
	/*
	for(int i=0;i<(sizeof(arrayA)/sizeof(arrayA[0]));i++)
	{
		printf("%d ", arrayA[i]);
	}
	printf("\n");
	*/

	median = findMedianSortedArrays(arrayA, nums1Size, arrayB, nums2Size);
	return 0;
}