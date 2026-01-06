#include <stdio.h>
//sayı örüntüde varsa indisi, yok ise nereye gelmeli kodu
int main () {
int i,n,N,ilk,son,mid;
int sayilar[20];
printf("Dizinizin eleman sayisini giriniz ");
scanf("%d", &N);
printf("Sirali dizinizi giriniz: ");
for(i=0;i<N;i++){
    scanf("%d", &sayilar[i]);
}
printf("Sectiginiz sayiyi giriniz: ");          //Eğer hedefimiz en küçükse ilk hep 0 kalacak
scanf("%d", &n);                                //Eğer hedefimiz en büyükse ilk N'e kadar (son+1) gidecek
ilk=0,son=N-1;                                  // Eğer hedefimiz aradaysa ilk, hedeften BÜYÜK OLAN İLK SAYIYI gösterecek
while(son>=ilk){
    mid=ilk + (son-ilk)/2;
    if(sayilar[mid]==n){
        printf("Hedefiniz %d. indis", mid);
        return 0;
    }else if(sayilar[mid]>n){
        son=mid-1;
    }else{
        ilk=mid+1;
    }
}
printf("Hedefiniz %d. indise gelmeli", ilk);

}