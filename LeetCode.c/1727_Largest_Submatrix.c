int sirala(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
} // 0 ve 1'lerden oluşan matriste bize bir kere sütün yer değiştirme hakkı veriliyor. 1'lerle oluşturulacak en büyük alan?
int largestSubmatrix(int** matrix, int matrixSize, int* matrixColSize){
int satir = matrixSize,sutun = matrixColSize[0];
int* yukseklikler = (int*)calloc(sutun,sizeof(int));
int* sortedYukseklik = (int*)malloc(sizeof(int)*sutun);
int max_alan=0,alan;
for(int i=0;i<satir;i++){
    for(int j=0;j<sutun;j++){
        yukseklikler[j] = (matrix[i][j])?yukseklikler[j]+1:0; // 0 Gördüğü anda o katı KOMPLE YIKIYOR
        sortedYukseklik[j] = yukseklikler[j]; // Yuk. dizisi ORİJİNALe göre katları arttıyor, sorted ise ANLIK olarak satıra bakıyor ve de yer değiştiriyor.
        // Eğer sorted olmasaydı yuksekliklerde üst üste her geçerli 1'i kat sayardık
    } // Bir satıra yönelik sayım bitince, kat sayılacak sütunlar belirlenince HER KATTA sayım yapılmalı. Yoksa en alt katı baz alır ve hatalı sonuç verir
    qsort(sortedYukseklik, sutun, sizeof(int), sirala);
    for(int k=0;k<sutun;k++){
    alan = sortedYukseklik[k]* (k+1);
    if(alan>max_alan) max_alan = alan; // ANLIK olarak rekoru yakalarsak diye her satırda tarıyoruz
}
}
free(yukseklikler);
free(sortedYukseklik);
return max_alan;
}