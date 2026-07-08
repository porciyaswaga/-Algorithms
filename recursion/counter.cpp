#include <iostream>
#include <vector>
#include <string>

struct Human {
    int age;
    std::string name;
};

int Counter(std::vector<Human>& data, int index, int count, int parameter) {
    if (index == data.size()) {
        return count;
    }
    if (data[index].age > parameter) {
        return Counter(data, index + 1, count + 1, parameter);
    }
    return Counter(data, index + 1, count, parameter);
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

    int parameter = 18;

    std::cout << "Total count of people than older than 18 y.o.: " << Counter(data, 0, 0, parameter) << std::endl;
    
}