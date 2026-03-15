// Bizden istenen -> Bir müşteri dizisi var. Her müşterinin bir bileti var. Bu bilet o müşterinin kaç kişilik masa istediğini söylüyor
// Soru da bizden bu aynı masaya oturan "indislerin" matrisini döndürmemizi istiyor
int comp(const void* a, const void* b){
    return (*(int**)a)[0] - (*(int**)b)[0];
}
// groupSizesSize -> Dizi kaç elemanlı
// returnSize -> Doldurulan masa adedi
// returnColumnSizes -> Kaçıncı masada kaç kişi oturuyor bunun listesi 
int** groupThePeople(int* groupSizes, int groupSizesSize, int* returnSize, int** returnColumnSizes){
int ** mylist = (int**)malloc(sizeof(int*)*groupSizesSize); // Orijinal indexlerini unutmamak için 2 satırlık liste oluşturduk
int** sonuc =  (int**)malloc(sizeof(int*)*groupSizesSize);
*returnColumnSizes = (int*)malloc(sizeof(int)*groupSizesSize); // Hangi masada kaç kişi oturuyor listesi(en kötü ihtimale karşı büyük açtık)
for(int i=0;i<groupSizesSize;i++){
    mylist[i] = (int*)malloc(sizeof(int)*2);
    mylist[i][0] = groupSizes[i]; // Masanın boyutu
    mylist[i][1] = i;
}
qsort(mylist, groupSizesSize, sizeof(int*), comp); // Aynı boyuta sahip herkes yan yana hem de indisleriyle
int i=0;
*returnSize = 0; // Başta hiç dolu masamız yok
while(i<groupSizesSize){
    int boyut = mylist[i][0];
    sonuc[*returnSize] = (int*)malloc(sizeof(int)*boyut); // Diziyi gezdik ve gördüğümüz sayı kadar(boyutu kadar) bir masa açtık
    for(int j=0;j<boyut;j++,i++){
        sonuc[*returnSize][j] = mylist[i][1]; // O masada boyut kadar eleman olduğu için boyut kadar ilerleyip elemanları sonuca atıyoruz
    }
    (*returnColumnSizes)[*returnSize] = boyut; // Masanın kapasitesini LeetCode için hazırladık
    (*returnSize)++; // Masa doldu, diğerine geç
}
for(int k=0; k<groupSizesSize;k++){
    free(mylist[k]); 
}
free(mylist); 
return sonuc;
}