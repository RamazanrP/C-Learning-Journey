#include <stdio.h>

int main () {
int sayi;
int sonuc=0;
int bas;
scanf("%d" , &sayi);
int yedek=sayi;

while(sayi>0){
    bas= sayi % 10;
    sonuc= sonuc + (bas*bas*bas);
    sayi= sayi/10;
}
 if (sonuc==yedek){
 printf("Sayiniz Armstrong");
 }
 else {
    printf("Armstrong degil");
 }
}