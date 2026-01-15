#include <stdio.h>
//O lar cansız, 1'ler canlı, 1'in etrafındaki 8 blokta 2||3 cansız varsa yaşar, yoksa ölür. 
//Cansızın etrafında tam 3 canlı varsa yaşar. Ek matris yasak. canlı ama ölecek = -1, ölü ama canlanacak = 2 olsun.
int main () {
int canlisayac,yatay,dikey,i,j,matris[25][25],satir,sutun;
printf("Matrisin boyutlarini giriniz: ");
scanf("%d %d", &satir, &sutun);
printf("Matrisinizi doldurunuz: ");
for(i=0;i<satir;i++){
    for(j=0;j<sutun;j++){
        scanf("%d", &matris[i][j]);
    }
}
for(i=0;i<satir;i++){
    for(j=0;j<sutun;j++){
        canlisayac=0; // Her hücre için sıfırlayalım
        for(dikey=-1;dikey<=1;dikey++){ //8 bloğu saymak için mecburen 3 ve 4. for'u kurmamız lazım
            for(yatay=-1;yatay<=1;yatay++){
                if(yatay==0 && dikey == 0) continue; //Matrisin kendisine bakmıyoruz
                if(i+dikey>= 0 && i+dikey < satir && j+yatay>=0 && j+yatay<sutun){
                    if(matris[i+dikey][j+yatay] == 1 || matris[i+dikey][j+yatay] == -1){ // Sadece canlı hücreleri saymak yeterli
                        canlisayac++;
                    }
                }
            }
        }
        //Buraya kadar saydık, şimdi matristeki bloğun ne olduğunu kontrol edip sayaç değerine göre değiştirecez
        if(matris[i][j] == 1){
            if(canlisayac<2 || canlisayac>3) matris[i][j] = -1;
        }else if(matris[i][j] == 0){
            if(canlisayac == 3) matris[i][j] = 2;
        }
    }
}
for(i=0;i<satir;i++){
    for(j=0;j<sutun;j++){ //Böyle bir konrtol mekanizması kurduk
        if(matris[i][j] == 1 || matris[i][j] == 2){
            matris[i][j] = 1;
            printf("%d ", matris[i][j]); 
        }else{
            matris[i][j] = 0;
            printf("%d ", matris[i][j]);
        }
    }
    printf("\n");
}
return 0;
}