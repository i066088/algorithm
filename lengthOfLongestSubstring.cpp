/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/
Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.empty())return 0;
        
        int chars[256];
        memset(chars, -1, sizeof(chars));
      
        int max_len = 0;
        int len = 0;
        int prev = 0;
        for(size_t i = 0, n = s.size(); i < n;++i)
        {  
            int c =  s[i];
            if(chars[c] == -1)
            {
                len++;
            }
            else
            {
                int j = chars[c] ;
                if(max_len < len)
                {
                    max_len = len;
                }
                
                len -= (j - prev);
                for(int k = prev; k <= j; ++k)
                {
                    chars[s[k]] = -1;
                }
                prev = j+1;
            }
            chars[c]=i;
        }
        return max_len > len ? max_len: len;
    }
};
