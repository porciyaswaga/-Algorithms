#include <iostream>
#include <vector>


int Max(std::vector<int>& data, int curMax, int index) {
    if (index == data.size()) {
        return curMax;
    }
    
    if (curMax < data[index]) {
        return Max(data, data[index], index + 1);
    }

    return Max(data, curMax, index + 1);
}


int main() {
    std::vector<int> data;
    int n;
    int num;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> num;
        data.push_back(num);
    }

    std::cout << Max(data, data[0], 1) << std::endl;
}