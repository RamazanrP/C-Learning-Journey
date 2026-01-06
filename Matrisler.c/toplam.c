#include <stdio.h>

int main (){
int m[5][5];
int satir,sutun;
int toplam=0;
int i,j;
printf("matrisinizi olusturun ");
for(i=0;i<5;i++){
    for(j=0;j<5;j++){
        scanf("%d", &m[5][5]);
    }
}
printf("eleman için konum giriniz ");
scanf("%d %d", &satir, &sutun);
if(satir>0){//matrisi değil de direk satır ve sütun değerini kontrol et ve 0. indekse DİKKAT
    toplam=toplam+m[satir-1][sutun];
} 
if(satir+1<5){
    toplam=toplam+m[satir+1][sutun];
}
if(sutun+1<5){
    toplam= toplam+m[satir][sutun+1];
}
if(sutun>0){
    toplam=toplam+m[satir][sutun-1];
}
printf("verilen konumun etrafindaki sayilarin toplami: %d", toplam);
}