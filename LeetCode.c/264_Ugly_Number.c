#include <stdio.h>
// LeetCode 264. soru -> sadece 2 3 ve 5 ile oluşturulan sayı dizisinde n. elemanı yazdıran kod (dizi[0]=1)
long long dizi[2000],enkucuk,aday2,aday3,aday5;
int main () {
int i,N,i2,i3,i5;
printf("Kacinci elemani görmek istiyorsunuz:");
scanf("%d", &N);
dizi[0] = 1; //Kural gereği
i2=0,i3=0,i5=0; //Çöp değer olmaması için 0'ladık en başta
for(i=1;i<N;i++){
    aday2 = dizi[i2]*2;
    aday3 = dizi[i3]*3;
    aday5 = dizi[i5]*5;
    enkucuk = aday2; // Çoğu kez aday2 küçük olur, o yüzden 2 if yeter bize
    if(aday3 < enkucuk) enkucuk = aday3;
    if(aday5 < enkucuk) enkucuk = aday5;
    
    dizi[i] = enkucuk; // Giderek diziyi dolduruyoruz

    if(enkucuk == aday2) i2++; //Burada if else açmadık çünkü mesela 6 dersek hem 2 hem 3 artması lazımdı
    if(enkucuk == aday3) i3++; // 2*3 de 3*2 de 6 olduğu için ikisi de artmalıydı
    if(enkucuk == aday5) i5++;
}
printf("%lld", dizi[N-1]);
}