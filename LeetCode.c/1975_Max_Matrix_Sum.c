// Yan yana iki sayıyı -1 ile çarpabiliriz. - sayısı tek ise eksi, istediği kadar yer değişir, çift ise bütün sayılar poizitif olabilir
#include <stdlib.h>
#include <stdio.h>
long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
long long negcounter=0,TotalSum=0,temp;
int minabsvalue;
int m=matrixSize,n=matrixColSize[0];
minabsvalue = abs(matrix[0][0]);
for(int i=0;i<m;++i) {
    for(int j=0;j<n;++j){
        if(matrix[i][j] < 0){
            temp = -1*matrix[i][j];
            TotalSum += temp;
            negcounter++;
            if(temp < minabsvalue) minabsvalue = temp;
        }else{
            TotalSum += matrix[i][j];
            if(matrix[i][j] < minabsvalue) minabsvalue = matrix[i][j];
        }
    }
}
if(negcounter%2 == 0) return TotalSum; // Çift kadarsa Total'dir
else return (TotalSum - 2*(minabsvalue)); // İki kere çıkarmak önemli, biri pozitif değeri için biri de kendisi için
}