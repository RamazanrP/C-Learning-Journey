#include <stdio.h>
// Verilen +/- sayıyı basamak adedi kaybetmeden en küçük haliyle ekrana yazdıran kod
long long N,temp,mutlak,yedeksayi;
int main(){
int hane[20],i,j,sifirsayaci=0,basamak=0;
printf("Sayinizi giriniz: ");
scanf("%lld", &N);
yedeksayi = N;
if(N<0){
    mutlak = N*-1;
}else{
    mutlak = N;
}
yedeksayi = mutlak;
while(yedeksayi>0){
    yedeksayi = yedeksayi/10;
    basamak++;
}
for(i=0;i<basamak;i++){
    hane[i] = mutlak%10;
    mutlak/=10;
    if(hane[i] == 0){
        sifirsayaci++;
    }
}
for(i=0;i<basamak-1;i++){
    for(j=i+1;j<basamak;j++){
        if(hane[j] <= hane[i]){
            temp = hane[j];
            hane[j] = hane[i];
            hane[i] = temp;
        }
    }
}
if(N >= 0){
    printf("%d", hane[sifirsayaci]);
    for(i=0;i<sifirsayaci;i++){
        printf("0");
    }
    for(i=sifirsayaci+1;i<basamak;i++){
        printf("%d", hane[i]);
    }
}else{
    printf('-');
    for(i=basamak-1;i>=0;i--){
        printf("%d", hane[i]);
    }
}
printf("\n");
return 0;
}