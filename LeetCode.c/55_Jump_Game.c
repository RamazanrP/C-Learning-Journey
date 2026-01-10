#include <stdio.h> 
// LeetCode 55.soru -> indis 0'dan başlıyoruz. Değerimiz veya daha azı kadar istediğimiz index'e gidip sona ulaşmaya çalışıyoz
int main() {
int i,j,N,dizi[50],maxkonum=0;
printf("Dizinizin eleman adedini giriniz: ");
scanf("%d", &N);
printf("Dizinizi giriniz: ");
for(i=0;i<N;i++){
    scanf("%d", &dizi[i]);
}
if (N == 1) {
    printf("true");
    return 0;
}
for(i=0;i<N;i++){
    if(i > maxkonum ){ //Daha buraya bile gelemiyorsak kodu bitirelim
        printf("false");
        return 0;
    }
    if(dizi[i]+i > maxkonum){ //Daha ileriyi bulursak güncelleyelim.
        maxkonum = dizi[i]+i;
    }
    if(maxkonum >= N-1) { // Bu if'i maxkonum atandığı yerde yapmak yerine her zaman yapmalıyız.
        printf("true");   // [0] için normalde buradayken kod bitiyor ama yukarıya girmediği için false vermemeli!
    }
}
printf("false");
return 0;
}