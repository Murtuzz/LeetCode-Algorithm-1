class Solution {
public:
    void floodFill (vector<vector<int>>& image, int i, int j, int color, int initialColor) {
        int rowLen = image.size();
        int colLen = image[0].size();
        
        if(i < 0 || j < 0  || i == rowLen || j == colLen || image[i][j] != initialColor || image[i][j] == color) {
            return;
        }
            image[i][j] = color;
            floodFill(image, i-1, j, color, initialColor);
            floodFill(image, i+1, j, color, initialColor);
            floodFill(image, i, j-1, color, initialColor);
            floodFill(image, i, j+1, color, initialColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        floodFill(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};