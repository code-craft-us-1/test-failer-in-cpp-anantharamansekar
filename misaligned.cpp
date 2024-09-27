#include <assert.h>
#include <iostream>
#include <string>

const char* majorColor[] = { "White", "Red", "Black", "Yellow", "Violet" };
const char* minorColor[] = { "Blue", "Orange", "Green", "Brown", "Slate" };

std::string GetMajorColor(int n) {
    return majorColor[n];
}

std::string GetMinorColor(int n) {
    return minorColor[n];
}

int printColorMap() {
    int i = 0, j = 0;
    for (i = 0; i < 5; i++) {
        std::string majorColor = GetMajorColor(i);
        for (j = 0; j < 5; j++) {
            std::string minorColor = GetMinorColor(j);
            int colorId = i * 5 + j;
            std::cout << colorId << " | " << majorColor << " | " << minorColor << "\n";
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    assert(GetMajorColor(2) == "Black");

    assert(GetMinorColor(0) == "White");

    std::cout << "All is well (maybe!)\n";
    return 0;
}
