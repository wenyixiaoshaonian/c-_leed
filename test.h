#include <vector>
#include <stack>
#include <iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  
class Solution {

private:
    ListNode * lde1,* lde2;
    ListNode * lde1_head, * lde2_head;
    ListNode * temp1, * temp2;
public:
    Solution() {
        lde1 = NULL;
        lde2 = NULL;
        lde1_head = NULL;
        lde2_head = NULL;
        temp1 = NULL;
        temp2 = NULL;
    }
    ~Solution() { del_lde(); }
    vector<int> twoSum(vector<int>& nums, int target) {
        int x,y;
        for(x = 0;x<nums.size()-1;x++) {
                for(y = x + 1;y<nums.size();y++) {
                    if((nums[x] + nums[y]) == target) {
                        return {x,y};
                    }   
                }
        }
        return {x,y};
    }
    ListNode* addTwoNumbers() {
        stack<ListNode> list1,list2;
        temp1 = lde1_head;
        temp2 = lde2_head;
        while(temp1 != NULL) {
            list1.push(*temp1);
            temp1 = temp1->next;
        }
        while(list1.size() >0) {
            cout << list1.top().val;
            list1.pop();
        }
        while(temp2 != NULL) {
            list2.push(*temp2);
            temp2 = temp2->next;
        }
        while(list1.size() >0) {
            cout << list1.top().val;
            list1.pop();
        }
    }
    void create_lde() {
        for(int x = 0;x< 5;x++) {
            lde1 = new ListNode;
            lde2 = new ListNode;
            lde1->val = x+1;
            lde2->val = x+2;
            
            if(lde1_head == NULL && lde2_head == NULL) {
                lde1_head = lde1;
                lde2_head = lde2;
            }
            else if (temp1 != NULL && temp2 != NULL){
                temp1->next = lde1;
                temp2->next = lde2;
            }
            temp1 = lde1;
            temp2 = lde2;
            temp1->next = NULL;
            temp2->next = NULL;
        }
    }
    void del_lde() {
        temp1 = lde1_head;
        temp2 = lde2_head;
        while(temp2 != NULL) {
            cout << temp2->val;
            temp2 = temp1->next;
            delete temp1;
            temp1 = NULL;
            temp1 = temp2;
        }
        cout << endl;
        temp1 = lde2_head;
        temp2 = lde2_head;
        while(temp2 != NULL) {
            cout << temp1->val;
            temp2 = temp1->next;
            delete temp1;
            temp1 = NULL;
            temp1 = temp2;
        }
    }
};