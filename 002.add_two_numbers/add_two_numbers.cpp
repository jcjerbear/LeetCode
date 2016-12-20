#include <iostream>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
    	int sum = 0;
    	ListNode *head = new ListNode(0);
    	ListNode *tail = head;

    	while(l1!=NULL || l2!=NULL || sum)
    	{
    		if(l1!=NULL)
    		{
    			sum += l1->val;
    			l1 = l1->next;
    		}
    		if(l2!=NULL)
    		{
    			sum += l2->val;
    			l2 = l2->next;
	   		}
    		tail->next = new ListNode(sum%10);
			tail = tail->next;
			sum /= 10;
    	}
    	return head->next;
    }
};

int main(int argc, char* argv[])
{
	Solution list;
	ListNode *result;

	ListNode list1Head(2);
	ListNode list1Body1(4);
	ListNode list1Body2(3);
	list1Head.next = &list1Body1;
	list1Body1.next = &list1Body2;
	list1Body2.next = NULL;

	ListNode list2Head(5);
	ListNode list2Body1(6);
	ListNode list2Body2(4);
	list2Head.next = &list2Body1;
	list2Body1.next = &list2Body2;
	list2Body2.next = NULL;

	cout<<"l1: "<<list1Head.val<<"->"<<list1Head.next->val<<"->"<<list1Head.next->next->val<<endl;
	cout<<"l2: "<<list2Head.val<<"->"<<list2Head.next->val<<"->"<<list2Head.next->next->val<<endl;

	result = list.addTwoNumbers(&list1Head, &list2Head);
	while(result!=NULL)
	{
		if(result->next == NULL) cout<<result->val;
		else cout<<result->val<<"->";
		result = result->next;
	}
	cout<<endl;
	return 0;
}
