#include <stdio.h>
//NxN matristek 0lar normal, 1ler bomba olacak. Output matrisi 0ların yerine sınırında (çaprazlar da bomba sayılır ) kaç tane 1 var onu gösterecek, 1ler de * olacak
int main () {
int i,N,j,k,l;
int mayin[10][10], patlak[10][10];
int sayac;
printf("Tarlanizin boyutunu giriniz: ");
scanf("%d", &N);
printf("Tarla matrisini doldurunuz: ");
for(i=0;i<N;i++){
    for(j=0;j<N;j++){
        scanf("%d", &mayin[i][j]);
    }
}
for(i=0;i<N;i++){
    for(j=0;j<N;j++){
        sayac=0; //burada sıfırlamazsak etrafıbda bomba olmayanlar da değer gözükmez
        if(mayin[i][j]==1){  //Bunu koyduk ki eğer sayı 1 ise direkt bomba diyelim, etrafına bakmayalım
            patlak[i][j]= '*';
        }
        else {
            for(k=i-1;k<=i+1;k++){ //burada k ve l'yi i ve j'ye göre oluşturuyyoruz ancak k ve l kendisi artacak, i ve j yi koyma 
                for(l=j-1;l<=j+1;l++){
                    if(k>=0 && k<N && l>=0 && l<N){     //sınır kontrolü koyduk
                        if(mayin[k][l]==1){
                        sayac=sayac+1;
                        }
                    }
                }
            }
            patlak[i][j]=sayac; //burayı else'in içine aldık yoksa başta * bulunan yere 0 yazardı
        }
    }
}
printf("Matrisinizin patlamis hali: ");
for(i=0;i<N;i++){
    for(j=0;j<N;j++){
        if(patlak[i][j]=='*'){
        printf("* "); //printf e '' konmaz
        }else{
            printf("%d ", patlak[i][j]);
        }
    }
    printf("\n");
}
}