#include <stdbool.h>
// Verilen target matrisine 90 derece döndürme ile ulaşabilir miyiz?
bool isSame(int** mat, int** target, int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j] != target[i][j]){
                return false;
            }
        }
    }
    return true;
}
bool findRotation(int** mat, int matSize, int* matColSize, int** target, int targetSize, int* targetColSize) {
if(matSize != targetSize || matColSize[0] != targetColSize[0]) return false;
int m=matSize; 
int n=matColSize[0];
for(int k=0;k<3;k++){ // 3 kere çevirmek yeterli. 4. çevirme zaten başlangıç ile aynısını verecekti
    if(isSame(mat,target,m,n)) return true; // İlk başta aynı mı kontrol edelim
    for(int i=0;i<m;i++){
        for(int j=i+1;j<n;j++){ // Transpozunu alıp satırları ters çevireceğiz. 90 derece dönmüş olacak
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n/2;j++){
            int temp = mat[i][n-1-j];
            mat[i][n-1-j] = mat[i][j];
            mat[i][j] = temp;
        }
    }
}
return false;
}