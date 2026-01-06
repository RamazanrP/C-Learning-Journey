#include <stdio.h>


int main() {
int sayi, k;
int basamak;
int yedek ;
int fact;
int sonbas;
int devamsorgu;

do {

  basamak=0;
  fact=1;
  printf("\n------------------------\n");
  printf("Sayi ve kaydirma miktarini gosteriniz:");
  scanf("%d %d" , &sayi , &k);
  yedek=sayi; 
 while (sayi>0) {
 
      basamak=basamak+1;
      fact=fact*10;
      sayi= sayi/10;
 }
 fact = fact / 10; //Burada fact'imiz sayıdan sonraki onluk kuvveti gösterdiği için bir küçüğünden başlıyoruz
 k = k % basamak;  //Boş yere dönmesin diye istenen kaydırma miktarının modunu aldık.
 for(int i=0; i<k; i++) {
    sonbas= yedek %10;  
    yedek= yedek/10;
    yedek= sonbas*fact + yedek; //En sondaki sayıyı en başa hem de onluk değerinin koruyarak saydırdık
  }
 printf("Sonuc: %d" , yedek);
 printf("\n\n Baska islem yapmak ister misiniz? Evet icin: 1 Hayir icin:0");
 scanf("%d" , &devamsorgu);

} while (devamsorgu ==1) ;
 

}