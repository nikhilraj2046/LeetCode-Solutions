class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     
        int n=s.length();
       
// Sliding Window Concept
        int l=0,r=0,maxlen=0;
        unordered_map<char,int>mp;
        while(r<n){
            if(mp.count(s[r])){
                if(mp[s[r]]>=l){
                    l=mp[s[r]]+1;
                }
            }
            int len=r-l+1;
            maxlen=max(maxlen,len);
            mp[s[r]]=r;
            r++;
        }
    return maxlen;
    }
};