#avl tree test
complied with g++ on wsl with flags
std=c++0x pedantic Wall

##addition test
1. adding increasing numbers in ranges
* 0 : 1 000
* 0 : 1 000 000
2. adding decreasing numbers in ranges
* 1 000 : 0
* 0 : -1000
3. adding random numbers in range
* (0 : 1 000 000) % 100 000 000 (possible repeating numbers)

##deletion test
1. removing increasing numbers in ranges (1000 added)
* 0 : 1000
* 900 : 1000
2. removing decreasing numbers in ranges (1000 added)
* 1000 : 0
* 0 : -1000
3. removing random numbers (1000 addded, 1000 removed)
* range 1000

##height test
1. adding integers in range 0:14 and 0:30 and checking 
if the heights are correct
2. adding 10 000 and 100 000 numbers and calculating 
the height of the tree and checking (should be log2(n) + 1 rounded up)

##rotation test
1. adding and deletig numbers in order to check
if the rotation takes place

