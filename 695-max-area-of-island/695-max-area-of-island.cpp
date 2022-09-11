class Solution {
    int visited[51][51];
    int max;
    int count;
    void findMaxArea(vector<vector<int>>& grid, int x, int y){
           if(x > -1 && y > -1 && x < grid.size() && y < grid[0].size() && !visited[x][y]){
               visited[x][y] = 1;
               if(grid[x][y]==1){
                    this->count++;
                findMaxArea(grid,x+1,y);
                findMaxArea(grid,x-1,y);
                findMaxArea(grid,x,y+1);
                findMaxArea(grid,x,y-1);
               }
            return;
           }
        return;
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->max = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j]){
                    this->count = 0;
                    findMaxArea(grid,i,j);
                    if(this->count > this->max){
                        this->max = this->count;
                    }
                }
            }
        }
        return this->max;
    }
};