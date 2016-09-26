# Genetic algorithm simulation for a linear fit
### Author: Abhay Mittal

This program simulates a basic genetic algorithm and performs operations of reproduction, crossover and mutation. I developed it as part of my coursework assignment in Soft Computing.
 The concepts and algorithm are from the book __"Fuzzy Logic with Engineering Applications"__ by __Timothy J. Ross__

```
Fitness function => y = C1 x + C2

Dataset:
--------------------------------
Data Number     x       y
--------------------------------
        1       1.0     1.0
        2       2.0     2.0
        3       4.0     3.0
        4       6.0     6.0
--------------------------------


Input Strings:
-------------
000111 010100
010010 001100
010101 101010
100100 001001

```

 The parameter set (C1,C2) is encoded in the form of bit strings.
 The values in this program match those of an example present in the book but can be changed.

### Compilation steps:
`gcc ga.c -lm`

### Sample Output
```

                 |                  |          |        |          |        |        |        |        |        |          | Expected |         
                 |                  | C1       |        | C2       |        |        |        |        |        |          | Count =  | Actual  
String no.       | String           | Bin      | C1     | Bin      | C2     | y1     | y2     | y3     | y4     | f(x)     | f/avg    | Count   
----------------------------------------------------------------------------------------------------------------------------------------------
1                | 000111010100     |        7 |  -1.22 |       20 |   0.22 |  -1.00 |  -2.22 |  -4.67 |  -7.11 |   147.49 |     0.48 |    0
2                | 010010001100     |       18 |   0.00 |       12 |  -0.67 |  -0.67 |  -0.67 |  -0.67 |  -0.67 |   332.22 |     1.08 |    1
3                | 010101101010     |       21 |   0.33 |       42 |   2.67 |   3.00 |   3.33 |   4.00 |   4.67 |   391.44 |     1.27 |    2
4                | 100100001001     |       36 |   2.00 |        9 |  -1.00 |   1.00 |   3.00 |   7.00 |  11.00 |   358.00 |     1.17 |    1

                                                                                                            sum =  1229.16
                                                                                                        average =   307.29
                                                                                                        maximum =   391.44

Enter 1 to display next iteration, any other number to exit: 1
                 |                  |          |        |          |        |        |        |        |        |          | Expected |         
                 |                  | C1       |        | C2       |        |        |        |        |        |          | Count =  | Actual  
Selected String  | New String       | Bin      | C1     | Bin      | C2     | y1     | y2     | y3     | y4     | f(x)     | f/avg    | Count   
----------------------------------------------------------------------------------------------------------------------------------------------
010101101010     | 010110001100     |       22 |   0.44 |       12 |  -0.67 |  -0.22 |   0.22 |   1.11 |   2.00 |   375.78 |     1.14 |    1
010010001100     | 010001101010     |       17 |  -0.11 |       42 |   2.67 |   2.56 |   2.44 |   2.22 |   2.00 |   380.78 |     1.16 |    2
010101101010     | 010100001001     |       20 |   0.22 |        9 |  -1.00 |  -0.78 |  -0.56 |  -0.11 |   0.33 |   348.52 |     1.06 |    1
100100001001     | 100101101010     |       37 |   2.11 |       42 |   2.67 |   4.78 |   6.89 |  11.11 |  15.33 |   208.93 |     0.64 |    0

                                                                                                            sum =  1314.00
                                                                                                        average =   328.50
                                                                                                        maximum =   380.78

Enter 1 to display next iteration, any other number to exit: 1
                 |                  |          |        |          |        |        |        |        |        |          | Expected |         
                 |                  | C1       |        | C2       |        |        |        |        |        |          | Count =  | Actual  
Selected String  | New String       | Bin      | C1     | Bin      | C2     | y1     | y2     | y3     | y4     | f(x)     | f/avg    | Count   
----------------------------------------------------------------------------------------------------------------------------------------------
010110001100     | 010111101010     |       23 |   0.56 |       42 |   2.67 |   3.22 |   3.78 |   4.89 |   6.00 |   388.33 |     1.09 |    1
010001101010     | 010000001100     |       16 |  -0.22 |       12 |  -0.67 |  -0.89 |  -1.11 |  -1.56 |  -2.00 |   302.00 |     0.85 |    1
010100001001     | 010100001010     |       20 |   0.22 |       10 |  -0.89 |  -0.67 |  -0.44 |   0.00 |   0.44 |   351.38 |     0.99 |    1
010001101010     | 010001101001     |       17 |  -0.11 |       41 |   2.56 |   2.44 |   2.33 |   2.11 |   1.89 |   380.11 |     1.07 |    1

                                                                                                            sum =  1421.83
                                                                                                        average =   355.46
                                                                                                        maximum =   388.33

Enter 1 to display next iteration, any other number to exit: 0
```