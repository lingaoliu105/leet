#include <vector>
#include <cmath>
#include <tuple>
#include <limits.h>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxValueAfterReverse(vector<int> &nums)
    {
        int size = nums.size();
        int first = nums[0];
        int last = nums.back();
        int maxIncreaseWithFirst = 0;
        int maxIncreaseWithLast = 0;
        int baseArrVal = 0;
        int maxmin = INT_MIN;
        int minmax = INT_MAX;
        for (int i = 0;i<size-1;i++){

            baseArrVal+=abs(nums[i]-nums[i+1]);
            int increaseWithFirst = abs(first-nums[i+1])-abs(nums[i]-nums[i+1]);
            int increaseWithLast = abs(last-nums[i])-abs(nums[i]-nums[i+1]);
            if (increaseWithFirst>maxIncreaseWithFirst) maxIncreaseWithFirst=increaseWithFirst;
            if (increaseWithLast>maxIncreaseWithLast) maxIncreaseWithLast = increaseWithLast;
            if (min(nums[i],nums[i+1])>maxmin) maxmin=min(nums[i],nums[i+1]);
            if (max(nums[i],nums[i+1])<minmax)
                minmax = max(nums[i], nums[i + 1]);
            
        }
        vector<int> v = {maxIncreaseWithFirst,maxIncreaseWithLast,2*(maxmin-minmax),0};
        return baseArrVal+*max_element(v.begin(),v.end() );
    }
};

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    vector<int> v = {2, 4, 9, 24, 2, 1, 10};
    int n = s.maxValueAfterReverse(v); 
    return 0;
}
