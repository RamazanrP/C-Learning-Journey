// Verilen Matriste X, Y ve . var. Soru bizden X içeren ve eşit sayıda X-Y içeren altmatrislerin sayısını soruyor
int numberOfSubmatrices(char** grid, int gridSize, int* gridColSize) {
int rowX,rowY;
int satir = gridSize,sutun = gridColSize[0];
int* ox = (int*)calloc(sutun,sizeof(int));
int* oy = (int*)calloc(sutun,sizeof(int));
int sayac=0;
for(int i=0;i<satir;i++){
    rowX=0,rowY=0; // Aşağıda zaten ox/oy[j]'ye += yaptığımız için üst satırlardaki X/Y'leri de alt satıra geçince biriktirmiş oluyoruz
    for(int j=0;j<sutun;j++){
        if(grid[i][j] == 'X') rowX++;
        else if(grid[i][j] == 'Y') rowY++;
        ox[j] += rowX;
        oy[j] += rowY;
        if(ox[j] == oy[j] && ox[j] > 0) sayac++; // En az bir kere X geçsin
    }
}
return sayac;
}