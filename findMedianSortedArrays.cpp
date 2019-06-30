/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/
Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        size_t n1 = nums1.size();
        size_t n2 = nums2.size();

        bool isEven = (n1 + n2) % 2 == 0;
        size_t median = (n1 + n2 + 1) / 2;

        int sum = 0;
        size_t i = 0, j = 0;
        bool bfound = false;
        for (; i < n1 && j < n2;)
        {
            int min = 0;
            if (nums1[i] < nums2[j])
            {
                min = nums1[i];
                ++i;
            }
            else
            {
                min = nums2[j];
                ++j;
            }

            if (i + j == median)sum += min;
            if (isEven)
            {
                if (i + j == median + 1)
                {
                    sum += min;
                    bfound = true;
                    break;
                }
            }
        }

        if (!bfound)
        {
            if(i < n1)
            {
                int k = median - i - j;
                if(sum == 0)
                {
                    sum += nums1[i - 1 + k];
                }
                if(isEven)
                {
                    sum += nums1[i + k];
                }
            }

            if(j < n2)
            {
                int k = median - i - j;
                if(sum == 0)
                {
                    sum += nums2[j - 1 + k];
                }
                if(isEven)
                {
                    sum += nums2[j + k];
                }
            }
        }
        if (isEven)
            return sum / 2.0;
        else
            return sum;
    }
};
