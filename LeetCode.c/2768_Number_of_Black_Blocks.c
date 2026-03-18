// Verilen matris içinde kalacak şekilde bazı koordinatlar veriliyor. Verilen bu kareleri siyaha boyayalım ve 5 indisli bir dizi açalım
// Soru bize tüm 2x2 matrislere bakmamızı ve 0'dan 4'e kadar bu matrislerden kaç tane 0-4 arası siyah kare içeriyor bunu döndürmemizi istiyor
int sirala(const void* a, const void* b) {
    long long val_a = *(long long*)a;
    long long val_b = *(long long*)b;
    if (val_a < val_b) return -1;
    if (val_a > val_b) return 1;
    return 0;
}
long long* countBlackBlocks(int m, int n, int** coordinates, int coordinatesSize, int* coordinatesColSize, int* returnSize) {
*returnSize = 5;
long long* IDs = (long long*)malloc((coordinatesSize*4)*sizeof(long long)); // Kaç tane siyah karemiz varsa 4 kare etki alanı vardır. Bunları kaydedeceğiz
int blok_adedi = coordinatesSize;
int k=0;
long long* sonuc = (long long*)calloc(5,sizeof(long long));
for(int i=0;i<blok_adedi;i++){
    long long x = coordinates[i][0], y = coordinates[i][1];
    if(x>= 0 && x<m-1 && y>=0 && y<n-1 ){
        long long id = x*n + y; // Matrixi düz bir array olarak yazmak istediğimiz için id, integer sınırını aşabilir ! 
        IDs[k] = id;            // Verilen koordinata göre SOL ÜST köşe neresi olur diye kontrol ediyoruz. O yüzden x ve y için üst sınırımız <m-1/n-1
        k++;                    // Mesela 0,0 için de 1,1 için de ortak id'miz 0,0
    }
    if(x-1>= 0 && x-1<m-1 && y>=0 && y<n-1 ){
        long long id = (x-1)*n + y;
        IDs[k] = id;
        k++;
    }
    if(x>= 0 && x<m-1 && y-1>=0 && y-1<n-1 ){
        long long id = x*n + y-1;
        IDs[k] = id;
        k++;
    }
    if(x-1>= 0 && x-1<m-1 && y-1>=0 && y-1<n-1 ){
        long long id = (x-1)*n + y-1;
        IDs[k] = id;
        k++;
    }

}
qsort(IDs, k, sizeof(long long), sirala);
int i=0;
int total_blacks = 0;
while(i<k){
    int adet = 1; // Listedeki her id en az bir kere var zaten
    while(i<k-1 && IDs[i] == IDs[i+1]){
        adet++,i++;
    }
    sonuc[adet]++; // Soru bize kaç tane çerçeve var demiyor. Şu adette kaç tane çerçeve var diye soruyor. O yüzden adet'i bulup sonuç dizisindeki sayıyı BİRER BİRER arttırıyoruz
    total_blacks++;
    i++;
}// 1-4 toplamını bulup toplam 2x2 matris sayısından bunu çıkarırsak hiç siyah içermeyen dizi[0]'ı bulmuş oluruz
sonuc[0] = (long long)(m-1)*(n-1) - total_blacks;
free(IDs);
return sonuc;
}