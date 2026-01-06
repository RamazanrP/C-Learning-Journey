#include <stdio.h>
/* Matrisin eleman sıralarını
        1 2 4 7 
        3 5 8 11
        6 9 12 14
        10 13 15 16
        diye yazdıran kod
        */ 
int main () {
int i,j,k,l=0,index=0;
int donusum[4][4];
int eski[16];
printf("4x4luk matrisinizi giriniz: ");
for(i=0;i<16;i++){
    scanf("%d", &eski[i]);
}
for(k=0;k<=6;k++){ //4x4 değil de NxN için yapsaydık k< 2*N-2 olacaktı çünkü son elemanın indisleri N-1 ve N-1 dir.
    if(k>3)
    {
        l++; //k, 3'ü geçmeye başlayınca 4x4 matrise sığmıyor, (k 3ü geçince) i'yi 1 2 ve en son 3 yapmamız lazım ki sığsın
    }
    for(i=l;i<=k-l;i++){ //burada simetrik alınması için k değil k-l ye kadar gitmesi çok kritik!!!
        donusum[i][k-i]= eski[index]; //i j yerine i k-i yazıyoruz
        index++;
    }
}
for(i=0;i<4;i++)
{
    for(j=0;j<4;j++)
    {
        printf(" %d",donusum[i][j]);
    }
    printf("\n");
}
}