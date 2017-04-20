coinnorm.c is the Sequential Code
conchange.c is the Parellized Code

compiling and running the Sequential Code

gcc coinnorm.c -o norm
./norm

compiling the Parallelized Code
gcc -fopenmp conchange.c -o pcode
./pcode


input to the programe

150 25
48 6 34 50 49 36 30 35 40 41 17 43 39 13 4 20 19 2 46 7 38 33 28 18 21

First line indicates m n  where m is the number total amount and n is the number of coins.
Second line indicates n different coins


Parellized Code: 

Changes are made to sequential code in main function and coin func
