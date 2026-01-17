//Alan = İndisler arası fark x Min boy (su en fazla min tahtanın boyu kadar doldurulabilir çünkü)
int minbul(int sol, int sag, int* height){                  // HIZ İSTESEYDİK
    int minboy;                                             //  #define MIN(a,b) (((a)<(b))?(a):(b))
    if(height[sol] > height[sag]){                          //  #define MAX(a,b) (((a)>(b))?(a):(b))
        minboy = height[sag];                               //  int maxArea(int* height, int heightSize) {
    }else{                                                  //  int sol=0, sag=heightSize-1, maxalan=0;
        minboy = height[sol];                               //  while(sol<sag){
    }                                                       //  int h_sol = height[sol], h_sag=height[sag];
    return minboy; // return değer vermek zorundayız        //  int guncel_h = MIN(h_sol, h_sag);
}                  //int diye de tanımlamak zorunluluk!     //  int guncel_alan = (sag - sol) * guncel_h;
int alanbul(int sol, int sag, int* height){                 //  if (guncel_alan > maxalan) maxalan = guncelalan;
    int zemin = sag-sol;                                    //  if (h_sol < h_sag) sol++;
    int yukseklik = minbul(sol,sag,height);                 //  else sag--;
    int alan = zemin*yukseklik;                             //  return maxalan;
    return alan;                                            //  }
}
int maxArea(int* height, int heightSize) {
int adet = heightSize;
int maxalan=0;
int sol=0,sag = adet-1;
while(sol<sag){
    int guncelalan = alanbul(sol,sag,height);
    if(guncelalan > maxalan) maxalan = guncelalan;
    if(height[sol] > height[sag]) sag--; //En büyüğü bulmak için kısa kenarı atıyoruz.
    else sol++;
}
return maxalan;
}