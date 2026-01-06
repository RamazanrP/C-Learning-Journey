#include <stdio.h>
/*Kullanıcının girdiği N satır, M sütunlu ve sadece 1 ve -1’lerdan
oluşan bir matrisin birbirine en çok benzeyen 2 satırının indislerini bulan
fonksiyonun algoritmasını çiziniz. Benzerlik, aynı sütundaki ikisi de aynı
olan eleman sayısının M’e oranıdır.*/
int main () {
int i,j,k,top,N,M,indi,indj;
int matris[20][20];
float max=0,oran;
printf("Matrisin boyutlarini giriniz: ");
scanf("%d %d", &N, &M);
printf("1 ve -1'den olusan matrisinizi giriniz: ");
for(i=0;i<N;i++){
    for(j=0;j<M;j++){
        scanf("%d", &matris[i][j]);
    }
}
for(i=0;i<N-1;i++){
    for(j=i+1;j<N;j++){ //j'yi 1'den başlatmak yerine i'nin sonrasından başlat
        top=0;
        for(k=0;k<M;k++){ //i ve j satırları, k ise sütunları geziyor
            top=top+ ((matris[i][k]*matris[j][k]) +1)/2; //HARİKA
        }
        oran= (float)top/M; //C'de iki tam sayının bölümü tam sayı olarak alınır!!!
        if(oran>max){
            max=oran;
            indi=i+1;
            indj=j+1;
        }
    }
}
printf("Birbirine en cok benzeyen satirlar %d. ve %d. satirlar", indi,indj);
printf("Bu satirlarin benzerlik orani: %.2f", max); //max'ın float olduğunu unutma %f diyeceğiz
}