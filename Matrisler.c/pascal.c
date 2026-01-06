#include <stdio.h>
// piramit olmayan, 1'ler sola yapışık, sağ 1'ler merdiven oalrak inen pascal üçgeni
int main () {
int i,j,N;
int pascal[10][10];
printf("Pascal Ucgeninin satir sayisini giriniz: ");
scanf("%d", &N);
for(i=0;i<N;i++){
    pascal[i][0]=pascal[i][i]=1; //Her satırın ilk ve son elemanı 1 olacak, j'ye ihtiyaç yok diye ilk for'un içine yazdık
    if(i>1){                     //Bunu koyduk ki j nerede çalışacağını bilsin
        for(j=1;j<i;j++){
            pascal[i][j]= pascal[i-1][j] + pascal[i-1][j-1]; //hemen üstündeki ve o üsttekinin solundaki toplamı şeklinde yazdık
        }
    }
}
for(i=0;i<N;i++){
    for(j=0;j<=i;j++){ //<= iye kadar giderse sağdaki 1'ler de gözükür
        printf("%d ", pascal[i][j]);
    }
    printf("\n");
}
}