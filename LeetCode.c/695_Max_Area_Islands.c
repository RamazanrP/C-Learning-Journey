int adahesapla(int** mat, int row, int col, int size, int colsize){
if(row<0 || row >= size || col<0 || col >= colsize || mat[row][col] == 0) return 0;
mat[row][col] = 0; // Önce bu adayı (valid ise) batıralım
// Soru bize bir ada bulunca sadece adayı değil bir de adanın boyutunu istiyor. O yüzden int return edeceğiz
return  1 // Adanın kendi boyutu
        +adahesapla(mat,row+1,col,size,colsize)
        +adahesapla(mat,row-1,col,size,colsize)
        +adahesapla(mat,row,col+1,size,colsize)
        +adahesapla(mat,row,col-1,size,colsize);
}
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
int guncelalan=0,maxalan=0;
for(int i=0;i<gridSize; i++){
    for(int j=0; j<gridColSize[0]; j++){
        if(grid[i][j] == 1){
            guncelalan = adahesapla(grid,i,j,gridSize,gridColSize[0]);
        }
        if(guncelalan > maxalan) maxalan = guncelalan;
    }
}
return maxalan;
}