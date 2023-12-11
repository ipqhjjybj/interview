/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        while(cur!=NULL) {
            // 保存一下 cur的下一个节点，因为反转当前节点之后还需要继续往后走
            // 防止链表断掉
            ListNode* cur_next = cur->next;
            // 反转  
            cur->next = pre;
            // 往后走
            pre = cur;
            cur = cur_next;
        }
        return pre;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //两个指针一起走、n为多少两个指针离多远
        //这样只需要遍历一次就可以得到最终的结果
        ListNode* dummy = new ListNode(0, head);//哑节点
        ListNode* pb = head;
        ListNode* pa = dummy;
        for (int i = 0; i < n; ++i) {
            pb = pb->next;
        }
        while (pb) {
            pa = pa->next;
            pb = pb->next;
        }
        pa->next = pa->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
