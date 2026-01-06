#include <stdio.h>
// 2ler yayılıyor, 0lara ulaşılıyor. 1 ise engel. Bir 0'ın etrafı 1lerle kaplıysa o da -1 olacak. Engeller de -1 yazlsın. 2ler 0
int main () {
int i,j,k,N,M,matris[20][20],yazdir[20][20],bas=0,son=0,bombx[400],bomby[400];
int yeniX,yeniY,guncelX,guncelY;
int dx[]= {-1, 1, 0, 0};
int dy[]= {0, 0, -1, 1};
printf("Matrisinizin boyutlarini giriniz: ");
scanf("%d %d", &N, &M);
printf("Matrisinizi giriniz: ");
for(i=0;i<N;i++){
    for(j=0;j<M;j++){
        scanf("%d", &matris[i][j]);
        yazdir[i][j] = -1; // Önce bütün matris -1 olsun
    }
}
for(i=0;i<N;i++){
    for(j=0;j<M;j++){
        if(matris[i][j] == 2){
            yazdir[i][j] = 0;
            bombx[son]=i; //Dalgayı başlatmak için kuyruğa ekledik
            bomby[son]=j;
            son++; //Burası for ile artmıyor kendimiz arttırmayı unutmamalıyız!
        }
    }
}
while(bas<son){
    guncelX = bombx[bas];// Önce 2'lerin sonra da 1,2... dalgaların koordinatlarını tutacaz
    guncelY = bomby[bas];
    bas++;
    for(k=0;k<4;k++){
        yeniX = guncelX + dx[k];
        yeniY = guncelY + dy[k];
        if(yeniX >= 0 && yeniX < N && yeniY >=0 && yeniY < M && matris[yeniX][yeniY] != 1){
            if(yazdir[yeniX][yeniY] == -1){ //Duvardan geçmişse ve hala ulaşılmadıysa
                yazdir[yeniX][yeniY] = yazdir[guncelX][guncelY]+1;
                bombx[son]=yeniX; //Dalgadan etkilenenleri son'dan itibaren ekliyoruz
                bomby[son]=yeniY;
                son++; //Ulaşılmayan 0 kaldıkça son artmayacak, bas = son olacak bir yerde
            }
        }
    }
}
for(i=0;i<N;i++){
    for(j=0;j<M;j++){
        printf("%d ", yazdir[i][j]);
    }
    printf("\n");
}
}