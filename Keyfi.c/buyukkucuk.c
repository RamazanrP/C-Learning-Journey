#include <stdio.h>

int main () {
int dizi[5];
int temp;
for (int i=0; i<5; i++){
    scanf("%d", &dizi[i]);
}
for (int i=0; i<5;i++){
    for(int j=0; j<4; j++) {
        if( dizi[j] < dizi[j+1]) {
            temp= dizi[j];
            dizi[j]= dizi[j+1];
            dizi[j+1]= temp;
        }

    }
}
for (int i=0; i<5; i++){
    printf(" %d", dizi[i]);
}
}