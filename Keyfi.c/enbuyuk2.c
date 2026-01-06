#include <stdio.h>
//Tek döngüde en büyük 2.yi bulma
int main () {
int maxara=-9999,maxmutlak=-9999,i,dizi[50],n;
printf("Dizinizin eleman sayisini giriniz: ");
scanf("%d", &n);
printf("Dizinizi giriniz: ");
for(i=0;i<n;i++){
    scanf("%d", &dizi[i]);
    if(dizi[i]>maxmutlak){
    maxara=maxmutlak; //Önceki kralı vezir yaptık
    maxmutlak=dizi[i];//Kral tahtına dizi[i] geçti 
    } else if(dizi[i]>maxara && dizi[i]!= maxmutlak){ //Ara değerde bir şey eğer mutlak olmasa da ara'dan büyükse
        maxara=dizi[i];                               //Vezir olarak dizi[i] deriz
    }
}
printf("Dizinizin En Buyuk 2. Elemani %d", maxara);
}


