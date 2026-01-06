#include <stdio.h>
/** Birbirini takip eden sayılar arasında aşağıdaki 2 kuraldan herhangi biri olduğu bilinen bir dizinin ilk 3 elemanı verildiğinde, 4. elemanı bulan algoritmayı çiziniz.
1.kural: A(N+1)=A(N)*X
2.kural: A(N+1)=A(N)+X
*/
int main () {
int a,b,i;
int dizi[3];
int eleman4;
printf("Dizinizin ilk 3 elemanini giriniz: ");
for(i=0;i<3;i++){
    scanf("%d", &dizi[i]);
}
a=dizi[2]-dizi[1];
b=dizi[1]-dizi[0];
if (a==b){
    eleman4= dizi[2]-dizi[1]+dizi[2];
} else{
    eleman4= (dizi[2]/dizi[1])* dizi[2];
}
printf("Dizinizin 4. elemani %d", eleman4);
}