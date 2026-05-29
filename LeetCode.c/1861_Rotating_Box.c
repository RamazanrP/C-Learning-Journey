char** rotateTheBox(char** boxGrid, int boxGridSize, int* boxGridColSize, int* returnSize, int** returnColumnSizes) {
int satir = boxGridSize, sutun = *boxGridColSize;
for(int i=0;i<satir; i++){
    int bosluk = sutun-1;
    for(int j = sutun-1; j>=0; j--){
        if(boxGrid[i][j] == '*') bosluk = j-1;
        else if(boxGrid[i][j] == '#'){
            boxGrid[i][j] = '.'; // Boşluk da taş da aynı hücreye denk gelirse diye bu önlemi almalıyız. Önce temizle sonra yerleştri
            boxGrid[i][bosluk] = '#';
            bosluk--;
        }
    }
}
char** rotated = (char**)malloc(sutun * sizeof(char*));
    *returnColumnSizes = (int*)malloc(sutun * sizeof(int)); // sutun adet satırımız var
    *returnSize = sutun;
    
    for (int i=0; i < sutun; i++) {
        rotated[i] = (char*)malloc(satir * sizeof(char));
        (*returnColumnSizes)[i] = satir; // HEr satırımızda satir adedinde sütun var, bunu bildiriyoruz
    }
    
    for (int i=0; i < satir; i++) {
        for (int j=0; j < sutun; j++) {
            rotated[j][satir - 1 - i] = boxGrid[i][j];
        }
    }
    
    return rotated;
}