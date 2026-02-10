#include <iostream>
#include <vector>
using namespace std;

vector<int> getConcatenation(vector<int> &nums)
{
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i < nums.size(); i++)
        ans.push_back(nums[i]);

    for (int i = 0; i < n; i++)
        ans.push_back(nums[i]);

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 1};
    vector<int> result = getConcatenation(nums);
    for (int x : result)
        cout << x << ", ";

    cout << endl;
}
