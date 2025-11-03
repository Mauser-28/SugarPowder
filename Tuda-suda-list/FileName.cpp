#include "List.h"
#include <stdexcept>
#include <vector>

int main() {
    std::vector<int32_t> v{ 1, 2, 3, 4, 5, 6 };
    List l;

    for (const auto& e : v) {
        l.pushBack(e);
    }

    l.insert(3, 0);
    l.erase(3);
    
    while (l.size()) {
        std::cout << l.front() << ' ';
        l.pop_front();
    }
}
