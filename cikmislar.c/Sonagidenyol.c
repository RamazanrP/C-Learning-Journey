#include <stdio.h>
// İlk sütunda 0'dan farklı her sayı bir yolu gösteriyor. Son sütuna kadar giden yolun kodu ve uzunluğunu yazdıran kod
int main () {
int i,j,k,N,M,matris[20][20],sonsutun=0,guncel,uzunluk,yolvarmi;
printf("Matrisinizin boyutlarini giriniz: ");
scanf("%d %d", &N, &M);
printf("Matrisinizi giriniz:");
for(i=0;i<N;i++){
    for(j=0;j<M;j++){
        scanf("%d", &matris[i][j]);
    }
}
for(k=0;k<N;k++){
    i=k,j=0,yolvarmi=1,uzunluk=1;
    if(matris[k][0] != 0){
        guncel=matris[k][0]; //Bu günceli hiç değiştirmememiz lazım
    while(yolvarmi == 1 && i>=0 && i<N && j>=0 && j<M-1){
        matris[i][j]=0; //Her seferinde önceki/geldiğimiz/ulaşabildiğimiz konumu 0'lıyoruz.Sonra bunun olası senaryolarına if'le bakcaz
        if(j<M-1 && matris[i][j+1] == guncel){ //Önce daima i ve j sınırlarını kontrol etmeliyiz, Sonra denkliğe bakalım!
            j++;
        }else if(i>0 && matris[i-1][j] == guncel){
            i--;
        }else if(i<N-1 && matris[i+1][j] == guncel){
            i++;
        }else if(j>0 && matris[i][j-1] == guncel){
            j--;
        }else if(i>0 && j<M-1 && matris[i-1][j+1] == guncel){
            i--,j++;
        }else if(i<N-1 && j<M-1 && matris[i+1][j+1] == guncel){
            i++,j++;
        }else if(i>0 && j>0 && matris[i-1][j-1] == guncel){
            i--,j--;
        }else if(i<N-1 && j>0 && matris[i+1][j-1] == guncel){
            i++,j--;
        }else{
            yolvarmi = 0;
        }
        if(yolvarmi){
            uzunluk++; //Her if'in içinde arttırmaktansa tek sorguda arttıralım
        }
    }
    if(j == M-1 && yolvarmi == 1){ //Tek sütun girilmesi ihtimaline karşı yolvarmi ? 1
        printf("Yolunuz: %d Yol Uzunlugu: %d", guncel, uzunluk);
    }
    }
}
return 0;
}