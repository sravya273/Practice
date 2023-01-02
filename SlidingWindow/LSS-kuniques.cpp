/**
https://www.geeksforgeeks.org/find-the-longest-substring-with-k-unique-characters-in-a-given-string/
*/

class Solution{
  public:
    int longestKSubstr(string s, int k) 
    {
        int n = s.length();
        int left = 0;
        int right = 0;
        int result = -1;
        
        unordered_map <char,int> umap;
        
        while(left<n && right<n)
        {
            while(umap.size()>k)
            {
                umap[s[left]]--;
                if(umap[s[left]]==0)
                {
                    umap.erase(s[left]);
                }
                left++;
            }
            umap[s[right]]++;
            if(umap.size()==k)
            {
                result = max(result, right-left+1);
            }
            right++;
        }
        return result;
    }
};
