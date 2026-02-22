int binaryGap(int n) {
int max_mesafe = 0;
int son_bir_konumu = -1; // Daha önce hiç 1 görmediğimizi bilmemiz için arrayde olamayacak bir sıra değeri verdik.
int guncel_konum = 0;
while( n > 0){
    if(n % 2 == 1){ // 1 görünce içeri girelim
        if(son_bir_konumu =! -1){ // Daha önce 1 gördüysek hemen mesafe hesaplayalım
            int mesafe = guncel_konum - son_bir_konumu;
            if(mesafe > max_mesafe){
                max_mesafe = mesafe;
            }
        }
        son_bir_konumu = guncel_konum; // Daha önce 1 görüp görmememizden bağımsız olarak son görülen 1'i bu konuma güncelledik
    }
    n/=2; // Digit 1 ve 0 olsun fark etmez. Her türlü konum artacak ve sayı küçülecek
    guncel_konum++;
} 
return max_mesafe;   
}