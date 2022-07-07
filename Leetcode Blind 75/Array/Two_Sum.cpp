class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        vector<int> ans;
        if (n == 2)
        {
            ans.push_back(0);
            ans.push_back(1);
        }
        else
        {
            unordered_map<int, int> m;
            for (int i = 0; i < n; i++)
                m[nums[i]] = i;
            for (int i = 0; i < n; i++)
            {
                int temp = target - nums[i];
                if (m.find(temp) != m.end() && m[temp] != i)
                {
                    auto itr = m.find(temp);
                    ans.push_back(i);
                    ans.push_back(itr->second);
                    break;
                }
            }
        }
        return ans;
    }
};