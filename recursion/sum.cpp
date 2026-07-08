#include <iostream>
#include <vector>


int Sum(std::vector<int> data, int sum, int index) {
    if (index == data.size()) {
        return sum;
    } else {
        return Sum(data, sum + data[index], index + 1);
    }
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

    std::cout << Sum(data, data[0], 1) << std::endl;
}