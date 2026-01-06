#include <stdio.h>

int main (){
int i,j;
int dizi[20];
int x;
int n;
printf("eleman sayinizi giriniz <20 ");
scanf("%d", &n);
printf("Sirali olan dizinizi girin ");
for(i=0;i<n;i++){
    scanf("%d", &dizi[i]);
}
printf("eklemek istediginiz sayiyi giriniz ");
scanf("%d", &x);
i=0;// i yi manuel 0 lamak önemli, for gibi düşünme while'ı
while (i<n && dizi[i]<x)// olur da dizi biterse while şart kısmını soldan okumaya başladığı için önce i<n şartı konmalı, dizi n ye bakılmaması için
{
    i++;
} 
for(j=n;j>i;j--){ //Eğer yukarda i<=n deseydik buradaki dizi[j] aslında dizide olmayan bir yerden veri çekerdi
    dizi[j]=dizi[j-1];
}
dizi[i]=x;// i+1 değil de i dedik çünkü zaten dizi i bizden büyük olan ilk yer, direkt dizi i ye yerleştirmeliyiz
for(i=0;i<=n;i++){ //yazdırırken i küçük eşit dedik çünkü eleman sayısı bir arttı
    printf("%d ", dizi[i]);
}
}