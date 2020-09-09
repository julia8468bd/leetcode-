#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int r2, temp;
        vector<int> r;

        for(int i=0; i<nums.size(); i++){
            r2 = target - nums[i];
            for(int j = i; j<nums.size(); j++){
                if(nums[j] == r2 && i!=j){
                    r.push_back(i);
                    r.push_back(j);
                }
            }
        }

        return r;
    }
};

int main()
{
    Solution s;
    vector<int> testCase = {2,7,11,15};
    int target = 9;

    vector<int> answer = s.twoSum(testCase, target);

    cout << "[";
    for(int i=0; i<2; i++){
        cout << answer[i];
        if(i!=2-1){
            cout << ", ";
        }
    }
    cout << "]";
}
