#include <iostream>
#include <vector>
#include <string>
#include <utility>


struct Human {
    int age;
    std::string name;
};

int Partition(std::vector<Human>& data, int cur_I, int cur_J, int right) {
    int pivot = data[right].age;

    if (cur_J == right) {
        std::swap(data[cur_J], data[cur_I]);
        return cur_I;
    }

    if (data[cur_J].age > pivot) {
        return Partition(data, cur_I, cur_J + 1, right);
    }
    if (data[cur_J].age <= pivot) {
        std::swap(data[cur_J], data[cur_I]);
        return Partition(data, cur_I + 1, cur_J + 1, right);
    }
}

void QuickSort(std::vector<Human>& data, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    
    if (data[left].age > data[mid].age) {
        std::swap(data[left], data[mid]);
    }

    if (data[mid].age > data[right].age) {
        std::swap(data[mid], data[right]);
    }

    if (data[left].age > data[mid].age) {
        std::swap(data[left], data[mid]);
    }

    std::swap(data[mid], data[right]);

    int pivotIndex = Partition(data, left, left, right);
    QuickSort(data, left, pivotIndex - 1);
    QuickSort(data, pivotIndex + 1, right);
}

int main() {
    Human human;
    std::vector<Human> data;
    while (true) {
        std::cout << "Input name (or stop): ";
        std::cin >> human.name;

        if (human.name == "stop") {
            break;
        }

        std::cout << "Input age: ";
        std::cin >> human.age;

        data.push_back(human);
    }
        std::cout << "Size of Human list " << data.size() << '\n';

        for (const auto& hum : data) {
            std::cout << "Name: " << hum.name << "; "
                      << "Age: " << hum.age << '\n';
        }

    std::cout << '\n';
    
    QuickSort(data, 0, data.size() - 1);

    for (const auto& hum : data) {
        std::cout << "Name: " << hum.name << "; "
                  << "Age: " << hum.age << '\n';
    }
}

/*
вариант с выбором pivot методом медианы из трех: первого элемента
                                                 среднего 
                                                 последнего; (по позиции)
и берем среднее из них
*/