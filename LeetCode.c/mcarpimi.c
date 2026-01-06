#include <stdio.h>

int main () {
int satir1,sutun1,satir2,sutun2,m1[10][10],m2[10][10];
int i,j,k,toplam=0;
int carpim[10][10];
printf("ilk matrisin satir ve sutununu giriniz: ");
scanf("%d %d", &satir1,&sutun1);
printf("ikinci matrisin satir ve sutununu giriniz: ");
scanf("%d %d", &satir2, &sutun2);
if(sutun1!=satir2){ //Böyleyse kabul etmez, else'i en aşağıya kadar çektik
    printf("Uygun degerleri giriniz!");
}else{
    for(i=0;i<satir1;i++){
        for(j=0;j<sutun1;j++){
            scanf("%d", &m1[i][j]);
        }
    }
    for(i=0;i<satir2;i++){
        for(j=0;j<sutun2;j++){
            scanf("%d", &m2[i][j]);
        }
    }

printf("Yeni Olusacak Matrisiniz %dx%d boyutunda olacaktir\n", satir1, sutun2);
for(i=0;i<satir1;i++){
    for(j=0;j<sutun2;j++){
        toplam=0; //Her yeni sütunda sıfırlanmalı
        for(k=0;k<satir2;k++){
            toplam= toplam+ m1[i][k]*m2[k][j]; //m1 için sütunları geziyor, m2 için satırlardan aşağı iniyor k'mız
        }
        carpim[i][j]=toplam;
    }
}
printf("---------Olusan Carpim Matirisiniz:------------ \n");
for(i=0;i<satir1;i++){
    for(j=0;j<sutun2;j++){
        printf("%d ", carpim[i][j]);
    }
    printf("\n");       //Şık gösterelim 
}
}
}