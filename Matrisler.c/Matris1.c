#include <stdio.h>

int main () {
int N,M;
int gorulen=0;
int max=0;
printf("Sehrin boyutlarini giriniz (satirxsutun) ");
scanf("%d %d", &N, &M);
int sehir[50][50];
printf("Yukseklikleri giriniz ");
for(int i=0; i<N;i++) {
    for(int j=0; j<M; j++) {
        scanf("%d", &sehir[i][j]);
    }
}

for(int i=0; i<N; i++) {
    max=0;
    gorulen=0;
    for(int j= M-1; j>=0; j--){
        if (sehir[i][j-1]> max) {
            gorulen++;
            max= sehir[i][j-1];
        }
 }
printf("%d. satir gorulen bina sayisi: %d ", i+1, gorulen);
}
for(int j=0; j<M; j++) {
    max=0;
    gorulen=0;
    for(int i=N-1; i>=0; i--){
       if(sehir[i][j]> max){
            max=sehir[i][j];
            gorulen++;
        }
    }
printf("%d. sutun gorulen bina sayisi: %d ", j+1, gorulen);
}
}

