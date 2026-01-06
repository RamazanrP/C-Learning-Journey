#include <stdio.h>

int main () {
int i,j,k,index=0;
int donusum[4][4];
int eski[16];
printf("4x4luk matrisinizi giriniz: ");
for(i=0;i<16;i++){
    scanf("%d", &eski[i]);// eğer eski'yi i j diye alsaydık baya yük binecekti, 16 sayı olarak aldık
}
for(k=0;k<=6;k++){
    
    for(i=0;i<=k;i++){
        if(i>3 || (k-i)>3) //k'nın bütün değerlerini değerlendiriyor ama 3'ten büyük oldu mu atlatıyor onu
        {
            continue;// con. eğer üstteki şart SAĞLANIYORSA o işlemi atlayıp for'u bir sonraki frame'e geçirtiyor
        }
        donusum[i][k-i]= eski[index];// j kullanmak yerine k-i dedik
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