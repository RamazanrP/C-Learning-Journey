#include <stdio.h>
#include <stdlib.h>
struct ListNode{
    int val;
    struct ListNode *next;
}; // Listemiz 3->2->0->4->2... olsun Yani döngü 2'den başlıyor 2->0->4 sürekli devam ediyor kısacası
// Listede döngü var mı varsa nerede başlıyor (geri döndüğünde hangi indise bağlanıyor) onu; yoksa NULL'ı döndüren kod
// Burada matematik devreye girecek:
// head'den döngü başına kadar A, Döngü başından karşılaşma noktasına kadar B, Karşılaşmadan tekrar döngü başına dönene kadar yol C
// Döngünün tam uzunluğu B+C. slow, A+B kadar gider, karşılaşırlar. fast de o zaman 2A+2B kadar gitmiştir. 
// fast, hızlı olduğunda A'yı geçer, bir tam tur atar ve B kadar ilerleyip slow'a çarpar. A+B+ 1 tur = 2A+2B yani A+B = B + C => $A=C$
// fast 1 tam tur atınca karçılaşacaklarının garantisi yok. Gerçek formül şu: 2(A+B) = A + B + n.tur => A = (n-1).tur + C :)
struct ListNode *detectCycle(struct ListNode *head) {
if(head == NULL || head->next == NULL) return NULL;
struct ListNode *slow = head, *fast = head;
while(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast){ // Döngü olduğunu yakaladık, 4'te karşılaştı ( 3 2 0 '4' 2 0 '4' )
        slow = head; // slow, en başa geldi. Döngü başına gidene kadar gideceği yol A
        while(slow != fast){ // fast, karşılaşma noktasında. Onun da döngüye geri dönmek için gideceği yol C
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
}
return NULL; // Döngü yoksa mecburen fast pointer'ı NULL'a gelecek ve de while'dan çıkacak
}