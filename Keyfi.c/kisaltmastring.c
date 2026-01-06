#include <stdio.h>
#include <string.h> //String kütüphanesini eklemeyi unutma
//aaabbbbccd a3b4c2d1 gösteren kod
int main () {
int sayac,i=0;
char harfler[50];
printf("Stringinizi giriniz: ");
scanf("%s", harfler);           //Böyle alınabilir 
while (harfler[i]!='\0'){
    sayac=1;                    // i ile i+1 aynı değilse ve harf sadece 1 kere yazılmışsa harfin bir olduğunu göstermek için 1'den başlattık
    while(harfler[i]==harfler[i+1]){
        sayac+=1;
        i++;                    // Hem içteki döngüyü arttırdık sayacı bulmak için
    } 
    printf("%c%d", harfler[i], sayac);
    i= i+sayac;                 // i'yi sayac kadar ileri götürmeliyiz ana stringte!!!
}
}