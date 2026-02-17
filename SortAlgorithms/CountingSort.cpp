#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> CountingSort(const std::vector<int>& array) {

    int n = array.size();
    int k = *std::max_element(array.begin(), array.end());
    std::vector<int> count(k + 1, 0);

    for (auto const& i : array) {
        count[i]++;
    }

    for (size_t i = 1; i < count.size(); ++i) {
        count[i] += count[i-1];
    }

    std::vector<int> result(n);
    for (int i = n - 1; i >= 0; --i) {
        result[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    return result;
}

int main() {
    std::vector<int> array;
    int num;
    std::cout << "Введите числа (Ctrl+D для окончания ввода):\n";

    while (std::cin >> num) {
        array.push_back(num);
    }

    std::vector<int> result = CountingSort(array);

    std::cout << "Отсортированный массив:\n";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i] << ' ';
    }
    std::cout << "\n";
    
    return 0;
}
