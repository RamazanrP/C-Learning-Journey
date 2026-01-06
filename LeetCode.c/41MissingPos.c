#include <stdio.h>
//Leetcode 41. soru --> Array'de olmayan en küçük pozitif sayı
long long i,N,dizi[100000];
int main () {
int birvarmi=1,temp;
printf("Dizinizin eleman sayisini giriniz: ");
scanf("%lld", &N);
for(i=0;i<N;i++){
    scanf("%lld", &dizi[i]);
    if(dizi[i] == 1){
        birvarmi = 0;
    }
}
if(birvarmi ==  1){
    printf("%d", 1); //Hiç bir yoksa direkt en küçük poz 1'dir deyip çıkarız
    return 0;
}else{
    for(i=0;i<N;i++){
        while(dizi[i]>0 &&  dizi[i] != i+1 && dizi[i]<= N && dizi[i] != dizi[dizi[i]-1]){ //<=N, eğer 5 varsa ve N=5 ise 5-1=N-1 !!!
            temp = dizi[i];
            dizi[i] = dizi[dizi[i]-1];
            dizi[temp-1] = temp; //Burada dizi[dizi[i]-1] yazamazdık çünkü dizi[i]'yi değiştirdik!
        }
    }
}
for(i=0;i<N;i++){
    if(dizi[i]>0 && dizi[i] != i+1){
        printf("%lld", i+1);
        return 0; //Bozuk sayı-indis bulursak hemen yazdırıp bitirsin
    }
}
printf("%lld", N+1);
// En sonda sıralı ve full pozitif bir dizi oluşmuşsa for'daki if hiç çalışmaz! 
//Böyle olmuşsa cevap N+1'dir. Örn: dizi[1,2,3] ise cevap 4'tür.
return 0;
}