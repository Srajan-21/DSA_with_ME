class Solution {
public:
    long long ans = 0;

    void mergeSort(vector<int>& pref, int l, int r) {
        if (l >= r) return;

        int mid = l + (r - l) / 2;

        mergeSort(pref, l, mid);
        mergeSort(pref, mid + 1, r);

        // Count pairs (i, j) where i <= mid < j and pref[i] < pref[j]
        int i = l;
        for (int j = mid + 1; j <= r; j++) {
            while (i <= mid && pref[i] < pref[j])
                i++;
            ans += (i - l);
        }

        // Merge the two sorted halves
        vector<int> temp;
        int p1 = l, p2 = mid + 1;

        while (p1 <= mid && p2 <= r) {
            if (pref[p1] <= pref[p2])
                temp.push_back(pref[p1++]);
            else
                temp.push_back(pref[p2++]);
        }

        while (p1 <= mid)
            temp.push_back(pref[p1++]);

        while (p2 <= r)
            temp.push_back(pref[p2++]);

        for (int k = l; k <= r; k++)
            pref[k] = temp[k - l];
    }

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }

        ans = 0;
        mergeSort(pref, 0, n);

        return ans;
    }
};