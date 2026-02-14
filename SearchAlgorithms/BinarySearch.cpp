#include <iostream>
#include <vector>

/*
Реализация алгоритма Бинарного поиска, рассмотренного в книге "Грокаем Алгоритмы."
*/

int BinarySearch(const std::vector<int>& data, const int& num) {
    int left = 0;
    int right = data.size() - 1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        int guess = data[mid];
        if (guess == num) {
            return mid;
        } else if (guess > num) {
            right = mid - 1;
        } else if (guess < num) {
            left = mid + 1;
        }
    }
    std::cout << "Элемент не найден" << '\n';
    return -1;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> sortedData(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> sortedData[i];
    }

    int num;
    std::cout << "Введите число для поиска: ";
    std::cin >> num;

    int result = BinarySearch(sortedData, num);

    if (result != -1)
        std::cout << "Индекс: " << result << '\n';
    else
        std::cout << "Элемент не найден\n";
}
