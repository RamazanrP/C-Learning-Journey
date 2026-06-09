#include <stdio.h>
#include <stdlib.h>
/*
L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
*/
// slow-fast kullanarak ortancı düğümü bulacağız. Ortanca her zaman sonda kalıyor çünkü
struct ListNode {
    int val;
    struct ListNode *next;
};
// --- YARDIMCI REVERSE FONKSİYONU --- //
struct ListNode* reverse(struct ListNode* head){
    struct ListNode* prev = NULL;
    struct ListNode* temp;
    while(head){
        temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}
// --- MAİN FONKİYON --- // 
void reorderList(struct ListNode* head) {
if(!head || !head->next || !head->next->next) return;
// --- ORTANCAYI BULMA --- //
struct ListNode* slow=head, *fast = head;
while(fast->next && fast->next->next){
    slow = slow->next;
    fast = fast->next->next;
}
// --- İKİNCİ YARIYI TERS ÇEVİRME --- //
struct ListNode* ikinci_yarim = slow->next;
struct ListNode* tershead = reverse(ikinci_yarim); // En baştan ters çevirmeye gerek yok. İkinci yarısını ters çevirip bi ondan bi bundan dicez
slow->next =  NULL; // ZORUNLUYDU!
// --- NORMAL VE TERS LİSTELERİ SIRASIYLA EKLEME --- //
struct ListNode* current = head; 
struct ListNode* normalhead = head->next; // Bağlama işlemleri next ile ilerlesin diye head'in next'inden başlattık
int sira = 0;
while(normalhead != NULL || tershead != NULL){ // Her iki zincirde de Node olduğu sürece devam
    if(!sira && tershead){
        current->next = tershead;
        current = current->next; // Manuel olarak ilerletiyoruz, current = tershead demek yerine önce next ile bağladık sonra ilerlettik
        tershead = tershead->next;
        sira = 1;
    }else if(sira && normalhead){ // Yukarda slow->next = NULL dediğimiz için olması gerektiği gibi ilk yarıya kadar ilerlicek normalhead
        current->next = normalhead;
        current = current->next;
        normalhead = normalhead->next;
        sira = 0;
    }
}
// void olduğu için "return head" demek yok,  o hataya düşmeyin aman :)
}