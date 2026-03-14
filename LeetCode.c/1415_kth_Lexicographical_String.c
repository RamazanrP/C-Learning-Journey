char* getHappyString(int n, int k) {
// karakterlerimiz a,b ve c. Stringte her harften sonrakisi öncekinden farklı olmalı. Bize bu n haneli kelimelerden k.cıyı soruyor
int total = 3*(1<<(n-1));
if(k>total) return "";
char s[] = {'a','b','c'};
static char cevap[100];
int index,block; // İndex bize nokta atışı yeri söylerken blok da bize bu nokta atışı yapıalcak alanı daraltıyor/söylüyor
int i,j;   
k--; // C'ye göre k. indis için azalttık
for(i=0;i<n;i++){
    block = 1<< (n-1)-i; // İlk harfi bulduktan sonra gerisinde kaç tane string oluşabilir(2^n-1)
    index = k/block;     // İlk harfimizin hangisi olduğunu söyler (integer'ın sağladığı özellikle fazlalıklar da block içinde kalıyor)
    for(j=0;j<3;j++){
        if(i==0 || s[j] != cevap[i-1]){ // İlk harfteysek arkamıza bakmayız. Bu yüzden i==0 var YA DA önceki ile pişti değilsek
            if(index == 0){ // İndex bize ES GEÇMEMİZ GEREKEN HARF SAYISINI söylüyor. Önce geçerli olacak (öncekinden farklı) sonra da sırası gelmiş olacak
                cevap[i] = s[j]; // Hem geçerli hem de sırası gelmişse yazdıralım ve de çıkalım artık burdan
                break;
            }
            index--;
        }
    }
    k %= block; // Artık bir harfi yerleştirdik, önümüze bakmak için gidilecek yol sayısını küçültüyoruz
}
// n=3 k=4 olsun. aba,abc,aca,acb -> Biz acb'yi bulacağız
// i=0 block=4 yani ilk harfi bulduktan sonra 4 yol var. index= 3(k--)/4 = 0 yani 0. indise bakacağız
// i==0 olduğundan geçerli, index==0 olduğundan BULDUK, cevap[0] = s[0] yani 'a' (break ile çıktık) k -> 3 %= 4 yani 'a' bloğunun içindeki 3. kelimeyi arıyoruz
// i==1 block = 2 index = 3/2 yani 1 ->  GEÇERLİ harfler arasından  1 TANEYİ ATLA 
// if'e geldi. Önceki harf a olduğu için if'e girmez. GEÇERLİ DEĞİL Kİ AZALSIN.
//  Azalmadı j==1 oldu. sıra b'ye geldi ama index==1 yani atlaması gerekiyor. Atladı c'ye geldi. index==0 yani c'yi al içine yaz
// k -> 3 %= 2 yani 1 oldu. Yani SON HARF ARTIK
// i==2 oldu block == 1, index == 1/1=1 yani GEÇERLİlerden 1 tane atla, iknciyi al
// j==0, 'a' geldi. Önceki c'ydi, geçerli. if'e girdik ama index == 1, 'a'yı atla b'ye gel ve de yerleştir.
// String olması için son indisi de koyduk
cevap[n] = '\0';
return cevap;
}