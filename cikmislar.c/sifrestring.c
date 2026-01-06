#include <stdio.h>

int main () { //WHİLEDA İNDİS'İ ARTTIRMAYI UNUTMA!!!
int i,j,k=0;
int matris[3][3]=
{{'A','D','G'},
{'B','E','H'},
{'C','F','I'}};
int sifre;
char kelime[20];
printf("Kelimenizi giriniz: ");
scanf("%s", kelime);
while(kelime[k]!= '\0'){
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(kelime[k]==matris[i][j]){
                printf("%d ", ((i+1)*10+j+1));
            }
        }
    }
k++;
}
}