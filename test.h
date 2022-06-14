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
public:
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode> list1,list2;
        while(l1 != NULL) {
            list1.push(*l1);
            l1 = l1->next;
        }
        while(list1.size() >0) {
            cout << list1.top();
            list1.pop();
        }
        while(l2 != NULL) {
            list2.push(*l2);
            l2 = l2->next;
        }
    }
};