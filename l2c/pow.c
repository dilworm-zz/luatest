#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <stdlib.h>
#include <stdio.h>


static int isquare(lua_State* L)
{
    float rtrn = lua_tonumber(L, -1);
    printf("Top of square(), nbr=%f\n", rtrn);
    lua_pushnumber(L, rtrn*rtrn);
    return 1;
}

static int icube(lua_State* L)
{
    float rtrn = lua_tonumber(L, -1);
    printf("Top of cube(), number = %f\n", rtrn);
    lua_pushnumber(L, rtrn*rtrn*rtrn);
    return 1;
}

int luaopen_power(lua_State* L) 
{
    lua_register(L, "square", isquare);
    lua_register(L, "cube", icube);
    return 0;
}


