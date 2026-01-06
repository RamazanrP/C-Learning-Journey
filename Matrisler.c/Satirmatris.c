#include <stdio.h>

int main (){
int i,j;
int n,m;
int matris[50][50];
printf("Matrisinizin boyutlarini giriniz: ");
scanf("%d %d", &n,&m);
for(i=0;i<n;i++){
    for(j=0;j<m;j++){
        scanf("%d", &matris[i][j]);
    }
}
for(i=1;i<n;i++){
    for(j=0;j<m-1;j++){
        matris[i][j]=matris[i-1][j+1];
    }
    matris[i][m-1]=matris[i-1][0];
}
for(i=0;i<n;i++){
    for(j=0;j<m;j++){
        printf("%d", matris[i][j]);
    }
    printf("\n");
}
}