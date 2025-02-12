#include <iostream>
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
void ChangeNode(ListNode operand_node, ListNode next_node) {
    operand_node.next = &next_node;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode list1_node = *list1; //If next != nullptr later
        ListNode list2_node = *list2;
        ListNode list_buffer(0, nullptr);
        ListNode list_buffer2(0, nullptr);

        while (true) {
            if (list1_node.val < list2_node.val && list2_node.next != nullptr) {
                list_buffer = NextNode(list1_node);
                ChangeNode(list1_node, list2_node);
                list1_node = list_buffer;
            }
            else if (list1_node.val >= list2_node.val && list1_node.next != nullptr) {
                list_buffer = NextNode(list2_node);
                ChangeNode(list2_node, list1_node);
                list_buffer2 = NextNode(list1_node);
                ChangeNode(list1_node, list_buffer);
                list2_node = list_buffer;
            }
            else {
                break;
            }
        }

        return &list2_node;
    }
};

int main() {
    Solution sol;
    ListNode one_third(4, nullptr);
    ListNode one_second(2, &one_third);
    ListNode one_first(1, &one_second);

    ListNode two_third(4, nullptr);
    ListNode two_second(3, &two_third);
    ListNode two_first(1, &two_second);

    ListNode* buffer = sol.mergeTwoLists(&one_first, &two_first);
    std::cout << "TESTING: ";
    std::cout << buffer->val << " ";
    std::cout << buffer->next->val << " ";
    std::cout << buffer->next->next->val << " ";
    std::cout << buffer->next->next->next->val << " ";
    std::cout << buffer->next->next->next->next->val << " ";
    std::cout << buffer->next->next->next->next->next->val << " ";

}