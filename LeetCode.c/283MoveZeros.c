#include <stdio.h>
// 283. soru -> Başka bir Array'e kopyalamadan verilen arraydeki 0'dan farklı sayıları sırasıyla yazdırıp 0'ları sona koyan kod
int main () {
int i,yerlestir=0,N,dizi[20],sifirsayaci;
printf("Dizinizin eleman adedini giriniz: ");
scanf("%d", &N);
printf("Dizinizi giriniz: ");
for(i=0;i<N;i++){
    scanf("%d", &dizi[i]); //Burada scanfle çekerken boşuna saymaya gerek yok. Yerlestir onu halledecek
}
for(i=0;i<N;i++){
    if(dizi[i] != 0){ //Sıfır görmediği anda o !=0 sayıları  başa atacak. Yerlestir, 0'ların olması gereken indise kadar ilerleyecek.
        dizi[yerlestir] = dizi[i];
        yerlestir++; //Yerlestir'i başta 0'dan başlatıp burada arttırmayı UNUTMA!!!
    }
}
for(i=yerlestir;i<N;i++){ //Yerlestirden en sona kadar 0'ladık. 0 1 0 3 12 -> 1 3 12 1 3 olmuştu
    dizi[i] = 0;                                              //Şimdi 1 3 12 0 0 oldu tam istediğimiz gibi
}
for(i=0;i<N;i++){
    printf("%d ", dizi[i]);
}
return 0;
}