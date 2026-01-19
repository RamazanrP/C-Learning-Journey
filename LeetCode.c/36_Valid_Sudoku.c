#include <stdbool.h>
bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
char satir[9][9] = {0};    // Burada her satır, sütun veya blok için histogram açmayacağız
char sutun[9][9] = {0};    // 9 satır 9 sütun ve de 9 bloğumuz var, 1. index kaçıncı satır,sütun,blok olduğunu söyleyecek
char bloklar[9][9] = {0};  // İkinci index de bizim numaramız olacak. Önceden işaretlenmişse (==1) false çevirecek
for(int i=0;i<9;++i){
    for(int j=0;j<9;++j){
        if(board[i][j] == '.') continue;
        int num = board[i][j] - '1'; // Ama tabi 0'dan 8'e kadar olduğu için bir azaltıyoruz
        int k= (i/3)*3 + (j/3); // bloklar üçerli olduğu için /3, bir satırda 3 tane blok olduğu içşn *3 
        if(satir[i][num] == 1 || sutun[j][num] == 1 || bloklar[k][num] == 1) return false;
        else{
            satir[i][num] = 1;
            sutun[j][num] = 1;
            bloklar[k][num] = 1;
        }
    }
}
return true;
}