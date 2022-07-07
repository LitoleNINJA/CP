class Solution {
public:
    int search(vector<int>& a, int t) {
        int n = a.size();
        int l = 0, r = n - 1;
        // Find point of rotation
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (a[mid] > a[r])
                l = mid + 1;
            else
                r = mid;
        }
        int rot = l;

        // Binary search & accounting for rotation
        l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int cmid = (mid + rot) % n;
            if (a[cmid] == t)
                return cmid;
            else if (a[cmid] < t)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};