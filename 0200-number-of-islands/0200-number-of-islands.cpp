class Solution {
private:
vector<pair<int,int>>dir{{1,0},{-1,0},{0,1},{0,-1}};
void dfs(vector<vector<char>>&grid,int i,int j){
    if(i<0 || i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]!='1') return ;
    grid[i][j]='$';
    for(pair<int,int>&p:dir){
        int a=i+p.first;
        int b=j+p.second;
        dfs(grid,a,b);
    }
}
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0) return 0;
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};