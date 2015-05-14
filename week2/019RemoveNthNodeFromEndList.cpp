#include <iostream>
using std::cout;
using std::endl;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};

class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode* preHead = new ListNode(0);
        preHead->next = head;
        ListNode *p1 = preHead;
        ListNode *p2 = preHead;
        for(int i = 0;i < n;i++){
            p2 = p2->next;
        }
        while(p2->next){
            p2 = p2->next;
            p1 = p1->next;
        }
        ListNode *nthNodeFromEnd = p1->next;
        p1->next = p1->next->next;

        delete nthNodeFromEnd;
        return preHead->next;
    }// ListNode* removeNthFromEnd

}; // class Solution
void testRemovedNode(){
    Solution testSolution;
    for(int i = 1;i < 6;i++){
        ListNode *a = new ListNode(1);
        ListNode *b = new ListNode(2);
        ListNode *c = new ListNode(3);
        ListNode *d = new ListNode(4);
        ListNode *e = new ListNode(5);
        a->next = b;
        b->next = c;
        c->next = d;
        d->next = e;
        ListNode *head = testSolution.removeNthFromEnd(a,i);
        for(int j = 0;j<4;++j){
            cout<<head->val;
            head = head->next;
        }
        cout<<endl;
    }
}
int main(){
    testRemovedNode();
    return 0;
}
