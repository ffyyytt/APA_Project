# APA_Project

# Permuatation

Run command:

```
cd source
make testpermut
./testpermut
```

Output: (method 0: Dictionary, method 1: Heap recursive, method 2: Heap)
```
Test n = 3, total permutations: 6
Method 0 	|	 Method 1 	|	 Method 2
0  1  2  	|	0  1  2  	|	0  1  2  
0  2  1  	|	1  0  2  	|	1  0  2  
1  0  2  	|	2  0  1  	|	2  0  1  
1  2  0  	|	0  2  1  	|	0  2  1  
2  0  1  	|	1  2  0  	|	1  2  0  
2  1  0  	|	2  1  0  	|	2  1  0  
Test time:
N = 0, method: 0, lengthPerm: 0, time taken: 0.00s
N = 0, method: 1, lengthPerm: 0, time taken: 0.00s
N = 0, method: 2, lengthPerm: 0, time taken: 0.00s
N = 1, method: 0, lengthPerm: 1, time taken: 0.00s
N = 1, method: 1, lengthPerm: 1, time taken: 0.00s
N = 1, method: 2, lengthPerm: 1, time taken: 0.00s
N = 2, method: 0, lengthPerm: 4, time taken: 0.00s
N = 2, method: 1, lengthPerm: 4, time taken: 0.00s
N = 2, method: 2, lengthPerm: 4, time taken: 0.00s
N = 3, method: 0, lengthPerm: 18, time taken: 0.00s
N = 3, method: 1, lengthPerm: 18, time taken: 0.00s
N = 3, method: 2, lengthPerm: 18, time taken: 0.00s
N = 4, method: 0, lengthPerm: 96, time taken: 0.00s
N = 4, method: 1, lengthPerm: 96, time taken: 0.00s
N = 4, method: 2, lengthPerm: 96, time taken: 0.00s
N = 5, method: 0, lengthPerm: 600, time taken: 0.00s
N = 5, method: 1, lengthPerm: 600, time taken: 0.00s
N = 5, method: 2, lengthPerm: 600, time taken: 0.00s
N = 6, method: 0, lengthPerm: 4320, time taken: 0.00s
N = 6, method: 1, lengthPerm: 4320, time taken: 0.00s
N = 6, method: 2, lengthPerm: 4320, time taken: 0.00s
N = 7, method: 0, lengthPerm: 35280, time taken: 0.00s
N = 7, method: 1, lengthPerm: 35280, time taken: 0.00s
N = 7, method: 2, lengthPerm: 35280, time taken: 0.00s
N = 8, method: 0, lengthPerm: 322560, time taken: 0.01s
N = 8, method: 1, lengthPerm: 322560, time taken: 0.01s
N = 8, method: 2, lengthPerm: 322560, time taken: 0.00s
N = 9, method: 0, lengthPerm: 3265920, time taken: 0.03s
N = 9, method: 1, lengthPerm: 3265920, time taken: 0.02s
N = 9, method: 2, lengthPerm: 3265920, time taken: 0.01s
N = 10, method: 0, lengthPerm: 36288000, time taken: 0.22s
N = 10, method: 1, lengthPerm: 36288000, time taken: 0.21s
N = 10, method: 2, lengthPerm: 36288000, time taken: 0.20s
N = 11, method: 0, lengthPerm: 439084800, time taken: 2.69s
N = 11, method: 1, lengthPerm: 439084800, time taken: 2.57s
N = 11, method: 2, lengthPerm: 439084800, time taken: 2.45s
```
