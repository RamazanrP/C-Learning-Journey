#include <stdio.h>
//LeetCode 75. am sory he -> tek geçişte o(N)'de diziyi sıralama kodu
int main () {
int i,dizi[50],low,high,guncel,N,temp;
printf("Dizinizin eleman adedini giriniz: ");
scanf("%d", &N);
printf("Dizinizi giriniz:" );
for(i=0;i<N;i++){
    scanf("%d", &dizi[i]);
}
low=0; // 0 görünce low ile temp uygulayacaz
guncel=0; //Kendisi ve öncesini (0 ve 1) gördüğü sürece artacak. 
high=N-1; //2'ler high'den başlayıp dizilecek ama dikkat high tarafını bilmiyoruz, guncel'i ARTTIRMAMALIYIZ
while(guncel <= high){
    if(dizi[guncel] == 0){
        temp = dizi[guncel];
        dizi[guncel] = dizi[low];
        dizi[low] = temp;
        low++,guncel++; // Atamadan sonra arttıralım
    }else if(dizi[guncel] == 1){ // Atama yapmıyoruz çümkü zaten 1 ortada kalmasını istediğimiz şey, sadece guncel artacak
        guncel++;
    }else{
        temp = dizi[guncel];
        dizi[guncel] = dizi[high];
        dizi[high] = temp;
        high--; // Guncel artarsa bilinmeyen yerden veri  çekmiş oluruz. Guncel öyle kalacak.
    }
}
for(i=0;i<N;i++){
    printf("%d ", dizi[i]);
}
return 0;
}