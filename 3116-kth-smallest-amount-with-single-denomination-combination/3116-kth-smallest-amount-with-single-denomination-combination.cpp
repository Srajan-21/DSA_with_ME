class Solution {
public:

    long long gcd(long long a, long long b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        
        int n = coins.size();
        int total_subsets = 1 << n;
        
        // Precompute LCM and sign (+1 / -1) for all non-empty subsets
        vector<pair<long long, int>> subset_info;
        subset_info.reserve(total_subsets - 1);

        for (int mask = 1; mask < total_subsets; ++mask) {
            long long current_lcm = 1;
            int count = 0;
            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    current_lcm = lcm(current_lcm, coins[i]);
                    count++;
                }
            }
            int sign = (count % 2 == 1) ? 1 : -1;
            subset_info.push_back({current_lcm, sign});
        }

        // Helper function to count valid numbers <= x
        auto countMultiples = [&](long long x) -> long long {
            long long total = 0;
            for (const auto& [l, sign] : subset_info) {
                total += sign * (x / l);
            }
            return total;
        };

        // Binary Search range
        long long low = 1;
        long long min_coin = *min_element(coins.begin(), coins.end());
        long long high = min_coin * (long long)k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (countMultiples(mid) >= k) {
                ans = mid;
                high = mid - 1; // Try finding a smaller valid amount
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};