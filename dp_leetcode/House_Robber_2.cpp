class Solution
{
public:
    int robber(vector<int> &a)
    {
        int n = a.size();
        int prev = a[0];
        int prev2 = 0;
        for (int i = 1; i < n; ++i)
        {
            int take = a[i];
            if (i > 1)
                take += prev2;
            int non_take = 0 + prev;
            int curr = max(take, non_take);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    long long rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> temp1, temp2;
        for (int i = 0; i < n; ++i)
        {
            if (i != 0)
                temp1.push_back(nums[i]);
            if (i != n - 1)
                temp2.push_back(nums[i]);
        }

        return max(robber(temp1), robber(temp2));
    }
};