class Solution {
public:
    vector<vector<int>> nei = {{1,0},{-1,0},{0,1},{0,-1}};
    void prt(vector<vector<int>>& grid){
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    int dfs(vector<vector<int>>& grid, int i, int j){
        stack<pair<int,int>>sta;
        int count = 0;
        sta.push({i,j});
        grid[i][j] = 0;
        while(!sta.empty()){
            auto coord = sta.top();
            grid[coord.first][coord.second] = 0;
            sta.pop();
            count++;

            for(auto n : nei){
                int x = n[0] + coord.first;
                int y = n[1] + coord.second;

                if(x >= 0 &&
                   x < grid.size() &&
                   y >= 0 &&
                   y < grid[0].size() &&
                   grid[x][y]==1
                ) {
                    grid[x][y] = 0;
                    sta.push({x,y});
                }
            }
        }
        
        return count;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    count = max(count,dfs(grid,i,j));
                }
            }
        }

        return count;
    }
};
