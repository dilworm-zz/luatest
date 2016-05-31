#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <lua.h>
#include <lauxlib.h>

typedef struct Foo 
{
    int x;
    int y;
}Foo;

static Foo* toFoo(lua_State*L, int index)
{
    Foo* bar = (Foo*)lua_touserdata(L, index);
    if (bar == NULL) luaL_typeerror(L, index, FOO);
    return bar;
}

static Foo* checkFoo(lua_State* L, int index)
{
    Foo* bar;
    luaL_checktype(L, index, LUA_TUSERDATA);
    bar = (Foo*)lauL_checkudata(L, index, FOO);
    if (bar == NULL) luaL_typerror(L, index, FOO);
    return bar;
}

static Foo* pushFoo(lua_State* L)
{
    Foo* bar = (Foo*)lua_newuserdata(L, sizeof(Foo));
    luaL_getmetatable(L, FOO);
    lua_setmetatable(L, -2);
    return bar;
}

static int Foo_new(lua_State* L)
{
    int x = luaL_optint(L, 1, 0);
    int y = luaL_optint(L, 2, 0);
    Foo* bar = pushFoo(L);
    bar->x = x;
    bar->y = y;

    return 1;
}









