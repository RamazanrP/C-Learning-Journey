int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
int sol=0,sag=n-1,ust=0,alt=n-1;
int i=0,j=0,k=1;
int** matrix = (int**)malloc(n*sizeof(int*)); // İşaretçinin işaretçisi olarak int** dedik, int* ile satırın başlangıç adresini tuttuk
*returnColumnSizes = (int*)malloc(n * sizeof(int));
for(i=0;i<n;i++){
    matrix[i] = (int*)malloc(n * sizeof(int)); // tek[] kullandık çünkü burada sadece SATIRı dikkate alıp yer ayırtıyoruz
    (*returnColumnSizes)[i] = n; //Önce returnCol'u eline alması için parantez şart! Col'u eline aldıktan sonra i. satırda n tane boşluk var demek
}
*returnSize = n; // kaç satır olduğunu döndürdük
while(k<=n*n){
    for(j=sol;j<=sag;j++){
        matrix[ust][j] = k++;
    }
    ust++;
    for(i=ust;i<=alt;i++){
        matrix[i][sag] = k++;
    }
    sag--;
    if(ust<=alt){ // Tekrara düşmemek için 3 ve 4. adımlarımızda if şart!
        for(j=sag;j>=sol;j--){
            matrix[alt][j] = k++;
        }
        alt--;
    }
    if(sag>=sol){
        for(i=alt;i>=ust;i--){
            matrix[i][sol] = k++;
        }
    sol++;
    }
}
return matrix;
}