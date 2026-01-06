#include <stdio.h>
// Çift olan bir N sayısına göre NxN matrisi sağ üst-sol üst vb. 4 bloğa bölüp bunları 1 kere saat yönünde taşıyan ve
// Oluşan matrisi yılan seklinde sağdan sola sonra soldan sağa gide gide aşağı iner şekilde printfleyen kod
int main () {
int i,j,N,boyut,matris[50][50],temp,cift=1;
printf("Matrisinizin boyutunu giriniz: (N, cift olmali!)");
while(cift==1){ //Kullanıcı çift girene kadar soracak.
    scanf("%d", &N);
    if(N%2!=0){
        printf("N, cift sayi olmalidir! Tekrar giriniz \n");
    }else{
        cift = 0;
        boyut = N;
    }
}
N=boyut;
printf("Matrisinizi giriniz:\n");
for(i=0; i<N; i++){
    for(j=0; j<N; j++){
        scanf("%d", &matris[i][j]);
    }
}
for(i=0; i<N/2; i++){ //Tek bir bloğu halletsek yeter. Sol üste temp diyip sol aşağıdakini içine koyacaz.Saatin tersinden gidecez
    for(j=0; j<N/2; j++){ //Tabi ki 0'dan N/2'ye kadardır sol üst blok
        temp = matris[i][j];
        matris[i][j] = matris[i+N/2][j]; // Diğer blok ile aradaki farkımız hep N/2
        matris[i+(N/2)][j] = matris[i+(N/2)][j+(N/2)];
        matris[i+(N/2)][j+(N/2)] = matris[i][j+(N/2)];
        matris[i][j+(N/2)] = temp; // En son Sağ üzttekine de temp atadık. Tek seferde halloldu
    }
}
for(i=0; i<N; i++){
    if(i%2==0){
        for(j=0; j<N; j++){
            printf(" %d", matris[i][j]);
        }
    }else{
        for(j=N-1; j>=0; j--){
            printf(" %d", matris[i][j]);
        }
    }
    printf("\n");
}
}