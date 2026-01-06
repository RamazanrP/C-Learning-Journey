#include <stdio.h>

int main (){
int n,m;
int dizi1[10];
int dizi2[10];
int dizi3[10];
int i,j,k;
printf("dizilerin boyutunu giriniz: ");
scanf("%d %d", &n, &m);
printf("ilk dizinizi giriniz ");
for(i=0;i<n;i++){
    scanf("%d", &dizi1[i]);
}
printf("Diger diziyi giriniz ");
for(i=0;i<m;i++){
    scanf("%d", &dizi2[i]);
}
i=k=j=0;
while (i<n && j<m){
    if(dizi1[i]<dizi2[j]){
        dizi3[k]=dizi1[i];
        i+=1;
        k+=1;//k'yı da manuel arttırdık yoksa for'a soksaydık while daima dönecekti
    }else{
        dizi3[k]=dizi2[j];
        j+=1;
        k+=1;
    }
}
/*Buradaki çıkışta biri bitiyor, onu kontrol etmek için if kullanabilirdik ancak if'ten sonra da for koyacaktık. O yüzden while koyduk
hem şartlı olsun hem de devamlı alsın k++ ile*/
while(i<n){
    dizi3[k]=dizi1[i];
    k++;
    i++;
}
while (j<m){
    dizi3[k]=dizi2[j];
    k++;
    j++;
}
for(i=0;i<m+n;i++){ //m+n önemli
    printf("%d ", dizi3[i]);
}

}