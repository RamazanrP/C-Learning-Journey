#include <stdbool.h>
bool check(char** board, int satirSayisi, int sutunSayisi, int i, int j, char* word, int k) {
    if (word[k] == '\0') return true; //check' girince sonra direkt kontrole sokalım

    if (i < 0 || i >= satirSayisi || j < 0 || j >= sutunSayisi || board[i][j] != word[k]) {
        return false; // Hızlı bitmesi için if açtık
    }

    // Harf tuttu! Ama bu hücreyi tekrar kullanmamak için işaretlemeliyiz.
    char temp = board[i][j];
    board[i][j] = '#'; // Geçici olarak 'gidildi' işareti koyuyoruz

    // Şimdi 4 yöne izciler gönderiyoruz (k+1. harf için)
    bool sonuc = check(board, satirSayisi, sutunSayisi, i + 1, j, word, k + 1) ||
                 check(board, satirSayisi, sutunSayisi, i - 1, j, word, k + 1) || 
                 check(board, satirSayisi, sutunSayisi, i, j + 1, word, k + 1) || 
                 check(board, satirSayisi, sutunSayisi, i, j - 1, word, k + 1);   

    // İşimiz bitti, hücreyi eski haline getiriyoruz (Backtrack)
    board[i][j] = temp; 

    return sonuc;
}
bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    int satir = boardSize;
    int sutun = *boardColSize;

    for(int i=0; i<satir; i++) {
        for (int j=0; j<sutun; j++) {
            // Eğer ilk harfi bulursan ve check fonksiyonu "Tamamdır" derse
            if (board[i][j] == word[0] && check(board, satir, sutun, i, j, word, 0)) {
                return true;
            }
        }
    }
    
    return false; // Hiçbir yerden yol bulamadık
}