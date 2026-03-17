// Verilen dizide En büyük alanı bulmamız isteniyor. Biz, her dizi[i] için kendisinden kısa olan sağ ve sol indisi bulup dizi[i] ile çarpacağız.
int largestRectangleArea(int* heights, int heightsSize) {
if(heightsSize==0) return 0;
int* sol_sinir = (int*)malloc(sizeof(int)*heightsSize);
int* sag_sinir = (int*)malloc(sizeof(int)*heightsSize);
sol_sinir[0] = -1; // En baştaki indisin solunda kimse yok
// Bizi durduracak indisi arıyoruz. p, bizim baktığım indisi gösteriyor (bizim solumuzdan başlıyor).
//  Baktığımız değer bizden uzunsa eğer bizi durduramaz, durmadığımız için GERİYE GİDİYORUZ. Bizden uzun olanı DURDURAN indise yani bizden uzun olandan daha KISA OLANA bakıyoruz bizden uzun mu diye
// Eğer bizden KISA bulursak while'a girmeyiz. Solumuzdaki bizden kısadır. Bizi DURDURABİLİR. Onun indisini alır KENDİ sol sınırımıza yazarız
for(int i=1;i<heightsSize;i++){
    int p = i-1;
    while(p>=0 && heights[p]>=heights[i]){
        p = sol_sinir[p];
    }
    sol_sinir[i] = p;
}
sag_sinir[heightsSize-1] = heightsSize; // En sağdaki indisin sağında kimse yok
for(int i=heightsSize-2;i>=0;i--){
    int p = i+1;
    while(p<heightsSize && heights[p] >= heights[i]){
        p = sag_sinir[p];
    }
    sag_sinir[i] = p;
}
int max_alan = 0;
for(int i=0;i<heightsSize;i++){
    int genislik = sag_sinir[i] - sol_sinir[i]-1; // Bizi durduran yani Binamızı yıkan indisler olduğu için DAHİL ETMİYORUZ
    int alan = genislik * heights[i];
    if(alan > max_alan){
        max_alan = alan;
    }
}
free(sag_sinir);
free(sol_sinir);
return max_alan;
}