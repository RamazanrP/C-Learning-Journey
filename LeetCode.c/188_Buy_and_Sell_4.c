#include <limits.h>
#include <stdlib.h>
int maxProfit(int k, int* prices, int pricesSize) {
// 3. versiyonda bize 2 hak vermişti en yüksek kar için. Şimdi k tane hakkımız var, bü yüzden ARRAY tutup İÇ DÖNGÜ ile bunu gezecez   
if(k==0) return 0;
int* alimlar = (int*)malloc(k*sizeof(int));
int* satislar = (int*)malloc(k*sizeof(int));
int i,j;
for(i=0;i<k;i++){
    alimlar[i] = INT_MAX,satislar[i]=0;
}
for(i=0;i<pricesSize;i++){
    int fiyat = prices[i];
    for(j=0;j<k;j++){
        int oncekinden_kar = (j==0) ? 0:satislar[j-1];
        if(fiyat-oncekinden_kar<alimlar[j]) alimlar[j] = fiyat-oncekinden_kar; // O günün fiyatını değil indirimli halini tutuyor
        if(fiyat-alimlar[j] > satislar[j]) satislar[j] = fiyat-alimlar[j];    // Satışlar için bize o günün alımı lazım, j ile iş yapıyoruz yani
    } 
}
// 30 50 50 40 80 ve k=2 olsun.
// alim[2] = MAX,MAX ve satis[2] = 0,0 && i ve j =0
// Öncekinden kar yok. 30-0 sonsuzdan küçüktür, alim[0] = 30, 30-30 büyük DEĞİLDİR 0'dan, satis[0] = 0 kaldı
// i=0,j=1 satis[0]=0 yani karımız 0, 30-0 sonsuzdan küçüktür, alim[1] = 30, 30-30 büyük DEĞİLDİR 0'dan, satis[1] = 0 kaldı
// i=1,j=0 50'yi ele aldık, karımız=0, 50 küçük DEĞİLDİR 30=alim[0]'dan. Hala en düşük alım 30, 50-30 > 0 karımız geldi. satis[0] = 50-30
//i=1,j=1 Gene 50 var, satis[0]=karımız=20, 50-20 küçük DEĞİLDİR 30=alim[1]'den, 50-alim[1](30) > 0'dan. satis[1] = 20 oldu
// i=2 j=0&1 için her şey aynı kaldı
// i=3 j=0 40'ı gördük, 40 - 0 küçük DEĞİLDİR 30'dan. Es geçtik, 40-30 büyük DEĞİLDİR 20'den(satis[0]), es geçtik
// i=3 j=1 karımız=satis[0]=20, 40-20 küçüktür 30'dan(alim[1]), alim[1] = 40 -20 oldu. ÜST ÜSTE BİRİKTİ !!!, 40-20 büyük DEĞİLDİR 20'den(satis[1])
// i=4 j=0 80-0 30'dan büyük, geç. 80-30 > 20'den. satis[0] = 50 oldu
// i=4 j=1 karımız=50 80-50 küçük DEĞİLDİR 20'den, es geçti. 80-20 > satis[1](20'den) satis[1]=60 oldu. 
int nihai_karimiz = satislar[k-1]; // Burada k kadar satma olanağı olmasa bile k-1 çalışır çünkü fiyat - alimlar[j] yani fiyat - (fiyat-kar) dediğimizde o kar daim kalır
free(alimlar),free(satislar);
return nihai_karimiz;
}