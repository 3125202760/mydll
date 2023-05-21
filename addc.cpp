#include <iostream>
#include <windows.h>

typedef int (*AddFunc)(int, int);

int main() {
    HMODULE hModule = LoadLibrary("add.dll");
    if (!hModule) {
        std::cerr << "Failed to load add.dll\n";
        return -1;
    }

    AddFunc add = (AddFunc)GetProcAddress(hModule, "add");
    if (!add) {
        std::cerr << "Failed to find add function\n";
        FreeLibrary(hModule);
        return -1;
    }

    int result = add(1, 2);
    std::cout << "Result: " << result << "\n";

    FreeLibrary(hModule);
    return 0;
}

