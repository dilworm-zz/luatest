require "power"
print(square(2))
print(cube(2))

require "msleep"
p = print
sf = string.format

local start = os.time()
p(sf("Started at %d", start))
sleep(2)
local mid = os.time()
p(sf("After sleep(2), time is %d", mid))
msleep(2000)
p(sf("After msleep(2000) time is %d", os.time()))

