#include <iostream>
#include <vector>

// g++ -std=c++11 pass_by_ref_imu.cpp && ./a.out   

int avg(const std::vector<int> &v)
{
    int avg = 0;
    int sum = 0;
    for(auto i : v) {
      sum += i;
    }
    return sum / v.size();
}

int main()
{
    std::vector<int> v  = {1, 2, 3};
    std::cout << avg(v) << "\n";
}

