#include <stdio.h>
//90 derece saat yönünde çevirmek aslında trasnpoze halinin satırlarının tersten okunmuş halidir
int main () {
int i,j,satir,sutun;
int matris[10][10];
int transpoze[10][10];
printf("Matrisinizin boyutlarini giriniz: ");
scanf("%d %d", &satir, &sutun);
for(i=0;i<satir;i++){
    for(j=0;j<sutun;j++){
        scanf("%d", &matris[i][j]);
        transpoze[j][i]=matris[i][j]; // değeri çektiğimiz gibi atayabiliriz
    }
}
for(i=0;i<sutun;i++){         //i'nin bu sefer sutun j'nin satir olmasina dikkat!!!
    for(j=satir-1;j>=0;j--){  //Transpozun satırını tersten okuduk, 90 derece dönmüş oldu
        printf("%d ", transpoze[i][j]);
    }
    printf("\n");
}
return 0;
}