#include <iostream>
#include <vector>
#include <utility>


int Parent(int i) {
    return (i - 1) / 2;
}

int Left(int i) {
    return (2 * i + 1);
}

int Right(int i) {
    return (2 * i + 2);
}

void MaxHeapify(std::vector<int>& data, int i, int heapSize) {
    int l = Left(i);
    int r = Right(i);
    int indexOfLargestElem = i;

    if (l < heapSize && data[l] > data[i]) {
        indexOfLargestElem = l;
    }

    if (r < heapSize && data[r] > data[indexOfLargestElem]) {
        indexOfLargestElem = r;
    }

    if (indexOfLargestElem != i) {
        std::swap(data[i], data[indexOfLargestElem]);
        MaxHeapify(data, indexOfLargestElem, heapSize);
    }
}

void BuildMaxHeap(std::vector<int>& data, int heapSize) {
    for (int i = heapSize / 2 - 1; i >= 0; --i) {
        MaxHeapify(data, i, heapSize);
    }
}

void HeapSort(std::vector<int>& data) {
    int length = data.size();
    int heapSize = length;

    BuildMaxHeap(data, heapSize);

    for (int i = length - 1; i >= 1; --i) {
        std::swap(data[0], data[i]);
        heapSize--;
        MaxHeapify(data, 0, heapSize);
    }
}

int main() {
    std::vector<int> data;
    int num;

    std::cout << "Input nums (to stop use Ctrl+D).\n";
    while (std::cin >> num) data.push_back(num);
    

    std::cout << "Input array:\n";
    for (const auto& elem : data) std::cout << elem << ' ';

    std::cout << '\n';

    HeapSort(data);

    std::cout << "Output array:\n";
    for (const auto& elem : data) std::cout << elem << ' ';

    std::cout << '\n';
}