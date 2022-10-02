#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define multi_ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>



class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector<long long> diffs(nums1.size());
        for(int i = 0; i < nums1.size(); i++)
            diffs[i] = nums1[i] - nums2[i];
        
        long long ans = 0;
        multi_ordered_set ms;
        for(int i = nums1.size() - 1; i >= 0; i--){
            ans += ms.size() - ms.order_of_key(diffs[i] - diff);
            ms.insert(diffs[i]);
        }
        
        return ans;
        
        
    }
};