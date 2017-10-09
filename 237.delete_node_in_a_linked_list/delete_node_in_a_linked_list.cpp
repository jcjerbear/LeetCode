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
    /**
     *  Algorithm:
     *
     *  a function to delete a node (except the tail) in a singly linked list, given only access to that node. We are
     *  assumming that we are not going to delete the tail at any time
     */
    void deleteNode(ListNode *node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }

    void insertTail(ListNode *head, int value) {
        if (!head) return;
        ListNode *listPointer = head;
        while (listPointer->next) listPointer = listPointer->next;
        listPointer->next = new ListNode(value);
    }

    void printList(ListNode *head) {
        if (!head) return;
        ListNode *listPointer = head;
        while (listPointer) {
            cout << listPointer->val;
            listPointer = listPointer->next;
        }
        cout << endl;
    }

    ListNode *searchNode(ListNode *head, int value) {
        if (!head) return NULL;
        ListNode *listPointer = head;
        while (listPointer) {
            if (listPointer->val == value) return listPointer;
            else listPointer = listPointer->next;
        }
        return NULL;
    }
};

int main() {
    Solution result;
    ListNode *inputListHead = new ListNode(1);

    result.insertTail(inputListHead, 2);
    result.insertTail(inputListHead, 3);
    result.insertTail(inputListHead, 4);
    result.insertTail(inputListHead, 5);
    result.insertTail(inputListHead, 6);

    result.printList(inputListHead);
    result.deleteNode(result.searchNode(inputListHead, 4));
    result.printList(inputListHead);
    result.deleteNode(result.searchNode(inputListHead, 1));
    result.printList(inputListHead);

    return 0;
}