#include <stdio.h>
//2 Kere en büyüğü bulup sıfıra eşitledim, sonraki en büyük, dizinin en büyüğü oluyordu
int main () { 
int yer;
int dizi[20];
int max=0;
int i,n;
printf("eleman sayisini giriniz: ");
scanf("%d", &n);
if(n<3){
    printf("elaman sayisi 3'ten buyuk olmalidir!");
    scanf("%d", &n);
}
printf("Dizinizi giriniz: ");
for(i=0;i<n;i++){
    scanf("%d", &dizi[i]);
}
max=dizi[0];         //Önce ilk elemanı max seçtim
for(i=1;i<n;i++){
    if(dizi[i]>max){
        max=dizi[i];
        yer=i;
    }
}
dizi[yer]=0; //En büyük 0landı
max=dizi[0]; //yeni for için en büyüğü ilk eleman seçtim
yer=0;       //Olur da en büyük, ilk terim olursa diye yer=0 dedim (en büyük, ilk terim olursa for'a hiç girmez)!!!
for(i=1;i<n;i++){
    if(dizi[i]>max){
        max=dizi[i];
        yer=i;
    }
}
dizi[yer]=0;
max=dizi[0];
yer=0;
for(i=1;i<n;i++){
    if(dizi[i]>max){
        max=dizi[i];
        yer=i;
    }
}
printf("dizinizin en buyuk 3. degeri ve yeri: %d %d", max, yer+1);
}