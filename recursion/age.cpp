#include <iostream>
#include <string>
#include <vector>

struct Human {
    int age;
    std::string name;
};

Human Min(std::vector<Human>& data, int index, Human curMin) {
    if (index == data.size()) {
        return curMin;
    }
    if (curMin.age > data[index].age) {
        return Min(data, index + 1, data[index]);
    }
    return Min(data, index + 1, curMin);
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

    Human result = Min(data, 0, data[0]);
    std::cout << "Name: " << result.name << " age: " << result.age << std::endl;
}