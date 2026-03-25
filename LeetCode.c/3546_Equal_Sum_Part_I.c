#include <stdbool.h>
// Soru bize matris veriyor acaba satır veya sütundan iki eşit parçaya bölünebilir mi diye sorguluyor
bool canPartitionGrid(int** grid, int gridSize, int* gridColSize) {
int m=gridSize,n= gridColSize[0];
long long total=0;
long long* satir_toplami = (long long*)calloc(m,sizeof(long long)); // İndisleriyle beraber hangi satırın/sütunun toplamı kaç onu tutuyoruz
long long* sutun_toplami = (long long*)calloc(n,sizeof(long long)); // Biriktirerek toplama işlemini en sonda yapacağız
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        total += grid[i][j];
        sutun_toplami[j] += grid[i][j];
        satir_toplami[i] += grid[i][j];
    }
}
if(total %2 != 0) return false; // Toplamımız ikiye bölünmezse!
long long target = total/2;
long long guncel=0; // Biriktirerek toplamak için kullanacağız
for(int i=0;i<m-1;i++){ // En az bir satır veya sütunun boşta kalması için -1 yazdık
    guncel += satir_toplami[i];
    if(guncel == total/2) return true;
}
guncel=0;
for(int i=0;i<n-1;i++){
    guncel += sutun_toplami[i];
    if(guncel == total/2) return true;
}
return false;
}