#include <stdio.h>
//1632. soru
int main () {
long long k=0,answer[500][500],matrix[500][500],temp,min,sayilar[250000][3];
int i,j,p,bitis,N,M,maxRankrow[500],maxRankcol[500],mevcutmax;
printf("Matrisinizin boyutlarini giriniz: ");
scanf("%d %d", &N, &M);
printf("Matrisinizi giriniz: ");
for(i=0;i<N;i++){
    for(j=0;j<M;j++){
        scanf("%lld", &matrix[i][j]);
        answer[i][j] = 0; //ansewer bizim dışarı yansıtacağımız matris
        sayilar[k][0] = matrix[i][j]; //sayılar'ın ilk sütunu büyükten küçüğe bütün sayılar
        sayilar[k][1] = i;            //İkinci sütunu bu küçükten büyüğe sayıların satır numarası
        sayilar[k][2] = j;            // 3. sütunu da satır numaraları
        k++;                          //Bunlar sayesinde aynı satır ve sütunu kontrol edeceğiz çünkü küçükten büyüğe giderken
    }                                 //Bir sayının rankı kendi satır ve sütunundaki en büyük rankın BİR FAZLASIDIR
}
for(i=0;i<N;i++){ //Burada tüm satır ve sütun rankları baştan 0'landı
    maxRankrow[i] = 0;
}
for(i=0;i<M;i++){
    maxRankcol[i] = 0;
}
min = sayilar[0][0];
for(i=0;i<N*M-1;i++){ //Burada sort işlemi yapıyoruz ama sadece sayıları değil onların satır-sütunlarını da taşımamız lazım
    for(j=i+1;j<N*M;j++){
        if(sayilar[j][0] < sayilar[i][0]){
            temp = sayilar[i][0];
            sayilar[i][0] = sayilar[j][0];
            sayilar[j][0] = temp;
            temp = sayilar[i][1];
            sayilar[i][1] = sayilar[j][1];
            sayilar[j][1] = temp;
            temp = sayilar[i][2];
            sayilar[i][2] = sayilar[j][2];
            sayilar[j][2] = temp;
        }
    }
}
k=0;
while(k<N*M){ //i ve j=i*M+j gibi şeyler yazarsak aynı gruptaki eşit sayıların rankı eşit olmaz. Bunun için 
    bitis = k;
    while(bitis<N*M && sayilar[bitis][0] == sayilar[k][0]){ //Aynı grupta eşit sayılar varsa bitişe kadar aynı rankı vercez
        bitis++;
    }    
    for(p=k; p<bitis; p++){
        if(maxRankrow[sayilar[p][1]] > maxRankcol[sayilar[p][2]]){ //aynı roe veya col'daki en büyüğün +1'i yeni rankımız
            answer[sayilar[p][1]][sayilar[p][2]] = maxRankrow[sayilar[p][1]]+1;
        }else{
            answer[sayilar[p][1]][sayilar[p][2]] = maxRankcol[sayilar[p][2]]+1;
        }
    }
    for(p=k; p<bitis;p++){ //Rankımızı yazdık. Şimdi de bu +1 hali en büyük mü diye kontrol edip maxrow ve col'u güncelleyecez
        if(answer[sayilar[p][1]][sayilar[p][2]] > maxRankrow[sayilar[p][1]]){
            maxRankrow[sayilar[p][1]] = answer[sayilar[p][1]][sayilar[p][2]];
        }
        if(answer[sayilar[p][1]][sayilar[p][2]] > maxRankcol[sayilar[p][2]]){
            maxRankcol[sayilar[p][2]] = answer[sayilar[p][1]][sayilar[p][2]];
        }
    }
    k=bitis; // k'nın artık eşit olan sayılardan çıkması ve diğer eşitliklere bakması için en sona çektik
}
for(i=0;i<N;i++){
    for(j=0;j<M;j++){
        printf("%lld ", answer[i][j]); //lld kullanmaya dikkat
    }
    printf("\n");
}
}