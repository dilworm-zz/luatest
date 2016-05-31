#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

static int msleep_c(lua_State* L)
{
    // 1000 us = 1ms
    // 1000 ms = 1s
    long msecs = lua_tointeger(L, -1);
    usleep(1000*msecs);
    return 0;
}

static int sleep_c(lua_State* L)
{
    long secs = lua_tointeger(L, -1);
    sleep(secs);
    return 0;
}

int luaopen_msleep(lua_State* L)
{
    lua_register(L, "msleep", msleep_c);
    lua_register(L, "sleep", sleep_c);
    return 0;
}
