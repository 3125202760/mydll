#include <lua.hpp>

    static int l_add(lua_State *L) {
    double a = luaL_checknumber(L, 1);
    double b = luaL_checknumber(L, 2);
    lua_pushnumber(L, a + b);
    return 1;
    }

    extern "C" {
    __declspec(dllexport) int luaopen_mydll(lua_State *L) {
        luaL_Reg reg[] = {
            {"add", l_add},
            {NULL, NULL}
        };
        luaL_register(L, "mydll", reg);
        return 1;
        }
}
