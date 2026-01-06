#include <stdio.h>

int main () {
int i,j,N;
int matris[10][10];
int dizi[100];
int sol=0,ust=0;
int sag,alt; //N'yi aldıktan sonra değer atayacaz
printf("Kare matrisinizin boyutunu giriniz: ");
scanf("%d", &N);
printf("Matrisinizi doldurunuz: ");
for(i=0;i<N;i++){
    for(j=0;j<N;j++){
        scanf("%d", &matris[i][j]);
    }
}
sag=N-1,alt=N-1;
while (sol<=sag && ust<=alt) //şimdi biz burada 1 kere koşul koyduk ama içerdeki for'ların ne kadar gideceği belli değil, o yüzden son 2'ye if koyduk
{
for(j=sol;j<=sag;j++){
    printf("%d ", matris[ust][j]);
}
ust++;                      // for sonrası +/- lere dikkat!!!
for(i=ust;i<=alt;i++){
    printf("%d ", matris[i][sag]);
}
sag--;
if(ust<=alt){ //Burada en alt satırı yazdırırken yatay kontrol yaptık ki bir daha tekrara girmesin
    for(j=sag;j>=sol;j--){
        printf("%d ", matris[alt][j]);
    }
}
alt--;
if(sol<=sag){ //sol sütunu yazdırırken hala genişlik olup olmadığını kontrol ettik
    for(i=alt;i>=ust;i--){
        printf("%d ", matris[i][sol]);
    }
}
sol++;
}
}