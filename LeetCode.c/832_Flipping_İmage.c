int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes) {
// Neden int** -> tek yıldız, diziyi tutar, Bize matris lazım, iki boyutlu olduğu için adresin ADRESİNİ tuttuk
// imageSize -> Sadece bir sayı, 3 tane satırı olduğunu söylüyor. Adrese gerek yok, yı yeter bize.
// **ColumnSizes -> Bir şeyi okuyup geri vereceksek çift yıldız. Sadece okusaydık tek yıldız. Dönecek Sütun listesi bu.   
// 1. HAFIZA AYIRMA
int** sonuc = (int**)malloc(imageSize * sizeof(int*)); //Matris olduğu için satır adresinin içinde sütun adresini de almak lazım
// (int*) dememizin sebebi biz sayı istemiyoruz, adres istiyoruz. Adres için posta kutusu ayırdık yıldız koyarak
*returnSize = imageSize;
*returnColumnSizes = (int*)malloc(imageSize * sizeof(int)); //Burada (int) çünkü bize sayı lazım

for (int i = 0; i < imageSize; i++) {
    int sutun = imageColSize[i];
    sonuc[i] = (int*)malloc(sutun * sizeof(int)); // apartman(sonuc)ın i. katına git ve okuduğun sütun kadar oda inşa et.
    (*returnColumnSizes)[i] = sutun; //ColSizes bize ** olarak gelmişti, bir kere zarfı açmak için * dedik ama önce parantez kullanmalı
    // Zarfı açtık, içindeki i diyor ki "bu apartmanın i. katı sutun elemanlıdır" diye not düşüyor
    // Zarfı açmak bir eylem olduğu için başta * koyduk. Değişken tanımlama olsaydı int* olurdu,  (int*) -> bu veriyi al, tamsayı adresine dönüştür demek
    // 2. TERS ÇEVİRME VE 0-1 DEĞİŞTİRME
    for (int j = 0; j < sutun; j++) {
        // Ters çevirmek için sondan başa doğru okuyoruz: [sutun - 1 - j]
        int deger = image[i][sutun - 1 - j];
            
        if (deger == 0) sonuc[i][j] = 1; //  0'ı 1, 1'i 0 yapıyoruz ama ters okuyup düz i j'ye yazdırıyoruz
        else sonuc[i][j] = 0;
    }
}

return sonuc;
}