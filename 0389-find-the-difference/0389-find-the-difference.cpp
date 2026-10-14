class Solution {
public:
    char findTheDifference(string s, string t) {
        // s+=t;
        // int c=0;
        // for(auto x:s) c^=x;
        // return c;
        unordered_map<char,int>mp;
        for(char x:s) mp[x]++;
        for(char c:t){
            mp[c]--;
            if(mp[c]<0) return c;
        }
        return ' ';
    }
};