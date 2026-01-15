#include <stdio.h>
// Ağırlık dizisinin SIRASINI BOZMADAN minimim taşıma kapasitesi ile istenen günde ağırlıkları taşıma kodu
int main () {
int mid,N,i,agirlik[50],toplam,gun,mincap,maxcap=0,gunsayaci,kapasite;
printf("Dizinizin eleman adedini giriniz: ");
scanf("%d", &N);
printf("Dizinizi giriniz: ");
for(i=0;i<N;i++){
    scanf("%d", &agirlik[i]);
    if(agirlik[i] > mincap){ // Minimum değeri bulmak için en büyük yükü buluyoruz ve atama yapıyoruz. Yoksa o yükü taşıyamazdık
        mincap = agirlik[i];
    }
    maxcap+=agirlik[i];      // Maksimum değer de toplam ağırlık olur, tek günde toplarız.
}
printf("İstenen gun sayisini giriniz: ");
scanf("%d", &gun);
kapasite = maxcap;
while(mincap<=maxcap){
    mid = mincap + (maxcap-mincap)/2;
    toplam=0,gunsayaci=1; // gunsayacini 1'den başlattık çünkü bizim FİZİKSEL olan gemi sayımızı tutuyor. İlk gün 1.gemiyi dolduruyoz
    for(i=0;i<N;i++){
        if(toplam + agirlik[i] > mid){ //Yeni gelen yük mid'i aşıyorsa burada kes, günü arttır, bir sonraki gemi gelsin
        gunsayaci++;
        toplam = agirlik[i]; //Bir sonraki gün, yeni gelen gemiye bu arta kalan değeri yerleştircez
    }else{
        toplam += agirlik[i]; // Gemi alabiliyorsa almaya devam etsin
    }
    }
    
    if(gunsayaci <= gun){
        kapasite = mid; // Uygun bir kapasite bulunca mid'i atayalım. İşlemler mid'e göre ilerliyor çünkü
        maxcap=mid-1;   //Yükleri çok çabuk götürdüysek max'ı azaltalım
    }else{
        mincap=mid+1;   //Çok hızlı götürdüysek min'i büyütelim, daha çok yük alalım
    }
}
printf("%d", kapasite);
return 0;
}