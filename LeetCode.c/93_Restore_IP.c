#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
bool isValid(char *s, int start, int len){
    if(len > 3) return false;
    if(s[start] == '0' && len != 1) return false;
    int num = 0;
    for(int i=0; i<len; i++){
        num = num * 10 +(s[start+i] - '0');
    }
    return num<256 ;
}

void backtrack(char* s, int startIndex, int partCount, char* currentIP, int currentIPLen, char** result, int* returnSize){
    if(partCount == 4){
        if(s[startIndex] == '\0'){ // Eğer 4 kutucuğa ulaşıp da diziyi bitirmişsek bunu result'a kaydedelim
            currentIP[currentIPLen] = '\0';
            result[*returnSize] = (char*)malloc((currentIPLen + 1) * sizeof(char));
            strcpy(result[(*returnSize)], currentIP);
            (*returnSize) += 1;
        }
        return; // 4 parçaya rağmen elde harf kalmışsa yanlış yoldayız
    }
    if(s[startIndex] == '\0') return; // 4 parça elde etmeden bittiyse yanlış yoldayız
    for(int i=1; i<=3; i++){ // Uzunluklar 1-3 arası
        
        if(startIndex+i > strlen(s)) break; // Sınırı aşmayalım
        
        if(isValid(s,startIndex,i)){ // i kadar haneyi kontrol edeceğiz
            for(int j=0; j<i; j++){ // Geçerliyse verilen string'ten current'a kaydet
                currentIP[currentIPLen + j] = s[startIndex + j];
            }
            if(partCount < 3){ // Eğer son kutucuğa gelmediysek current'ın en sonuna nokta koy ve i+1 kadar ilerle
            currentIP[currentIPLen + i] = '.';
            backtrack(s,startIndex + i, partCount+1, currentIP, currentIPLen + i + 1, result, returnSize);
        }else{
            backtrack(s,startIndex + i, partCount+1, currentIP, currentIPLen + i, result, returnSize);
        }
        } 
    }
}

char** restoreIpAddresses(char* s, int* returnSize) {
    *returnSize = 0;
    char** res = (char**)malloc(100 * sizeof(char*)); // Fazla yer ayırdık gibi gözükse de sorun yok, LeetCode returnSize'a göre okuma yapacak
    char path[16]; // Geçici string en fazla 15 harf + 1 null = 16 karakter olur
    backtrack(s, 0, 0, path, 0, res, returnSize);
    // by value ile aktardığımız için backtrack içindeyken startIndex artsa bile
    // bizim için sorun yok, biz hep en baştan, yeni, temiz bir sayfayla denemeye başlayacağız. Hatalı yolu silmekle uğraşmıyoruz
    
    return res;
}