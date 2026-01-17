#include <stdbool.h>
#include <stdio.h>
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
if (matrixSize == 0 || *matrixColSize == 0) return false;
int sutun = *matrixColSize, satir = matrixSize;
int i=0, j=sutun-1;
int aranan = target;
while(i<satir && j>=0){
    if(matrix[i][j] == aranan) return true;
    if(matrix[i][j] > aranan){
        j--;
    }else{
        i++;
    }
}
if(i==satir || j<0){
    return false;
}
}