#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int countSubsequences(int M, const vector<int>& nums) {
    int count = 0;
    int p = 1;
    int left = 0;

    for (int right = 0; right < nums.size(); ++right) {
        p *= nums[right];

        while (p % M == 0) {
            p /= nums[left];
            ++left;
        }

        if (p % M == 0) {
            count += right - left + 1;
        }
    }

    return count;
}

int main() {
    ifstream input("26-104a.txt");
    int M = 4043520;
    int N;
    input >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        input >> nums[i];
    }

    int result = countSubsequences(M, nums);
    cout  << result << endl;

    return 0;
}
