##### Dikstra.cpp  --- Sequential code
##### P_Dikstra.cpp ---- Pararallelized code

### Generating input for the programe
gcc graph_ge.c -o graph
./graph

this generates edgerepresentation of graph
select generate random connected graph
select number_of_vertices and number_of_Edges
give the filename;

Convert to edge representation to matrixrepresentation with EdgetoMat.py
python3 EdgetoMat.py < edgerepresentation > input

### Compliling and Running Sequential code

g++ Dikstra.cpp -o d
./d < input

### Compliling and Running Parallelized code

g++ -fopenmp P_Dikstra.cpp -o p
./p < input


# Changes To the Sequential Code:
Parallel Changes to the Sequential code is done minDistance function to find the minimum
