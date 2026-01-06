#include <stdio.h>
// Kullanıcının girdiği N*N lik bir matrisin elemanlarını N*N elemanlı bir dizinin içine sırayla tek döngü ile yazan kod
int main () {
int i,j,k,N;
int matris[10][10];
int dizi[100];
printf("NxN'lik matrisinizin boyutunu (N) giriniz:");
scanf("%d", &N);
printf("Matrisinizi doldurun: ");
for(i=0;i<N;i++){
    for(j=0;j<N;j++){
        scanf("%d", &matris[i][j]);
    }
}
for(k=0;k<N*N;k++){ //Talha => k= i*n +j de oluyor linnerleştirme için
    i= k/N;//3x3 lük matris için ilk satır 0/3=1/3=2/3=0 çıkacak. İlk satırı ilk 3 doğrusal hizaya aldık
    j= k%N;//Aynı matris için 0%3 =0 ama 1%3=1 2/3 de 2. yani i sabit kalırken j artıyor
    dizi[k]= matris[i][j];
}
printf("Matrisinizin diziye donmus hali: \n");
for(i=0;i<N*N;i++){
    printf("%d", dizi[i]);
}
}