#include <stdio.h>
#include <stdlib.h>
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
if (matrixSize == 0 || *matrixColSize == 0) {
    *returnSize = 0;
    return NULL;
}    
int Total = matrixSize * (*matrixColSize); // Toplam eleman adedi hesabı
int* sonuc = (int*)malloc(Total*sizeof(int)); // Sonuç dizisi için yer ayırdık
int satir = matrixSize, sutun = *matrixColSize; // Sütunu bulmak için * ile zarfı açtık
int ust=0,alt=satir-1,sag= sutun-1,sol=0,k=0; //Sonucu dizmek için k'yı kullanıcaz ve her for içinde manuel arttırmalıyız!
while(ust<=alt && sol<=sag){
    for(int j=sol;j<=sag;j++){
        sonuc[k] = matrix[ust][j];
        k++;
    }
    ust++; // Yukarı ile işimiz bitti, arttırdık. Diğerleri de böyle olacak
    for(int j=ust;j<=alt;j++){
       sonuc[k] = matrix[j][sag];
       k++;
    }
    sag--;
    if(ust<=alt){ // sola ve aşağı gitmede sorun yok ama sola ve yukarıya çıkarken tekrara düşmemek için if zorunluluk
        for(int j=sag;j>=sol;j--){
            sonuc[k] = matrix[alt][j];
            k++;
        }
        alt--; // alt ve sol'u if'in içinde değiştirmeliyiz ki if'e girmeme durumunda bunlara bir şey olmasın. 
    }
    if(sol<=sag){
        for(int j=alt;j>=ust;j--){
            sonuc[k] = matrix[j][sol];
            k++;
        }
        sol++;
    }
}
*returnSize = Total;
return sonuc;
}   