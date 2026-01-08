#include <stdio.h>
// LeetCode 274. soru ->Soruyu anladım ama anlatamıyorum. En yakın h = dizi[i] ? >=h gibi bişi :D
int main () {
int i,j,N,dizi[50],temp;
printf("Dizinizin eleman adedini giriniz: ");
scanf("%d", &N);
printf("Dizinizi giriniz: ");
for(i=0;i<N;i++){
    scanf("%d", &dizi[i]);
}
for(i=0;i<N-1;i++){
    for(j=i+1;j<N;j++){
        if(dizi[j] > dizi[i]){ //Büyükten küçüğe sıraladıktan sonra sıralarını kontrol edeceğiz. dizi[i] < i+1 ise zincir kırılacak
            temp = dizi[j];
            dizi[j] = dizi[i];
            dizi[i] = temp;
        }
    }
}
i=0;
while(dizi[i] >= i+1){
    i++;
}
printf("%d", i);
return 0;

}