#include <vector>
#include <stack>
#include <iostream>
#include <string>
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
    stack<ListNode> list1,list2;
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
        struct ListNode* res = NULL,* ldes_head = NULL,* temps = NULL;
        int flag = 0;
        int num = 0;
        temp1 = lde1_head;
        temp2 = lde2_head;
        cout << "addTwoNumbers" << endl;
        while(temp1 != NULL) {
            list1.push(*temp1);
            temp1 = temp1->next;
        }
        while(temp2 != NULL) {
            list2.push(*temp2);
            temp2 = temp2->next;
        }
        /*add*/
        while(list1.size() >0 || list2.size() >0) {
            if(list1.size() >0) {
                num += list1.top().val;
                list1.pop();
            }
            if(list2.size() >0) {
                num += list2.top().val;
                list2.pop();
            }
            if (flag) {
                num +=1;
                flag = 0;
            }
            if(num >= 10) {
                flag = 1;
                num %= 10;
            }
            res = new ListNode;
            res->val = num;
            num = 0;
            if(!ldes_head)
                ldes_head = res;
            if(temps) {
                temps->next = res;
            }
            temps = res;
            temps->next = NULL;
        }

        return ldes_head;
    }
    ListNode* reversalNumbers() {
        struct ListNode* res = NULL,* ldes_head = NULL,* temps = NULL;
        struct ListNode* next = NULL,*pre = NULL;
        temp1 = lde1_head;
        while(temp1) {
            next = temp1->next;
            temp1->next = res;
            res = temp1;
            temp1 = next;
        }
        ldes_head = res;
        temps = ldes_head;
        cout << "res 2  = " << endl;
        while(temps) {
            cout << temps->val;
            temps = temps->next;
        }
        cout << endl;
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
        cout << "del..." << endl;
        temp1 = lde1_head;
        temp2 = lde1_head;
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
        cout << endl;
    }
    //无重复字符的最长子串
    int lengthOfLongestSubstring(string s) {
        int result[50000] = {1};
        int max = 1,flag = 0,y = 0;
        for(int i=0; i<s.size()-1; i++) {
            for(y = i+1;y < s.size()-2;y++) {
                
                if(s[y] != s[y+1]) {
                    result[i]++;
                }
                else
                    break;
            }
        }
        for(int x = 0;x<s.size()-1;x++) {
            if (result[x] > max)
                max = result[x];
        }
        cout << max << endl;
    }
};