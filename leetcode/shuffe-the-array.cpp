#include <iostream>
#include <vector>
using namespace std;

vector<int> shuffle(vector<int> &nums, int n)
{
    vector<int> result;
    int *p1 = &nums[0];
    int *p2 = &nums[n];

    for (int i = 0; i < n; i++)
    {
        result.push_back(*p1);
        result.push_back(*p2);
        p1++;
        p2++;
    }

    return result;
}

int main()
{
    vector<int> nums = {2, 5, 1, 3, 4, 7};
    int n = 3;

    vector<int> result = shuffle(nums, n);

    for (int x : result)
    {
        cout << x << ", ";
    }

    cout << endl;
}
