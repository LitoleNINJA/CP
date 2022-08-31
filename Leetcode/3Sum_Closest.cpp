class Solution {
public:
    // 1. If a[first] + a[second] + a[third] is smaller than the target, we know we have to increase the sum. So only choice is moving the second index forward.
    // 2. If the sum is bigger than the target, we know that we need to reduce the sum. so only choice is moving 'third' to backward.
    // 3. While doing this, collect the closest sum of each stage by calculating and comparing delta. Compare abs(target-newSum) and abs(target-closest).
    // 4. If no exactly matching sum has been found so far, the value in closest will be the answer.
    int threeSumClosest(vector<int>& a, int target) {
        int n = a.size();
        sort(a.begin(), a.end());
        int ans = a[0] + a[1] + a[2];
        for (int i = 0; i < n - 2; i++)
        {
            int l = i + 1, r = n - 1;
            while (l < r)
            {
                int sum = a[i] + a[l] + a[r];
                if (sum == target)
                    return  sum;
                if (abs(target - sum) < abs(target - ans))
                    ans = sum;
                else if (sum < target)
                    l++;
                else
                    r--;
            }
        }
        return ans;
    }
};