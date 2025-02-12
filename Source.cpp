
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Returns the next node moving from current one forward
ListNode& NextNode(const ListNode current_node) {
    return (*current_node.next);
}

//Changes the next of the first operand to the address of the second one
ListNode& ChangeNode(ListNode operand_node, ListNode next_node) {
    operand_node.next = &next_node;
    return next_node;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode list1_node = *list1; //If next != nullptr later
        ListNode list2_node = *list2;
        ListNode list_buffer(0, nullptr);
        ListNode list_buffer2(0, nullptr);

        while (list1_node.next != nullptr && list2_node.next != nullptr) {
            if (list1_node.val < list2_node.val) {
                list_buffer = NextNode(list1_node);
                ChangeNode(list1_node, list2_node);
                list1_node = list_buffer;
            }
            else if (list1_node.val >= list2_node.val) {
                list_buffer = NextNode(list2_node);
                ChangeNode(list2_node, list1_node);
                list_buffer2 = NextNode(list1_node);
                ChangeNode(list1_node, list_buffer);
                list1_node = list_buffer2;
            }
        }

        return &list2_node;
    }
};