int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
int Total = matSize*(*matColSize);
int* sonuc = (int*)malloc(Total*sizeof(int));
int satir = matSize,sutun = *matColSize;
int i=0,j=0,yon=1,k=0; // else-if'lere girdiği gibi sonuc'a atama yapmalıyız ve her yerde k'yı arttırmayı unutma!
while(k<Total){
    if(yon == 1){
        if(j == sutun-1){ // Yon=1 iken j, yon=0 iken i bizim için önemli, yoksa matris dışına çıkarız
            sonuc[k] = mat[i][j];
            i++,k++;
            yon=0;
        }else if(i == 0){
            sonuc[k] = mat[i][j];
            j++,k++;
            yon=0;
        }else{
            sonuc[k] = mat[i][j];
            k++,i--,j++;
        }
    }else{
        if(i==satir-1){
            sonuc[k] = mat[i][j];
            k++,j++;
            yon=1;
        }else if(j==0){
            sonuc[k] = mat[i][j];
            i++,k++;
            yon=1;
        }else{
            sonuc[k] = mat[i][j];
            k++,i++,j--;
        }
    }
}
*returnSize = Total;
return sonuc;
}