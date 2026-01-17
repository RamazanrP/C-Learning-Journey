void batir(int row, int col, char**grid, int satir, int sutun){
    if(row<0 || row>=satir || col<0 || col>= sutun || grid[row][col] == '0'){
        return; //Kontrolleri erkenden yapıp işlemi kısaltıyor ve de filtreliyoruz
    }
    grid[row][col] = '0'; //==1 se ve yukardaki if'ten geçmişse 0'a eşitleyip ZİNCİRLEME gitmek için 4 yönü de gene burda çağırdık
    batir(row-1,col,grid,satir,sutun);
    batir(row+1,col,grid,satir,sutun);
    batir(row,col-1,grid,satir,sutun);
    batir(row,col+1,grid,satir,sutun);
}
int numIslands(char** grid, int gridSize, int* gridColSize) {
if (gridSize == 0) return 0;
int adasayisi=0;
int satir = gridSize, sutun = *gridColSize;
for(int row=0;row<satir;++row){
    for(int col=0;col<sutun;++col){
        if(grid[row][col] == '1'){
            adasayisi++;            //Bir tane 1 bulduk mu hemen ada sayısını arttıralım ve batiralim geri kalanı
            batir(row,col,grid,satir,sutun);
        }
    }
}
return adasayisi;   
}