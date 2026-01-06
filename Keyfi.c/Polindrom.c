#include <stdio.h>

int main() {
int sayi;
scanf("%d" , &sayi);
int yedek=sayi;
int tersi=0;
while (sayi>0) {
 tersi= tersi*10 + (sayi% 10); //Sayıyı 10'a bölüp son basamağı aldık. Bu alınan son basamakları gitiikçe büyüteceğiz
 sayi= sayi / 10;
}
 if (tersi==yedek) {
printf("Sayiniz polindrom");
}
else {
    printf("Sayiniz polindrom degil");
}

}