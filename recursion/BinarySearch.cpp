#include <iostream>
#include <vector>

void BinarySearch(std::vector<int>& data, int needToFind, int curLeft, int curRight) {
    if (curLeft > curRight) {
        std::cout << "Not found\n";
        return;
    }

    int curMid = (curLeft + curRight) / 2;

    if (data[curMid] == needToFind) {
        std::cout << "I find it in pos: " << curMid << std::endl;
        return;
    }
    if (needToFind > data[curMid]) {
        return BinarySearch(data, needToFind, curMid + 1, curRight);
    }
    if (needToFind < data[curMid]) {
        return BinarySearch(data, needToFind, curLeft, curMid - 1);
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

    std::cout << "What I need to find?\n";
    int needToFind;
    std::cin >> needToFind;

    BinarySearch(data, needToFind, 0, data.size() - 1);
}