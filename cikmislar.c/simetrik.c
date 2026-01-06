#include <stdio.h>
//daha seksi gözükmesi için if(!=) in altına return 0; yazıp BÜTÜN MAİN fonk.unu bitirebiliriz. tabi returndan önce simetrik değil yazdıralım
int main () {
int i,j,k,N;
int matris[10][10];
int gecerli=1;
printf("Kare matrisinizin boyut degerini giriniz: ");
scanf("%d", &N);
printf("Matrisinizi doldurun: ");
for(i=0;i<N;i++){
    for(j=0;j<N;j++){
        scanf("%d", &matris[i][j]);
    }
}
/*for(i=0;i<N;i++){     Bunu yazarsak tüm matrisi boş yere gezeceğiz, üstüne de kontrol edilenleri de etmiş olacağız
    for(j=0;j<N;j++){
        if(i!=j){
            if(matris[i][j]!=matris[j][i]){
                gecerli=0;
            }
        }
    }
}*/
for(i=0;i<N;i++){
    for(j=i+1;j<N;j++){
        if(matris[i][j]!=matris[j][i]){
            gecerli=0;
            break; //bir kere bile eşit olmayan varsa for dan çıksın diye yazdık
        }
    }
    if(gecerli==0){
        break; //önceki break sadece j yi kırdı, biz tamamen buradan çıkmasını istiyorsak j'den sonra da kontrol yazıp kırmalıyız
    }
}
if(gecerli==1){
    printf("Matrisiniz Simetrik <3");
} else{
    printf("Matrisiniz Simetrik degil");
}
}