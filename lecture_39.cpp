#include <iostream>
#include <vector>
using namespace std;
void solve(vector<int> &nums, vector<vector<int>> &ans, int index)
{
    // Base case:
    if (index >= nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        solve(nums, ans, index + 1);
        // Backtracking:
        swap(nums[index], nums[i]); // Fix: It should be swap(nums[index], nums[i]) instead of swap(nums, ans, index + 1);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    int index = 0;
    solve(nums, ans, index);
    return ans;
}
int main()
{
    vector<int> nums = {0, 1, 2, 3}; // Fix: Use curly braces instead of square brackets for initialization
    vector<vector<int>> ans = permute(nums);
    for (int i = 0; i < ans.size(); i++) // Fix: Use ans.size() instead of nums.size()
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}