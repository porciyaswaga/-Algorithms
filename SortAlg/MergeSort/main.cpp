#include <iostream>
#include <vector>
#include <string>

struct Human {
    int age;
    std::string name;
};

void Merge(std::vector<Human>& data, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<Human> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = data[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = data[mid + j + 1];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i].age <= R[j].age) {
            data[k] = L[i];
            i++;
        } else {
            data[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        data[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        data[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(std::vector<Human>& data, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;

    MergeSort(data, left, mid);
    MergeSort(data, mid + 1, right);

    Merge(data, left, mid, right);
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
    
    MergeSort(data, 0, data.size() - 1);

    for (const auto& hum : data) {
        std::cout << "Name: " << hum.name << "; "
                  << "Age: " << hum.age << '\n';
    }
}