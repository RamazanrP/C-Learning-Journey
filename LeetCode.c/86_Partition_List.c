#include <stdio.h>
#include <stdlib.h>
// Listedeki düğümlerin sırası değişmeyecek, x'ten küçükler önde sıralanacak, >= x'ler de bunun ardına sıralanacak
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* partition(struct ListNode* head, int x) {   
if(!head || !head->next) return head;
struct ListNode *List1, *List2; // Bunları head'e eşitlemicez. Sadece malloc ile yer açıcaz. Next'leri ile sıralicaz
List1 = malloc(sizeof(struct ListNode));
List2 = malloc(sizeof(struct ListNode));
struct ListNode *temp1 = List1; // Listelerin başını tutmak için kullandık çünkü while içinde List1-2 ilerliyor, yerini sabitledik
struct ListNode *temp2 = List2;
List1->next = NULL, List2->next = NULL;
struct ListNode* current = head;
while(current){
    if(current->val < x){
        List1->next = current;
        List1 = current;
        
    }else{
        List2->next = current;
        List2 = current;
        
    }
    current = current->next;
}
List2->next = NULL; // RAM içinden bir şeyler kuyruğa eklenmesin diye!
List1->next = temp2->next; // Dediğim buydu. List2'yi sadece yaratmak için kullandık. Next'leri ile sıralıyoruz.
//  Şimdi de bağladık. temp1->next en küçük sayıyı tutuyor ve liste x'e göre iki birleşik parça halinde teslim ediliyor
return temp1->next; 
}