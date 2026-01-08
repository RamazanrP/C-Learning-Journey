#include <stdio.h>
#include <stdlib.h> //abs için lazım
// 16.soru-> verilen diziden 3 sayının toplamının istenen target'a en yakın halini (toplamı) yazdıran kod
int main () {
int i,j,temp,gunceltoplam,dizi[50],sag,sol,target,N,enyakintoplam;
printf("Dizinizin eleman adedini ve target'i giriniz giriniz: ");
scanf("%d %d", &N, &target);
printf("Dizinizi giriniz: ");
for(i=0;i<N;i++){
    scanf("%d", &dizi[i]);
}
for(i=0;i<N-1;i++){
    for(j=i+1;j<N;j++){
        if(dizi[j] < dizi[i]){ //Küçükten büyüğe sıraladık
            temp = dizi[j];
            dizi[j] = dizi[i];
            dizi[i] = temp;
        }
    }
}
enyakintoplam = dizi[0]+dizi[1]+dizi[2]; // Önce ilk 3'ü en yakın kabul edelim
for(i=0;i<N-2;i++){
    sol = i+1, sag = N-1;
    while(sol<sag){
    gunceltoplam = dizi[i]+dizi[sol]+dizi[sag]; //Değerleri çektiğimiz gibi if'e sokalım. Sonra sol-sag değiştiririz
    if(abs(gunceltoplam - target) < abs(enyakintoplam - target)){
        enyakintoplam = gunceltoplam; //Aradaki fark en azsa enyakintoplam'a atayalım
    }
    if(gunceltoplam < target){
        sol++;
    }else if(gunceltoplam > target){
        sag--;
    }else{
        printf("%d", gunceltoplam); //Gunceltoplam = target durumu en iyi durum olduğu için bunu direkt yazdırırız
        return 0;
    }
    }

    
}

printf("%d", enyakintoplam);
}