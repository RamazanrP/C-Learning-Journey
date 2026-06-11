#include <stdio.h>
// Listenin başında ve sonunda 0 değerli Node olacağı garanti ediliyor. Biz, Liste içindeki iki 0 arasındaki değerleri toplayacağız
// Yeni bir Liste yaratamıyorsak biz de 0'ları kullanırız. Bu sıfırdan önceki değerleri toplayıp 0'a yazarız, bir sonraki 0'a bağlarız
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* mergeNodes(struct ListNode* head) {
struct ListNode* curr = head->next;
struct ListNode* prev = head;
int sum = 0;
while (curr && curr->next) {
    if (curr->val != 0) {
        sum += curr->val;
    } else {
        prev->val = sum; // Gerideki 0'ın değerini toplam yap
        prev->next = curr; // Gerideki 0'ın (artık değeri güncel) next'i Şu anki (daha ilerideki) 0 olsun
        prev = curr; // Sum'ı toplayacağımız 0 Node'unu bir ileriye taşıdık. Artık güncel 0 Node'umuz gerideki Node rolünde
        sum = 0;
    }
    curr = curr->next;
}
// Buradan çıktıysa demek ki son Node'a geldik. Next'imiz NULL. Son Node'un da 0 olduğunu biliyoruz
// if (curr->val != 0) {sum += curr->val;}  bloğuna GİRMEDİK. Elimizde sum var ama prev'i (gerideki 0'ın) içini güncellemedik 
prev->val = sum; // Güncelledik
prev->next = NULL; // Artık listeyi bitirdik
return head;
}