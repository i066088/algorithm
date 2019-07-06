/*
https://leetcode.com/problems/longest-increasing-subsequence/solution/

Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
*/

#include <iostream>
#include <vector>
using namespace std;

//lower bound
int binarysearch(int start, int end, vector<int>& nums, int val)
{
	while (start <= end)
	{
		int m = (start + end) / 2;
		if (val <= nums[m])
		{
			end = m - 1;
		}
		else
		{
			start = m + 1;
		}
	}
	return start;
}

//O(n log n) time complexity
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {

		size_t size = nums.size();
		if (size == 0)return size;

		int max = 0;
		for (size_t i = 1; i < size; ++i)
		{
			int j = binarysearch(0, max, nums, nums[i]);
			{
				nums[j] = nums[i];
				if (j > max)
				{
					max = j;
				}
			}
		}
		return max + 1;
	}
};


//run in O(n2) complexity.
#include <iostream>
#include <vector>
using namespace std;

class Solution2 {
public:
	int lengthOfLIS(vector<int>& nums) {

		size_t size = nums.size();
		if (size == 0)return size;

		vector<int> ret;
		ret.assign(size, 1);

		for (size_t i = 1; i < size; ++i)
		{
			for (size_t j = 0; j < i; ++j)
			{
				if (nums[i] > nums[j] && ret[i] < ret[j] + 1)
				{
					ret[i] = ret[j] + 1;
				}
			}
		}

		int max = ret[0];
		for (size_t i = 1; i < size; ++i)
		{
			if (max < ret[i])
			{
				max = ret[i];
			}
		}
		return max;
	}
};

//recommend this solution
class SolutionBest {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> array; //the index is the longest number array[i] is the lowest end number
        for(int i:nums){
            auto iter=lower_bound(array.begin(),array.end(),i);
            if(iter==array.end()) array.push_back(i);
            else *iter=i;
        }
        return array.size();
    }
};
