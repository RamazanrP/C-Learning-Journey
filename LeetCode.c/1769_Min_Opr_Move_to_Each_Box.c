int* minOperations(char* boxes, int* returnSize) {
//Input: boxes = "001011"
//Output: [11,8,5,4,3,4] tüm 1'leri istenen i. kutuya taşımak için gereken toplam adım sayısını yazdırıyoruz.
// Toplam 1 indislerini toplayalım. 1 görmedikçe en soldan başlayalım ve 1 adedi kadar azaltalım
// 1 görünce de görülen 1 kadar arttıralım. Sola gittikçe sağdakilerin uzaklığı azalırken soldakilerinki artıyor.
int n = strlen(boxes);
int* cevap = (int*)malloc(n*sizeof(int));
int sum=0,bir_sayaci=0,i=0;
while(boxes[i] != '\0'){
    if(boxes[i] == '1'){
        sum += i;
        bir_sayaci++;
    }
    i++;
}
*returnSize = n;
i=0;
int soldaki_birler=0,sagdaki_birler=bir_sayaci;
while(boxes[i] != '\0'){
    cevap[i] = sum;
    if(boxes[i] == '1'){ // Sağa doğru giderken 1 gördükçe sağdakiler azalsın soldakiler arttsın. 
        sagdaki_birler--;
        soldaki_birler++;
    }
    sum += soldaki_birler-sagdaki_birler; // 0 da görülse 1 de görülse azalma olacak. Hem de sayaç kere :)
    i++;
}
return cevap;
}