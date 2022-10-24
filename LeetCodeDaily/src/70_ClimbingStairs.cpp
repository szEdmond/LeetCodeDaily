#include<iostream>

int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    int count = climbStairs(n - 1) + climbStairs(n - 2);
    return count;
}

int main()
{
    //TLE needs TODO: DP
    std::cout << climbStairs(12);
}