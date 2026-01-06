#include <stdio.h>

int main () {
int max;
int N;
scanf("%d", &N);
int dizi[100];
for (int i=0; i<N; i++) {
scanf("%d", &dizi[i]);

}

max = dizi[0];
for (int i=1; i<N; i++) {
    if (dizi[i]> max) {
        max= dizi[i];
    }
}

printf("%d", max); 
}