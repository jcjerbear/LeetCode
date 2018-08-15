#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *dummyNode = new ListNode(INT_MIN);
        ListNode *iterator = dummyNode;

        if (!l1 && !l2) {
            return nullptr;
        } else if (!l1 && l2) {
            return l2;
        } else if (l1 && !l2) {
            return l1;
        } else {
            while (l1 && l2) {
                if (l1->val < l2->val) {
                    iterator->next = l1;
                    l1 = l1->next;
                } else {
                    iterator->next = l2;
                    l2 = l2->next;
                }
                iterator = iterator->next;
            }
            iterator->next = l1 ? l1 : l2;
            return dummyNode->next;
        }
    }

    void printList(ListNode *list) {
        while (list) {
            if (!list->next) {
                cout<<list->val;
                list = list->next;
            } else {
                cout<<list->val<<"->";
                list = list->next;
            }
        }
    }
};

int main() {
    Solution result;

    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    result.printList(result.mergeTwoLists(l1, l2));
    return 0;
}