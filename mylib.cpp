#include <lua.h>
#include <lauxlib.h>

static int add(lua_State *L) {
    double a = luaL_checknumber(L, 1);
    double b = luaL_checknumber(L, 2);
    lua_pushnumber(L, a + b);
    return 1;
}

int __declspec(dllexport) luaopen_mylib(lua_State *L) {
    static const struct luaL_Reg mylib[] = {
        {"add", add},
        {NULL, NULL}
    };
    luaL_newlib(L, mylib);
    return 1;
}
