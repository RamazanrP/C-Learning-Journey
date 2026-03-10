int dfs(int**grid, int satir, int sutun, int m, int n, int sifir_sayaci){
if(m<0 || m>= satir || n<0 || n>= sutun || grid[m][n] == -1){
    return 0;
}
if(grid[m][n] == 2){ // Bayrağı bulduğumuzda bütün kareler gezildi mi kontrol ediyoruz
    return (sifir_sayaci==-1)?1:0;
}
grid[m][n] = -1,sifir_sayaci--; // Sorun yoksa bu kareyi işaretliyoruz, sifir kareler azalıyor
int total_paths = dfs(grid,satir,sutun,m-1,n,sifir_sayaci)+
                  dfs(grid,satir,sutun,m+1,n,sifir_sayaci)+
                  dfs(grid,satir,sutun,m,n-1,sifir_sayaci)+
                  dfs(grid,satir,sutun,m,n+1,sifir_sayaci);
grid[m][n] = 0; // Bir kere olsun sağa gidip tüm mümkün yerleri gezince başlangıçtan diğer 3 yöne olan yolları deneemek için 0'a eşitledik
return total_paths; // return 1 o yol var, 0 da o yol yok diyor. Kısacası o 1 ve 0'lar gerçek sayı değeri. Üst üste birikmeyi sağlayan
}
int uniquePathsIII(int** grid, int gridSize, int* gridColSize) {
int satir=gridSize, sutun=gridColSize[0],i,j,x=0,y=0,sifir_sayaci=0;
for(i=0;i<satir;i++){
    for(j=0;j<sutun;j++){
        if(grid[i][j] == 1){
            x=i,y=j;
        }
        if(grid[i][j] == 0) sifir_sayaci++;
    }
}
return dfs(grid,satir,sutun,x,y,sifir_sayaci);
  
}