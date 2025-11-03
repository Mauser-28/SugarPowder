#include "String.h"


int main() {
    String a{"this text have no sense"};
    String b{"use"};
    std::cout << a.substr(0, 15) << a.substr(18, 5) << std::endl;
    std::cout << a.erase(29, 4);
    std::cout << String("It's") + String(" no ") + b;
    return 0;
}