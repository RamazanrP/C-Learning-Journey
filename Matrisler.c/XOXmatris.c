#include <stdio.h>
// X ve O harf olduğu için char olarak tanıttık matrisi, dikkat
int main() {
char tiktaktoe[3][3]; //Matrisleri 0'dan değil 1'den başlatıyoruz satır sütun olarak
int i,j;
int satir,sutun;
char oyuncu; //X ve O'ları karakter olarak gireceğimiz için char tanıttık
for(i=0; i<=2;i++){
    for(j=0; j<=2;j++){
        tiktaktoe[i][j]=' ';
    }
}
printf("-------OYUN BASLİYOR-------\n");
for(i=0;i<9;i++){
    //Sıranın kimde olduğunu bulmak için mod alacaz
    if(i %2==0) oyuncu= 'X';
    else oyuncu ='O';
    printf("\n Sira %c oyuncusunda. SatirxSutun giriniz:  " ,oyuncu);
// kullanıcı doğru girene kadar değer isteyeceğiz
int gecerli=0;
//do-while şartını =0 yapacağız ki doğru girene kadar dönsün
// =1 olduğunda while kırılacak, for i++ olacak
do{
    scanf("%d %d", &satir, &sutun);
    if(satir<0|| satir>2|| sutun<0||sutun>2){
        printf("Hatali koordinat girdiniz ");
    } else if (tiktaktoe[satir][sutun] != ' '){
        printf("Girilen yerde harf mevcut!");
    } else {
        gecerli= 1;
    }
}
 while (gecerli == 0);
// ilk 2 eleme şartı da geçildiyse demek ki sorunsuz bir eylem olmuş
//Bu yüzden gecerli =1 dedik ki while'dan çıksın, for artsın
tiktaktoe[satir][sutun] = oyuncu;
printf("\n");
for(int k=0; k<3; k++){
    printf("%c| %c| %c\n", tiktaktoe[k][0], tiktaktoe[k][1], tiktaktoe[k][2]);
    if(k!= 2) printf("---|---|---\n");
}
char kazanan;
for(int k=0;k<3;k++){ // 2 den fazla şey varsa == yazamayız && olmalı
 if(tiktaktoe[k][0]==tiktaktoe[k][1] && tiktaktoe[k][1]==tiktaktoe[k][2] && tiktaktoe[k][2]!= ' '){
    kazanan= tiktaktoe[k][0];
    }
 if(tiktaktoe[0][k]==tiktaktoe[1][k] && tiktaktoe[1][k]==tiktaktoe[2][k] &&  tiktaktoe[2][k]!= ' '){
    kazanan= tiktaktoe[0][k];
    
 }
} if(tiktaktoe[0][0]==tiktaktoe[1][1] && tiktaktoe[1][1]==tiktaktoe[2][2]  && tiktaktoe[1][1] != ' '){
    kazanan=tiktaktoe[0][0];
    
 }
 if(tiktaktoe[2][0]==tiktaktoe[1][1] && tiktaktoe[1][1]==tiktaktoe[0][2]  && tiktaktoe[1][1] != ' '){
    kazanan=tiktaktoe[2][0];
    
 }
if(kazanan!=' '){
    printf("Kazanan %c", kazanan);
    break;
}
}
}