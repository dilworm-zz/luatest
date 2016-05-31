ba = require "bitarray"

local a = ba.new(10)
print(a)
print (ba.get(a,1))
ba.set(0, 1, 1);
print (ba.get(a,1))




