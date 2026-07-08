#include <iostream>
#include <vector>
#include <string>

struct Human {
    int age;
    std::string name;
};


void InsertionSort(std::vector<Human>& data) {
    for (int j = 1; j < data.size(); ++j) {

        Human transit = data[j];
        int i = j - 1;

        while (i >= 0 && data[i].age > transit.age) {
            data[i + 1] = data[i];
            --i;
        }

        data[i + 1] = transit;
    }
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
    
    InsertionSort(data);

    for (const auto& hum : data) {
        std::cout << "Name: " << hum.name << "; "
                  << "Age: " << hum.age << '\n';
    }
}