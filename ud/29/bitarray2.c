#include <limits.h>
#include <lua.h>
#include <lauxlib.h>

#define BITS_PER_WORD (CHAR_BIT*sizeof(unsigned int))
#define I_WORD(i)     ((unsigned int)(i) / BITS_PER_WORD)
#define I_BIT(i)      (1 << ((unsigned int)(i) % BITS_PER_WORD))

#define _USE_METATABLE

typedef struct NumArray
{
    int size;
    unsigned int values[1];
}NumArray;

#define checkbitarray(L) \
    (NumArray*)luaL_checkudata(L, 1, "LuaBook.bitarray")

static int newarray(lua_State* L)
{
    int i;
    size_t size;
    NumArray* arr = NULL;
    
    int n = luaL_checkinteger(L, 1);
    luaL_argcheck(L, n >= 1, 1, "invalid size"); // raise exception if cond failed.
    size = sizeof(NumArray) + I_WORD(n - 1)*sizeof(unsigned int);
    arr = (NumArray*)lua_newuserdata(L, size);
    arr->size = n;
    for (i = 0; i <= I_WORD(n - 1); i++)
        arr->values[i] = 0;

#ifdef _USE_METATABLE
    luaL_getmetatable(L, "LuaBook.bitarray");
    lua_setmetatable(L, -2); // set metatable "LuaBook.bitarray" to arr
#endif 
    return 1;
}
// array.set(a, index, value)
static int setarray(lua_State* L)
{
#ifdef _USE_METATABLE
    NumArray* arr = checkbitarray(L);
#else
    NumArray* arr = (NumArray*)lua_touserdata(L, 1);
    luaL_argcheck(L, arr != NULL, 1, "'array' excepted");
#endif
    
    int index = luaL_checkinteger(L, 2) -1;

    luaL_argcheck(L, (index >= 0) && (index < arr->size), 2, 
                    "index out of range");

    luaL_checkany(L, 3);
    if (lua_toboolean(L, 3))
        arr->values[I_WORD(index)] |= I_BIT(index);
    else
        arr->values[I_WORD(index)] &= ~I_BIT(index);

    return 0;
}

static int getarray(lua_State* L)
{
    NumArray* arr = (NumArray*)lua_touserdata(L, 1);
    int index = luaL_checkinteger(L, 2) - 1;

    luaL_argcheck(L, arr != NULL, 1, "'array' excepted");
    luaL_argcheck(L, (index >= 0) && (index < arr->size), 2, "index out of range");

    lua_pushboolean(L, arr->values[I_WORD(index)] & I_BIT(index));
    return 1;

}

static int getsize(lua_State* L)
{
#ifdef _USE_METATABLE
    NumArray* arr = checkbitarray(L);
#else
    NumArray* arr = (NumArray*)lua_touserdata(L, 1);
    luaL_argcheck(L, arr != NULL, 1, "'array' excepted");
#endif
    lua_pushinteger(L, arr->size);
    return 1;
}

static const struct luaL_Reg arraylib[] = 
{
    {"new", newarray},
    {"set", setarray},
    {"get", getarray},
    {"size", getsize},
    {NULL, NULL}
};

int luaopen_bitarray(lua_State* L)
{
#ifdef _USE_METATABLE
    luaL_newmetatable(L, "LuaBook.bitarray"); 
#endif
    luaL_newlib(L, arraylib);
    return 1;
}



