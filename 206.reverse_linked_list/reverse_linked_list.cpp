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
    ListNode *reverseList(ListNode *head) {
        ListNode *current = head;
        ListNode *previous = NULL;
        while (current) {
            ListNode *temp = current->next;
            current->next = previous;
            previous = current;
            current = temp;
        }
        return previous;
    }

    void insertAtTail(ListNode *head, int value) {
        if (!head) return;
        ListNode *listPointer = head;
        while (listPointer->next) {
            listPointer = listPointer->next;
        }
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
};

int main() {
    Solution result;
    ListNode *inputList = new ListNode(1);
    result.insertAtTail(inputList, 2);
    result.insertAtTail(inputList, 3);
    result.insertAtTail(inputList, 4);
    result.insertAtTail(inputList, 5);
    result.printList(inputList);
    result.printList(result.reverseList(inputList));

    return 0;
}