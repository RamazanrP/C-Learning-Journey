int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
*returnSize = numRows; // Kaç katlı üçgen?
*returnColumnSizes = (int*)malloc(sizeof(int)*numRows); // Her katta kaç tane tuğla olduğunu göstermek için kat kadar dizi açalım
int** ucgen = (int**)malloc(sizeof(int*)*numRows);
for(int kat=0;kat<numRows;kat++){
    int sayi_adedi = kat+1; // Her kata kaç sayı yerleştirebiliriz?
    (*returnColumnSizes)[kat] = sayi_adedi;
    ucgen[kat] = (int*)malloc(sizeof(int)*sayi_adedi);
    ucgen[kat][0] = ucgen[kat][sayi_adedi-1] = 1;
    for(int sutun=1;sutun<sayi_adedi-1;sutun++){ // 0. kat için sayi_adedi-1==0 olduğu için for'a girmez ve de tehlikeye atmaz :)
        ucgen[kat][sutun] = ucgen[kat-1][sutun-1] + ucgen[kat-1][sutun];
    }
}
return ucgen;
}