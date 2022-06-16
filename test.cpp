#include "test.h"

int main(int argc,char **argv) {
    // vector<int> num {-1,-2,-3,-4,-5};
    // vector<int> res(2);
    Solution test;
    // res = test.twoSum(num,-8);
    // cout << res[0] << " " << res[1];
    struct ListNode* res;

    string s = "abcabcbb";
    test.create_lde();

    // res = test.addTwoNumbers();
    // cout << "res: " << endl;
    // while(res != NULL) {
    //     cout << res->val;
    //     res = res->next;
    // }
    test.lengthOfLongestSubstring(s);
    cout << endl;
    return 0;
}