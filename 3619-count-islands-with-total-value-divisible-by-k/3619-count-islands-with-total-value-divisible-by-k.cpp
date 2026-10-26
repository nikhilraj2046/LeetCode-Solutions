class Solution {
private:
long long dfs(vector<vector<int>>& grid , int i,int j,int n,int m){
    if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0) return 0;
    long long sum=grid[i][j];
    grid[i][j]=0;
     sum+=dfs(grid,i+1,j,n,m);
    sum+=dfs(grid,i-1,j,n,m);
    sum+=dfs(grid,i,j+1,n,m);
    sum+=dfs(grid,i,j-1,n,m);
    return sum;
}
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
                long long s=dfs(grid,i,j,n,m);
                    if(s%k==0) count++;
                }
            }
        }
        return count;
    }
};