class Solution {
public:
    int findMin(vector<int>& a) {
        int l = 0, r = a.size() - 1;
        while (l < r)
        {
            if (a[l] < a[r])
                return a[l];
            int mid = (l + r) / 2;
            if (a[mid] >= a[l])
                l = mid + 1;
            else
                r = mid;
        }
        return a[l];
    }
};