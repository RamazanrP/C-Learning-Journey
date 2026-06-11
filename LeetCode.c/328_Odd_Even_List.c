#include <stdio.h>
// Array veya başka bir Linked yaratmadan sadece indekse göre (1-based index) tekleri sırasıyla, çiftleri de bunun ardına sırasıyla 
struct ListNode {
    int val;
    struct ListNode *next;
};
// Linked List => 1 -> 2 -> 3 -> 4 -> 5 olsun
struct ListNode* oddEvenList(struct ListNode* head) {
if(!head || !head->next || !head->next->next) return head;
struct ListNode* tek = head;
struct ListNode* ciftbas = head->next;
struct ListNode* cift = ciftbas; // En sonda bağlamak için lazım
while(cift && cift->next){
    tek->next = tek->next->next; // 1'den sonra 3 gelsin 1 -> 3 -> 4 -> 5 (2 kayboldu bak!)
    tek = tek->next;    // Tek artık 3'ü gösteriyor
    cift->next = cift->next->next; // 2'den sonra 4 gelsin 2 -> 4 -> 5
    cift = cift->next; // Cift artık 2'yi gösteriyor
}
/* İlk Döngü Sonu : Tek zincir: 1 → 3 → 4 → 5 → NULL (3'ten sonra 4 var)
                    Çift zincir: 2 → 4 → 5 → NULL*/
/*İkinci Döngü Sonu: Tek zincir: 1 → 3 → 5 → NULL (tek artık 5)
                    Çift zincir: 2 → 4 → NULL (5'in next'i NULL)*/
// Cift artık NULL, döngüden çıktı. Head şu an 1 -> 3 -> 5'i gösteriyor (tek hala 5'i gösteriyor)
// 5'in arkasına ciftbas'ı bağladık mı tmmdrı
tek->next = ciftbas;
return head;
}