#include <stdio.h>
// N tane, uzunlukları dizi olarak verilen ağaçlar için en az uzunlukta odun keserek istenen M kadar odun kesen bir kod
int main () {
long long agaclar[1000005],M,mid,max=0,ust,alt,fark,cevap;
int N,i,j;
long long toplam=0;
printf("Agac adedini ve istenen odun miktarini giriniz: ");
scanf("%d %lld", &N, &M);
printf("Odun yuksekliklerini giriniz: ");
for(i=0;i<N;i++){
    scanf("%lld", &agaclar[i]);
    if(agaclar[i]>max){
        max=agaclar[i]; // En uzun ağacı bulmak için daha scanfle çekerken if'e sokup max'a atayacağız. 2 tane for'a sokarsak pc gider
    }
}
ust=max,alt=0;
while(alt<=ust){ //toplamın tam olarak M'ye eşit olmaması durumunda sonsuz döngü olur. Sınırlardan while'a şart koşmalıyız
mid= alt+ (ust-alt)/2;  // mid'i integer tanıttık, tam sayı olması için bu durumların en geçerli olanını yazdık. Daime int çıkar bu işlem
for(i=0;i<N;i++){
    fark=agaclar[i]-mid;
    if(fark>0){
        toplam+=fark;
    }
}
if(toplam>=M){ //>=olmasına bakacağız, eşitlik  halini de katalım ki mükemmel nokta elimizden kaçmasın
    alt=mid+1;
    cevap=mid; //Şimdi burada biz en yüksekten kesmeyi hedeflediğimiz için toplam>M durumlarında
}else{         //Belki sonraki mid değeri için while bozulur diye yedek değer tuttuk ve de burada atadık
    ust=mid-1; //yoksa sonraki mid değeri ile while'a girip bozularak çıksaydı elimizdeki son doğru değer yanardı
}
toplam=0; //toplamı her yeni for'a sokmadan önce sıfırla!!!
}
printf("minimum H yüksekliginiz %lld metre", cevap);
return 0;
}