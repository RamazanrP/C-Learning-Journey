#include <stdio.h>

int main() {
int n,m,i,j,k;
int matris[50][50];
int kucuk,sutunind;
printf("Matrisin boyutlarini giriniz (satirxsutun) ");
scanf("%d %d", &n, &m);
printf("Matrisi doldurunuz ");
for(i=0;i<n;i++) {
    for(j=0;j<m;j++){
        scanf("%d", &matris[i][j]);
    }
}
for(i=0;i<n;i++){
   kucuk= matris[i][0];
   sutunind=0; //Bunu unutursak ilk satırdaki 0. sütnun küçük değer olmasını görmezden gelmiş oluruz çümkü j'yi 1'den başlatıyoruz 
   for(j=1;j<m;j++){
        if(matris[i][j]< kucuk){
            kucuk=matris[i][j];
            sutunind=j; //BÖylece aşağı ineceğimiz yeri bulduk, j yerine bu değişkeni yazacağız, j değeri uçtu gitti
        }
    }
    for(k=0;k<n;k++){
        if(matris[k][sutunind]> kucuk){
    break;
        } 
    } 
if(k==n) { /*Break diyince fordan çıktık, yokmeğer tüm satırları gezseydi de çıkacaktık. Bu yüzden kontrol ediyoruz. Tüm satırları
    gezmiş ise demek ki daha büyüğü yok. yani istediğimiz */
    printf("%d. satir %d. sutun semer noktasi", i+1, sutunind+1);
}
}
    
}