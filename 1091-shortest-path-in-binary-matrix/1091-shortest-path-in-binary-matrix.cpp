class Solution {
private:
vector<vector<int>>directions{{1,1},{0,1},{1,0},{0,-1},{-1,0},{-1,-1},{1,-1},{-1,1}};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(n==0 || m==0 || grid[0][0]!=0 || grid[n-1][m-1]!=0) return -1;
        queue<pair<int,int>>que;
        que.push({0,0});
        grid[0][0]=1;
        auto isSafe=[&](int x,int y){
            return x>=0 && x<n && y>=0 && y<m;
                    };
        int steps=1;
        while(!que.empty()){
            int size=que.size();
            while(size--){
                auto curr=que.front();
                que.pop();
                int x=curr.first;
                int y=curr.second;
                if(x==n-1 && y==m-1) return steps;
                for(auto dir:directions){
                    int a=x+dir[0];
                    int b=y+dir[1];
                    if(isSafe(a,b) && grid[a][b]==0){
                        que.push({a,b});
                        grid[a][b]=1;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};