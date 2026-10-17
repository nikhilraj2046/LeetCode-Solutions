class Solution {
public:
    int calPoints(vector<string>& arr) {
        int n=arr.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(arr[i]=="C"){
                ans.pop_back();
            }
            else if(arr[i]=="+"){
                int d=*ans.rbegin()+*(ans.rbegin()+1);
                ans.push_back(d);
            }
            else if(arr[i]=="D"){
                int d=ans.back()*2;
                ans.push_back(d);
            }
            else{ 
                int x=stoi(arr[i]);
                ans.push_back(x);
            }
        }
        int sum2=0;
        for(auto x:ans){
            sum2+=x;
        }
        return sum2;
    }
};