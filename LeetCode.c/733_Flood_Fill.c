void dfs(int** image, int sr, int sc, int color, int newColor, int rows, int cols) {
if (sr < 0 || sr >= rows || sc < 0 || sc >= cols) return;
if (image[sr][sc] != color) return; // Eski renkten değilse dur, haritadaki 0'ları newColor yapmaktan kurtarır!s
if (image[sr][sc] == newColor) return; // Zaten boyanmışsa dur
image[sr][sc] = newColor;
dfs(image, sr - 1, sc, color, newColor, rows, cols);
dfs(image, sr + 1, sc, color, newColor, rows, cols); 
dfs(image, sr, sc - 1, color, newColor, rows, cols); 
dfs(image, sr, sc + 1, color, newColor, rows, cols);
}

// LeetCode'un bizden istediği ana fonksiyon
int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
int original = image[sr][sc];
if(original != color){
    dfs(image, sr, sc, original, color, imageSize, imageColSize[0]);
}
*returnSize = imageSize;
*returnColumnSizes = imageColSize;
return image;
}