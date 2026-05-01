#include <stdio.h>
#include <stdlib.h>
// 1-index based liste verilmiş. Birer birer gidiyor. Left ve right verilmiş. Left ve Right arasını ters çevirmemizi istiyor
struct ListNode {
    int val;
    struct ListNode *next;
 };
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
if(head == NULL || left ==right) return head; // Boş veya tek elemanlıysa
struct ListNode dummy; // Eğer en baştan ters çevir derse head değişebilir. Bu durumda kod patlar. Önlem alıyoruz.  
dummy.next = head;
struct ListNode* prev = &dummy;
for(int i=0; i< left-1; i++) prev = prev->next;
struct ListNode* current = prev->next; // Çevirmenin başına yani Left'e gider. VE SABİT KALIR. Prev'den sonrası değişecek unutma!
struct ListNode* sonrasi = current->next; // Left'in hemen sonrasına gider
for(int i=0; i< right-left;i++){ // 1 2 3 4 5 için 2 ve 4 derse biz önce 3'ü alır 1-2 araına sokarız, sonra 4'ü alır 1-3 arasına koyarız
    // Şu an 1->prev 2->current 3->sonrasi
    current->next = sonrasi->next; // 1- 3'ü aradan çıkar, 2 ile 4'ü bağla
    sonrasi->next = prev->next;    // 2- Havada kalan 3'e dedik ki senden sonra 1'in next'i gelsin. Yani şu an 3 -> 2 oldu
    prev->next = sonrasi; // dummy.next=sonrasi
    // 3- Önceki adım yüzünden 1'in next'i gitmişti. liste 3'den başlıyordu. Artık 1'i, başa koyduk. 1->3->2
    sonrasi = current->next;       // 4- İlk adımdan sonra 2->4 olmuştu. Artık sonrasi 3 değil 4 oldu. 
}
return dummy.next; // En sonda dummy.next = şu demeye gerek yok.prev=&dummy satırı sayesinde dummy her zaman en başın öncesini tutar
}