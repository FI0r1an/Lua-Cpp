#include<iostream>

extern "C"
{
#include"lua515/src/lua.h"
#include"lua515/src/lualib.h"
#include"lua515/src/lauxlib.h"
}

#ifdef _WIN32
#pragma comment(lib, "lua515/liblua5.1.a")
#endif

#define API extern"C" int

API add(lua_State *L) {

    double op1 = luaL_checknumber(L, 1);
    double op2 = luaL_checknumber(L, 2);
    lua_pushnumber(L, op1 + op2);

    return 1;
}

static const luaL_Reg myfunc[] =
{
    { "add",add },
    { NULL, NULL }
};

extern "C" __declspec(dllexport) int luaopen_mylib(lua_State* L)
{
    luaL_register(L, "mylib", myfunc);
    return 1;
}