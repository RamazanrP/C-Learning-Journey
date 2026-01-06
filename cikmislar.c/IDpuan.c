#include <stdio.h>
/* Kullanıcının girdiği, içinde 5 adet yarışmacıya ait id ve 4 er hakemin verdiği puanların yer aldığı 
2*20’lik matristen en fazla puanı alanın id’sini tek döngü ile bulan algoritmayı çiziniz.
İlk satırda ID, ikinci satırda ise puanlar yer almaktadır.*/
int main () {
int i,k,max,id;
int dizi[40];
int hist[5];
printf("2x20 matriste ilk 20 ID son 20 puan olacak sekilde giriniz:");
for(i=0;i<40;i++){
    scanf("%d", &dizi[i]); //direkt 40 sayı olarak çektik
}
for(i=0;i<5;i++){
    hist[i]=0;
}
for(i=0;i<20;i++){
    hist[dizi[i]-1]= hist[dizi[i]-1] + dizi[i+20]; //bu -1 leri unutursak hist[5]'e giderdi
}
max=0;
for(i=0;i<5;i++){
    if(hist[i]>max){
        max=hist[i];
        id= i+1; //burada da +1'i unutmamak lazım
    }
}
printf("En cok puan alan ID: %d", id);
}