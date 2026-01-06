#include <stdio.h>
int n;
int x;
int main () {
scanf("%d %d", &x,&n);
float sonuc=1; //float olması önemli!!!
float terim=1;
for(int i=1; i<=n; i++) {
    terim= terim*x / i; //Tek tek pay payda hesabı yapmamak için daima önceki terimi x/i ile böldük.
    sonuc= sonuc + terim ;
}

printf("%f", sonuc);


}