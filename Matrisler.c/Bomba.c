#include <stdio.h>
//5x5 matriste bir bomba konumu verilecek. gücü 1 olacak şekilde etrafını patlatıp üsttekiler aşağı düşecek
int main () {
int guc=1,i,j,k,bi,bj,matris[10][10],m,n;
printf("Matrisinizin boyutlarini giriniz: ");
scanf("%d %d", &n, &m);
printf("Matrisinizi doldurunuz: ");
for(i=0;i<n;i++){
    for(j=0;j<m;j++){
        scanf("%d", &matris[i][j]);
    }
}
printf("Bombanin konumunu giriniz: ");
scanf("%d %d", &bi,&bj);
while(i>=0 && i<=n && j>=0 && j<=m){
    for(i=bi-1;i<=bi+1;i++){
        for(j=bj-1;j<=bj+1;j++){
            matris[i][j]=matris[i-3][j];
        }
    }
}
j=0; //Ne olur ne olmaz diye yazdım
for(i=0;i<3;i++){
    while(j>=0 && j<= m){
        for(j=bj-1;j<=bj+1;j++){
            matris[i][j]= -1;
        }
    }
}
for(i=0;i<n;i++){
    for(j=0;j<m;j++){
        printf("%d", matris[i][j]);
    }
    printf("\n");
}
}