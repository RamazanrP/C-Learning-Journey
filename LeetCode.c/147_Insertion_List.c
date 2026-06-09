#include <stdio.h>
// Array veya başka bir Linked yaratmadan value'larına göre Node'ları küçükten büyüğe dizmek
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* insertionSortList(struct ListNode* head) {
if(!head || !head->next) return head;
struct ListNode dummy;
dummy.next = NULL; // Yepyeni bir başlangıç için next = NULL diyoruz
struct ListNode* current = head; // Elimizde tuttuğumuz Node
while(current){
    struct ListNode* gecici = current->next; // İLERİYİ GÜVENE AL //
    struct ListNode* gezici = &dummy; // Eğer elimizdeki sayı en küçük sayıysa, onu en başa koyabilmek için en baştan başlaması şart.
    while(gezici->next != NULL && gezici->next->val < current->val){ // Elimizdeki 5-(...) olsun, liste de 1-3-10 olsun
        gezici = gezici->next;
    }
    // Gezici 3'te durdu. 
    current->next = gezici->next; // gezici (3'ten) sonrası bizden büyük, onu ardımıza bağlayalım
    gezici->next = current; // gezici bizden küçük, onun ardından biz gelmeliyiz
    current = gecici; // En başta garantiye aldığımız devam Node'unu üzerimize atayalım, Listede sırasıyla ilerliyoruz artık
}
return dummy.next; 
}