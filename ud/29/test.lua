ba = require "bitarray"
--ba2 = require "bitarray2"

-- C 方式的调用
function test1()
    local a = ba.new(10)
    print(a)
    print (ba.get(a,1))
    ba.set(0, 1, 1);
    print (ba.get(a,1))
end

-- 面向对象的访问方式
function test2()
    -- 获取userdata的metatable并重定向__index
    local metaarray = getmetatable(ba.new(1))
    metaarray.__index = metaarray
    metaarray.set = ba.set
    metaarray.get = ba.get
    metaarray.size = ba.size

    local a = ba.new(10)
    a:set(2, 2);
    print (a:get(2))
    print (a:size())
end

test2()

