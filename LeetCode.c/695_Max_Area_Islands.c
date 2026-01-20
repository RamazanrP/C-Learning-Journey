#include <stdio.h>
int dfs(int** grid, int gridSize, int* gridColSize, int row, int col){
    if(row<0 || row>= gridSize || col<0 || col>= gridColSize[0] || grid[row][col] == 0){
        return 0;
    }else{
        grid[row][col] = 0;
        return 1 +  dfs(grid,gridSize,gridColSize,row+1,col)
                 +  dfs(grid,gridSize,gridColSize,row-1,col)
                 +  dfs(grid,gridSize,gridColSize,row,col-1)
                 +  dfs(grid,gridSize,gridColSize,row,col+1);
    }
}
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
int n = gridSize;
int column = *gridColSize;
int maxarea=0,guncelarea;
for(int i=0;i<n;++i){
    for(int j=0;j<column;++j){
        if(grid[i][j] == 1){
            guncelarea = dfs(grid,gridSize,gridColSize,i,j);
            if(guncelarea > maxarea) maxarea = guncelarea; // maxarea sorgusunu sadece ada bulunca yapalım ki çöp değer gelmesin
        }
    }
}
return maxarea;
}