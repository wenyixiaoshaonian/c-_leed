#include "test.h"

int main() {
    vector<int> num {-1,-2,-3,-4,-5};
    vector<int> res(2);
    Solution test;
    res = test.twoSum(num,-8);
    cout << res[0] << " " << res[1];

    return 0;
}