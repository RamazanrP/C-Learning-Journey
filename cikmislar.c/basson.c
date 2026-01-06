#include <stdio.h>
//input:   5 7 2 9 5 3 8 6
//output:  2 8 6 3 5 9 7 5 
//benimki: 2 8 6 5 9 5 3 7
int main (){
int i,n;
int dizi[50];
int temp;
int k=0;
printf("dizinin eleman sayisini giriniz: ");
scanf("%d", &n);
int m=n-1;
printf("dizinizi giriniz: ");
for(i=0;i<n;i++){
    scanf("%d", &dizi[i]);
}
for(i=0;i<n;i++){
    if(dizi[i]%2==0){
        temp= dizi[k];
        dizi[k]=dizi[i];
        dizi[i]= temp;
        k++;
    }
}
for(i=0;i<n;i++){
    if(dizi[i]%2!=0){
        temp= dizi[m];
        dizi[m]=dizi[i];
        dizi[i]=temp;
        m--;
    }
}
for(i=0;i<n;i++){
    printf("%d ", dizi[i]);
}
}