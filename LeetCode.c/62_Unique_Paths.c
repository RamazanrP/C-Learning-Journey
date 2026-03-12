int uniquePaths(int m, int n) {
int i,j;
int** grid = (int**)malloc(m*sizeof(int*));
for(i=0;i<m;i++){
    grid[i] = (int*)malloc(n*sizeof(int));
}
for(i=0;i<n;i++){
    grid[0][i] = 1;
}
for(i=0;i<m;i++){
    grid[i][0] = 1;
}
for(i=1;i<m;i++){
    for(int j=1;j<n;j++){
        grid[i][j] = grid[i-1][j] + grid[i][j-1];
    }
}
return grid[m-1][n-1];
}