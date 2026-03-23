#include <limits.h>
// k*k alt matriste bulunan sayıların mutlakca farkının en küçük değerinin tutulduğu matrisi istiyor (alt matrisimiz bir kare sayılacak)
int sirala(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}
int** minAbsDiff(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes){
int m = gridSize,n = gridColSize[0];
int satir = m-k+1; // k*k için nereye kadar gidebiliriz?
int sutun = n-k+1;
*returnSize = satir;
*returnColumnSizes = (int*)malloc(sizeof(int)*satir);
int** sonuc = (int**)malloc(sizeof(int*)*satir);
int* temp = (int*)malloc(sizeof(int)*(k*k)); // k*k altmatrisimizdeki sayıları sıralamak için kaydedeceğimiz dizi
for(int i=0;i<satir;i++){
    sonuc[i] = (int*)malloc(sizeof(int)*sutun);
    (*returnColumnSizes)[i] = sutun;
    for(int j=0;j<sutun;j++){
        int index=0;
        for(int x=i;x<i+k;x++){ // Alt matrise girdik, içinde gezelim
            for(int y=j;y<j+k;y++){
                temp[index++] = grid[x][y];
            }
        }
        qsort(temp, k*k, sizeof(int), sirala);
        int min_fark = INT_MAX;
        for(int t=1;t<k*k;t++){
            if(temp[t] != temp[t-1]){
                if(min_fark > temp[t] - temp[t-1]){
                    min_fark = temp[t] - temp[t-1];
                }
            }
        }
        if(min_fark != INT_MAX){
            sonuc[i][j] = min_fark;
        }else{
            sonuc[i][j] = 0;
        }
    }
}
free(temp);
return sonuc;
}