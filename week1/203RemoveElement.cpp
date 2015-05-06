#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};//struct ListNode

class Solution{
public:
    ListNode* removeElements(ListNode* head, int val){
        if(NULL == head){
            return head;
        }
        ListNode* current = head;
        while(current->next != NULL){
            if( val == current->next->val){
                ListNode* tmp = current->next;
                current->next = tmp->next;
                cout<<"delete val"<<endl;
                delete tmp;
            }else{
                current = current->next;
            }
        }
        
        if(val == head->val){
            ListNode* delHead = head;
            head = head->next;    
            cout<<"delete head"<<endl;
            delete delHead;
        }
        return head;
    }

};//class Solution


int main(){
    Solution testSolution;
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(1);
    a->next = b;
    b->next = c;
    ListNode* result = testSolution.removeElements(a, 1);
    cout<<result->val<<endl;
    return 0;
}
