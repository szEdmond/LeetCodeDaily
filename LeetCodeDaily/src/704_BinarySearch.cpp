#include<iostream>
#include<vector>

int search(std::vector<int>& nums, int target) {
    int lo = 0;
    int hi = nums.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) hi = mid - 1;
        else lo = mid + 1;
    }
    return -1;
}

int main() {
    std::vector<int> iv{ -1,0,3,5,9,12 };
    std::cout << search(iv, 9) << std::endl;
}