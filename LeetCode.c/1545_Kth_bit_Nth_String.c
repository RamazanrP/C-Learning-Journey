char findKthBit(int n, int k) {
if (n==1)  return '0';
int uzunluk = (1 << n) - 1;  // veya math.h ekleyip pow(2,n) derdik. 32.0 dönerdi. 1 << n demek 1'i n kadar sola götür demek. 2^n olmuş oluyor
int mid = uzunluk/2 + 1;
if(k==mid) return '1'; // Hızlanma açısından if'e sokuyoruz
if(k<mid) { // k, ortadaki 1'in solunda ise sistem öncekine baksın diyoruz
    return findKthBit(n-1,k);
}
// Bu iki ihtimalde olmadıysa demek ki k, sağda kalıyor. Burada REVERSE düşüneceğiz
char bit = findKthBit(n-1,uzunluk+1-k); // k'nın baştan kaçıncı olacağını hesaplayıp, öncekindeki halini buluyoruz
return (bit=='0') ? '1':'0'; // Gene hızlı kullanım if-else'in
}