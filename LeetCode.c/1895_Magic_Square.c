#include <stdbool.h>
#include <stdlib.h>
bool isMagic(int** grid, int** rowsum, int** colsum, int row, int col, int k){
    long long diag1=0,diag2=0;
    for(int i=0;i<k;++i){
        diag1 += grid[row+i][col+i]; // Buradaki row ve col bizim bloğumuzun en sol-üst koordinatı
        diag2 += grid[row+i][col+k-1-i];
    }
    if(diag1 != diag2) return false;
    long long target = diag1; // Demek çaprazlar eşitse bu ortak değere göre hareket edeceğiz satır ve sütunlar için
    for(int i=0;i<k;++i){ // İteratif arttığı için en son-başlangıç yaparsak satırın toplamı bulunmuş olur. Bu da sütun üzerinden
        long long flexibleRowSum = rowsum[row+i][col+k] - rowsum[row+i][col]; // Burada row+i, k'yı geçmiyor çünkü biz row'u yani 41. satırdaki i'yi en fazla m-k'ya kadar ilerletiyoruz
        if(flexibleRowSum != target) return false;
    }
    for(int j=0;j<k;++j){ // Bu da en aşağıdan yukarıyı çıkarıyor
        long long flexibleColSum = colsum[row+k][col+j] - colsum[row][col+j];
        if(flexibleColSum != target) return false;
    }
    return true; // Buraya kadar gelmişse true döndür
}
int largestMagicSquare(int** grid, int gridSize, int* gridColSize) {
int i,j,m=gridSize,n= gridColSize[0],sum=0;
int** rowsum = (int**)malloc(m*sizeof(int*)); // Bana m tane "dizi adresi" tutan matris aç diyoruz. int tutmayacağız, adreslerini tutuyoruz
for(int i=0;i<m;++i){
    rowsum[i] = (int*)malloc((n+1)*sizeof(int)); // n tane sütunumuz var, 0'dan başlayacağımız için +1 koyduk
    rowsum[i][0] = 0; // İlk sütun hep 0, sağa doğru görsel olarak matrisin satırları yığın olarak toplanıyor
    for(int j=0;j<n;++j){
        rowsum[i][j+1] = rowsum[i][j] + grid[i][j]; // j+1 en son n. indise gidecek, it's okay
    }
}
int** colsum = (int**)malloc((m+1)*sizeof(int*)); // Yığınlaşmada satır sayısı değişmezken sütun için ilk satırı 0 yapınca satır sayısı 1 artıyor. O YÜZDEN M+1 DEDİK
colsum[0] = (int*)calloc(n, sizeof(int)); // n tane sütunun ilk satırı 0 olsun
for(i=0;i<m;++i){
    colsum[i+1] = (int*)malloc(n*sizeof(int)); // Zaten i=0 full sıfır, şimdi 1. satırdan itibaren sağa doğru zemin açıyoruz, n sütun için n tane yer, buraya sayı (int) gelecek
    for(int j=0;j<n;++j){
        colsum[i+1][j] = colsum[i][j] + grid[i][j];
    }
}
int maxK = (m < n) ? m : n; // küçük olana göre blok genişliğini EN BÜYÜKTEN başlatıyoruz, soru bize en büyük sorduğu için dıştan başlamalıyız
for(int k=maxK; k>=2;k--){
    for(int i=0;i<=m-k;++i){ // m-k ifadesi gittikçe (k--) büyüyor, yani i daha aşağılara gidebilir, DAHA KÜÇÜK BLOKLARA BAKABİLİR
        for(int j=0;j<=n-k;++j){
            if(isMagic(grid,rowsum,colsum,i,j,k)) return k; // Döndürdüğümüz değer k. Olduğunca en büyük k ile bitiriyoruz
        }
    }
}
return 1;
}