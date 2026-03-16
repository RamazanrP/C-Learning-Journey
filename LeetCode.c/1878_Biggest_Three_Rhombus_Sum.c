// Soru bizden verilen matriste çevreleri(içinde yazan sayılar) toplamı en büyük olan 3 eşkenar dörtgeni istiyor
// Biz bir tane tepe noktası seçip 4 yolu toplamak yerine her [i][j]'yi merkez kabul edip dört tarafa genişleyeceğiz
void enBuyukUclu(int* top, int deger){ // En büyük 0'dan 2'ye
    if(deger == top[0] || deger==top[1] || deger==top[2]) return;
    if(deger>top[0]){
        top[2] = top[1];
        top[1] = top[0];
        top[0] = deger;
    }else if(deger>top[1]){
        top[2] = top[1];
        top[1] = deger;
    }else if(deger > top[2]) top[2] = deger;
}
int* getBiggestThree(int** grid, int gridSize, int* gridColSize, int* returnSize) {
int top[3] = {-1,-1,-1}; // En sonda return ederken acaba -1 klamış mı diye kontrol edeceğiz. -1 olmayanları sonuca atayacağız
int i,j;
int satir = gridSize, sutun = gridColSize[0];
for(i=0;i<satir;i++){
    for(j=0;j<sutun;j++){
        enBuyukUclu(top,grid[i][j]); // Alanı 0 olan yani tek kareler de kabul edildiği için her birini kontrol edeceğiz
        int k=1; // Önceki satırda k=0 için yaptık. Şimdi kenarı 1 olan(1 adım gerektiren) dörtgenler için hesaba başladık, giderek genişleyecek
        while(1){
            if(i-k<0 || i+k >= satir || j-k<0 || j+k >= sutun) break;
            int toplam = 0;
            for(int t=0;t<k;t++){
                toplam += grid[i-k+t][j+t]; // En tepeden başlar sağ köşeye kadar
                toplam += grid[i+t][j+k-t]; // En sağdan başlar en alt köşeye kadar
                toplam += grid[i+k-t][j-t]; // En alttan başlar en sol köşeye kadar
                toplam += grid[i-t][j-k+t]; // En soldan başlar en üst köşeye kadar
            }
            k++; // Bir tane dörtgeni tamamlayınca kenarı büyütüyoruz ve şu an elde ettiğimizi kontrole gönderiyoruz
            enBuyukUclu(top,toplam);
        }
    }
}
int sayac=0;
for(i=0;i<3;i++){
    if(top[i] != -1) sayac++; // Kaç tane geçerli dörtgen elde ettiğimizi döndürelim
}
*returnSize = sayac;
int* sonuc = (int*)malloc(sizeof(int)*sayac);
for(i=0;i<sayac;i++) sonuc[i] = top[i];
return sonuc;
}