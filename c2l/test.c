#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int status, result, i;
    double sum;
    lua_State* L;
    L = luaL_newstate();
    luaL_openlibs(L);
    
    status = luaL_loadfile(L, "script.lua"); 
    if (status)
    {
        fprintf(stderr, "Couldn't load file:%s \n", lua_tostring(L, -1));
        return -1;
    }

    lua_newtable(L); 
    for (i = 1; i <=5; i++)
    {
        lua_pushnumber(L, i);
        lua_pushnumber(L, i*2);
        lua_rawset(L, -3);
    }

    lua_setglobal(L, "foo"); 

    result = lua_pcall(L, 0, LUA_MULTRET, 0); 
    if (result)
    {
        fprintf(stderr, "Failed to run script: %s\n", lua_tostring(L, -1));
        return -1;
    }

    sum = lua_tonumber(L, -1);
    printf("Script returned: %.0f\n", sum);
    
    lua_pop(L, 1);
    lua_close(L);

    return 0;
}
