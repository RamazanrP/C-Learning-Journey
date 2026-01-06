#include <stdio.h>

int main (){
int n;
int matris[50][50];
int i,j,k;
int carpim[50][50];
int toplam=0;
printf("Kare Matrisin boyutlarini giriniz: ");
scanf("%d", &n);
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        scanf("%d", &matris[i][j]);
    }
}
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        toplam=0;//toplam ile işlem yapmadan her toplam işlemi öncesi sıfırladık
        for(k=0;k<n;k++){
            toplam= toplam+ (matris[i][k]* matris[k][j]); //k burada satırı sabit tutup satırları gezecek, diğerinde de tam tersini yapacak
        }
        carpim[i][j]= toplam;
    }
}
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        printf("%d ", carpim[i][j]);
    }
    printf("\n");
}
}