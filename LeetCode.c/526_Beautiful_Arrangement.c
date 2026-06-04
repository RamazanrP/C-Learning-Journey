#include <stdbool.h>
void backtrack(int n, bool* visited, int current, int* sayac){
    if(current == 0){ // current-1 dedi, 1-1 0'ı çağırdı. 0. koltuk yok, demek ki herkes harika yerleşmiş, o an elindekini kaydet ve başkalarını ara
        (*sayac)++;
        return;
    }
    for(int i=1; i<=n; i++){
        if(!visited[i] && (i%current == 0 || current%i == 0)){
            visited[i] = true;
            backtrack(n, visited, current-1, sayac); // Bu satır bittiğinde i için mevcut sayım yapılmış oluyor.
            //Diğer i'ye geçerken temiz bir sayfa olması lazım. O yüzden eski i'yi false yapıp for'dan i'yi ilerletiyoruz
            visited[i] = false;
        }
    }
}
int countArrangement(int n) {
int sayac =  0;
bool visited[16] = {false};
// 1'den başlasaydık ilerde bozulacak çok fazla dal ile uğraşmış olacaktık. N'den başladık ki elemek kolaylaşsın
backtrack(n, visited, n, &sayac);
return sayac;
}