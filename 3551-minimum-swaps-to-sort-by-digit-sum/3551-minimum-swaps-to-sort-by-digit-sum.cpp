class Solution {
    private:
    int getSum(int num){
        int sum=0;
        while(num>0){
            int d=num%10;
            sum+=d;
            num/=10;
        }
        return sum;
    }
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<pair<pair<int,int>,int>>arr(n);
        for(int i=0;i<n;i++){
            arr[i]={{getSum(nums[i]),nums[i]},i};
        }
        sort(arr.begin(),arr.end());
        vector<bool>v(n,false);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(v[i] || arr[i].second==i) continue;
        int temp=0;
        int j=i;
        while(!v[j]){
            v[j]=true;
            j=arr[j].second;
            temp++;
        }
        if(temp>0){
            cnt+=(temp-1);
        }
        }
        return cnt;
    }
};