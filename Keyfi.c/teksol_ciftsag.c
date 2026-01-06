#include <stdio.h>

int main () {
int i,j,N,dizi[50],temp;
printf("Dizinizin eleman sayisini giriniz:");
scanf("%d", &N);
printf("Dizinizi giriniz: ");
for(i=0;i<N;i++){
    scanf("%d", &dizi[i]);
}
for(i=0;i<N-1;i++){
    for(j=0;j<N-1-i;j++){
        if(dizi[j]%2 == 0 && dizi[j+1]%2 != 0){
            temp = dizi[j];
            dizi[j] = dizi[j+1];
            dizi[j+1] = temp;
        }
    }
}
for(i=0;i<N;i++){
    printf("%d ", dizi[i]);
}
}