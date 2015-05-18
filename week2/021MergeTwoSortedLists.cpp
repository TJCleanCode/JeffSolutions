#include <iostream>
#include <cassert>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution{
public:
    //Pre-condition: Two lists are sorted.
    //@param l1: the head of the first list
    //@param l2: the head of the second list
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(l1 == NULL || l2 == NULL){
            return (l1 == NULL) ? l2 : l1;
        }

        ListNode preHead(0);
        ListNode *current = &preHead;
        while((l1!=NULL)&&(l2!=NULL)){
            if(l1->val < l2->val){
                current->next = l1;
                current = current->next;
                l1 = l1->next;
            }else{
                current->next = l2;
                current = current->next;
                l2 = l2->next;
            }
        }

        current->next = (l1 == NULL)? l2:l1;

        return preHead.next;
    }


};


void testSolution(){
    Solution solution;
    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(3);
    ListNode *a3 = new ListNode(5);
    a1->next = a2;
    a2->next = a3;

    ListNode *b1 = new ListNode(2);
    ListNode *b2 = new ListNode(4);
    ListNode *b3 = new ListNode(6);
    b1->next = b2;
    b2->next = b3;

    ListNode *head = solution.mergeTwoLists(a1, b1);
    while(head){
        std::cout<<head->val<<std::endl;
        head = head->next;
    }
}

int main(){
    testSolution();

    return 0;
}

