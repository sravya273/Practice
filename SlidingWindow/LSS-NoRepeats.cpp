/** gfg link - https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/ */
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int left =0;
        int n = s.length();
        int right =0;
        int result =0;
        unordered_set <char> uset;
        while(left<n && right<n)
        {
            while(uset.find(s[right])!=uset.end())
            {
                uset.erase(s[left]);
                left++;
            }
            uset.insert(s[right]);
            result = max(result, right-left+1);
            right++;
        }
        return result;
    }
};
