#include <stdio.h>

// Haritadaki toplam hücre sayısı (Satır x Sütun). 100.000 hücre sınırı koyulmuş.
// Bu sınır hafıza hatalarını (Runtime Error) önler.
#define MAX_TOTAL 100005

int grid[MAX_TOTAL];   // Hızı arttırmak için 
int dist[MAX_TOTAL];   // Her hücrenin 2'ye olan mesafesini tutan dizi
int qX[MAX_TOTAL];     // Kuyruğa giren hücrelerin X (satır) koordinatları
int qY[MAX_TOTAL];     // Kuyruğa giren hücrelerin Y (sütun) koordinatları
int bas = 0;           // Kuyruğun başı (Sırası gelen zombiyi buradan alırız)
int son = 0;           // Kuyruğun sonu (En son yakalanan 3)

// Hareket yönleri: Yukarı (-1,0), Aşağı (1,0), Sol (0,-1), Sağ (0,1)
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    int N, M;
    // Satır (N) ve Sütun (M) sayılarını oku. Okuyamazsan programı kapat.
    if (scanf("%d %d", &N, &M) != 2) return 0;

    // --- 1. ADIM: Haritayı Okuma ve İlk 2'leri Sıraya Dizme ---
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            // 2D koordinatı (i,j), tek boyutlu dizideki yerine çeviriyoruz
            int konum = i*M + j; 
            scanf("%d", &grid[konum]);

            if (grid[konum] == 2) { // Eğer burası bir zombiyse
                dist[konum] = 0;    // Zombinin kendine mesafesi 0'dır
                qX[son] = i;        // İlerde değerlendirmek için i'lerini 0. index 1. index diyerek kaydediyoruz
                qY[son] = j;        // Gene aynı mantık 0. index ilk 2, 1. index 2. 2 gibi
                son++;              //Buradaki taramadan çıkınca son-1 indisi artık bütün 2'lerin indexini tutmuş olacak
            } else {                //2 tane 2 varsa son=2 olup çıkar. 3 geldi mi o son[2]'ye yazılcak
                dist[konum] = -1;   // Daha ulaşılmadığını görmek için dist'te -1 dedik (-1 sadece işaretçi,matematiksel anlamı yok)
            }
        }
    }

    // --- 2. ADIM: Kuyruk Mantığı ---
    // Kuyrukta işlenecek 3 kaldığı sürece devam et
    while (bas < son) {
        int x = qX[bas]; // Sıradaki 2'nin, 2 bitince 1. Dalga-2.Dalga... 3'lerin  satırını al
        int y = qY[bas]; // Sıradaki 2'nin veya yeni ulaşılanın sütununu al
        bas++;           // Bir kere tarama yapılıp bitti mi diğer 2'nin sonra da Dalgaların konumunu çeker

        int suankiKonum = x*M + y; //Şu anki 2'nin/Dalganın konumu

        // Bu 2'nin/Dalganın etrafındaki 4 komşuya bakıyoruz (Sağ, Sol, Alt, Üst)
        for (int i=0; i<4; i++) {
            int yeniX = x + dx[i]; //-1,1,0,0 olan dizimiz
            int yeniY = y + dy[i]; //0,0,-1,1 olan dizimiz
            int yeniKonum = yeniX * M + yeniY; // 2'nin etrafını tarıyoruz 1 kere

            // Komşu haritanın içindeyse
            if (yeniX >= 0 && yeniX < N && yeniY >= 0 && yeniY < M) {
                // Ve bu komşuya hala ulaşılmadıysa (-1 ise)
                if (dist[yeniKonum] == -1) {
                    // Onu bulunca Şuankinin (Önce 2, sonra komşu 3, sonra komşunun komşusu 3'ler...)
                    dist[yeniKonum] = dist[suankiKonum] + 1; // İlk komşu 3 bulunca şuankinin yani 2'nin dist'i +1 = 0+1 yazacak
                    // Yeni bulduğun 3'ü kuyruğun sonuna ekle ki o da başkalarına (Hala ulaşılmadıysa) yaysın
                    qX[son] = yeniX; //Yeni bi 3'e ulaştık mı en sona kaydediyoruz, artık kimse bu 3'e bir daha ulaşamaz
                    qY[son] = yeniY; // Ve yeni ısırılan bir 3'e her zaman en küçük değer yazılmış oluyor
                    son++; //Giderek son artmaycak, ulaşılmıyan 3'ler azaldıkça bas-son farkı azalcak. En sonda while kırılacak
                }
            }
        }
    }

    // --- 3. ADIM: Sonuçları Ekrana Basma ---
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            // Sayıyı yazdır, satır sonundaysan aşağı geç (\n), değilsen boşluk koy (' ')
            // Bu kısım format hatalarını (Wrong Answer) önlemek için!
            printf("%d%c", dist[i*M + j], (j == M-1 ? '\n' : ' '));
        }
    }

    return 0;
}