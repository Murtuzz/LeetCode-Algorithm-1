class Solution {
public:
    void floodFill (vector<vector<int>>& image, int i, int j, int color, int initialColor, vector<vector<bool>>& visited) {
        int rowLen = image.size();
        int colLen = image[0].size();
        
        if(i < 0 || j < 0  || i == rowLen || j == colLen || image[i][j] != initialColor || image[i][j] == color || visited[i][j]) {
            return;
        }
            visited[i][j] = true;
            image[i][j] = color;
            floodFill(image, i-1, j, color, initialColor, visited);
            floodFill(image, i+1, j, color, initialColor, visited);
            floodFill(image, i, j-1, color, initialColor, visited);
            floodFill(image, i, j+1, color, initialColor, visited);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>> visited(image.size(),vector<bool>(image[0].size(),false));
        floodFill(image, sr, sc, color, image[sr][sc], visited);
        return image;
    }
};