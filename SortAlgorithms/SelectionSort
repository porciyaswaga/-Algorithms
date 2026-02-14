#include <iostream>
#include <vector>

int findTheSmallest(const std::vector<int>& data) {
    int dataSmallestNum = data[0];
    size_t indexOfSmallestNum = 0;

    for (size_t i = 1; i < data.size(); ++i) {
        if (data[i] < dataSmallestNum) {
            dataSmallestNum = data[i];
            indexOfSmallestNum = i;
        }
    }
    return indexOfSmallestNum;
}

std::vector<int> SelectionSort(std::vector<int> data) {
    std::vector<int> sortedData;

    while (!data.empty()) {
        int index = findTheSmallest(data);
        sortedData.push_back(data[index]);
        data.erase(data.begin() + index);
    }

    return sortedData;
}

int main() {
    std::vector<int> v = {5, 2, 9, 1, 7};
    std::vector<int> sorted = SelectionSort(v);

    for (int x : sorted)
        std::cout << x << " ";
    std::cout << '\n';
}
