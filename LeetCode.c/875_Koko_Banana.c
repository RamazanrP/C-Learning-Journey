#include <stdio.h>
// Bir muz yığını dizisi ve h saati verilsin. h süre kadar sonra bekçiler gelecek. 1 saatte yenebilecek en az muz sayısı
int main () {
int sol,sag,mid,max=0,dizi[50],i,h,k,N,saatsayaci,temp;
printf("Dizinizin eleman adedini giriniz: ");
scanf("%d", &N);
printf("Dizinizi giriniz: ");
for(i=0;i<N;i++){
    scanf("%d", &dizi[i]);
    if(dizi[i] > max){ // Max'ı buluyoruz sağ ve k'ya ilk değeri atamak için
        max = dizi[i];
    }
}
printf("Verilen süreyi giriniz: ");
scanf("%d", &h);
sol=1,sag=max,k=max;
while(sol<=sag){
    saatsayaci=0;
    mid = sol + (sag-sol)/2;
    if(mid == 0) {sol=1; continue;} // 0'a bölünme hatası olmaması için
    for(i=0;i<N;i++){
        if(mid >= dizi[i]){ // Zaten kendisinden küçüklerde 1 kere artacak
            saatsayaci++;
        }else{
            temp = dizi[i];
            if(temp%mid != 0){ //Kalanlıysa 1 ekleyelim, değilse direkt bölümü ekliyoruz
                saatsayaci = saatsayaci+(temp/mid)+1;
            }else saatsayaci = saatsayaci+ (temp/mid);
        }   
    }
    if(saatsayaci <= h){
        k = mid;
        sag=mid-1; //Mid'i küçültmeye devam etmeliyiz, zaten eşit olunca da k = mid olacak, eşitlik için özel else açmaya gerek yok
    }else{
        sol=mid+1;
    }
}
printf("%d", k);
return 0;
}