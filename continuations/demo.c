// The code below is for represention only, it shows the continuations 
// implemention of pcall.



// In Lua 5.1, this function had the following code:

static int luaB_pcall (lua_State *L) {
	int status;
	luaL_checkany(L, 1); /* at least one parameter */
	status = lua_pcall(L, lua_gettop(L) - 1, LUA_MULTRET, 0);
	lua_pushboolean(L, (status == 0)); /* status */
	lua_insert(L, 1); /* status is first result */
	return lua_gettop(L); /* return status + all results */
}

//============================lua 5.2============================
static int finishpcall (lua_State *L, int status) {
	lua_pushboolean(L, status); /* first result (status) */
	lua_insert(L, 1); /* put first result in first slot */
	return lua_gettop(L);
}
static int pcallcont (lua_State *L) {
	int status = lua_getctx(L, NULL);
	return finishpcall(L, (status == LUA_YIELD));
}
static int luaB_pcall (lua_State *L) {
	int status;
	luaL_checkany(L, 1);
	status = lua_pcallk(L, lua_gettop(L) - 2, LUA_MULTRET, 0,
	return finishpcall(L, (status == LUA_OK));
}
