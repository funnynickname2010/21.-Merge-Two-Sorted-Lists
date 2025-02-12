
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode list1_node = *list1->next; //If next != nullptr later
        ListNode list2_node = *list2->next;

        while (list1_node.next != nullptr && list2_node.next != nullptr) {

        }

    }
};