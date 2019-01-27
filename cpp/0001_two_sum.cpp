#include <vector>
#include <map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mapNum;
        for (int i=0; i<nums.size(); i++) {
            map<int,int>::iterator it = mapNum.find(target - nums[i]);
            if (it != mapNum.end()) {
                return vector<int>{i, it->second};
            } else {
                if (mapNum.count(nums[i]) <= 0)
                    mapNum.insert(pair<int,int>(nums[i],i));
            }
        }
        return vector<int>{-1, -1};
    }
};