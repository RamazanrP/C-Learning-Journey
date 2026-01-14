#include <stdio.h>
// LeetCode 73. Soru -> matriste 0 bulunan bloğun bütün satır ve sütunu 0 yapılsın
int main () {
int i,j,satir,sutun,col0=1,matris[20][20];
printf("Matrisin boyutlarini giriniz: ");
scanf("%d %d", &satir, &sutun);
printf("Matrisinizi giriniz: ");
for(i=0;i<satir;i++){
    for(j=0;j<sutun;j++){
        scanf("%d", &matris[i][j]);
    }
}  
for(i=0;i<satir;i++){
    if(matris[i][0] == 0){
        col0 = 0;
    }
    for(j=1;j<sutun;j++){
        if(matris[i][j] == 0){ // İlk sütun dışında 0 görürsek
            matris[i][0] = 0;  // satırın başını 0 yapalım
            matris[0][j] = 0;  // Sütunun başını 0 yapalım. İşaretliyoruz böylece
        }
    }
}
for(i=satir-1;i>=0;i--){
    for(j=sutun-1;j>=1;j--){ // İlk sütunu boş bırakcaz, en son kontrol edeceğiz.
        if(matris[i][0] == 0 || matris[0][j] == 0){
            matris[i][j] = 0; // Hepsini sıfırla
        }
    }
}
if(col0 == 0){
    for(i=0;i<satir;i++){
        matris[i][0] = 0;
    }
}
for(i=0;i<satir;i++){
    for(j=0;j<sutun;j++){
        printf("%d ", matris[i][j]);
    }
    printf("\n");
}
return 0;
}