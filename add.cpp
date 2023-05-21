#include <lua.hpp>

extern "C" {
    __declspec(dllexport) double add(double a, double b) {
        return a + b;
    }
}
