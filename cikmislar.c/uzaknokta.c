#include <stdio.h>
// tek boyutta verilen dizi için en uzak iki noktanın indislerini TEK DÖNGÜ İLE bulan kod
int main   () {
int i,n,max,min,minyer,maxyer;
int dizi[20];
printf("dizinin boyutunu giriniz: ");
scanf("%d", &n);
printf("Dizinizi giriniz: ");
for(i=0;i<n;i++){
    scanf("%d", &dizi[i]);
}
max=dizi[0];
min=dizi[0];
for(i=1;i<n;i++){
    if(dizi[i]>max){
        max=dizi[i];
        maxyer=i;
    } else if (dizi[i]<min){
        min=dizi[i];
        minyer=i;
    }
}
printf("dizinizin en uzak iki noktasi %d. ve %d. elemanlar ", (maxyer+1), (minyer+1));
}