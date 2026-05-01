#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* reverseList(struct ListNode* head) {
if(head == NULL) return NULL;
// prev: Şu anki düğümün yeni hedefi olacak (arkadaki vagon).
// next: Bağlantı koptuğunda listenin geri kalanını tutacak (yedekçi).
// current: Üzerinde işlem yaptığımız vagon.
struct ListNode *prev=NULL, *next=NULL, *current=head;
while(current){
    next = current->next; // current->next bağını kopardığımızda listenin ilerisini kaybetmemek için devamı yedekliyoruz.
    current->next = prev; // Şu anki vagon artık önündekini değil, arkasındaki vagonu gösteriyor. Şu an bağı kopardık ama yukarda yedeği var
    prev = current; // 'prev' artık şu anki vagonun üzerine gelsin. (sonraki adımda 2. kutuya geldik mi ikinin göreceği şey 1. kutu olsun (Yukardaki satıra bak!))
    current = next; // 1. adımda next'e "2'yi tut" demiştik. Şimdi current'ı next'in yanına, yani 2 numaraya gönderiyoruz.
}  // prev'i de current'ı da birer adım ilerlettik yani
return prev; // Döngü bittiğinde 'current' NULL olur, 'prev' ise listenin yeni başı (eski sonu) olur.
}