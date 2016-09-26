# Genetic algorithm simulation for a linear fit
### Author: Abhay Mittal

This program simulates a basic genetic algorithm and performs operations of reproduction, crossover and mutation. I developed it as part of my coursework assignment in Soft Computing.
 The concepts and algorithm are from the book __"Fuzzy Logic with Engineering Applications"__ by __Timothy J. Ross__


 Fitness function => y = C1 x + C2


 The parameter set (C1,C2) is encoded in the form of bit strings.
 The values in this program match those of an example present in the book but can be changed.

### Compilation steps:
`gcc ga.c -lm`

### Sample Output
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
010101101010     | 010010001100     |       18 |   0.00 |       12 |  -0.67 |  -0.67 |  -0.67 |  -0.67 |  -0.67 |   332.22 |     0.92 |    1
010010001100     | 010101101010     |       21 |   0.33 |       42 |   2.67 |   3.00 |   3.33 |   4.00 |   4.67 |   391.44 |     1.09 |    1
010101101010     | 010101001001     |       21 |   0.33 |        9 |  -1.00 |  -0.67 |  -0.33 |   0.33 |   1.00 |   359.67 |     1.00 |    1
100100001001     | 100100001010     |       36 |   2.00 |       10 |  -0.89 |   1.11 |   3.11 |   7.11 |  11.11 |   355.73 |     0.99 |    1

                                                                                                            sum =  1439.06
                                                                                                        average =   359.77
                                                                                                        maximum =   391.44

Enter 1 to display next iteration, any other number to exit: 1
                 |                  |          |        |          |        |        |        |        |        |          | Expected |         
                 |                  | C1       |        | C2       |        |        |        |        |        |          | Count =  | Actual  
Selected String  | New String       | Bin      | C1     | Bin      | C2     | y1     | y2     | y3     | y4     | f(x)     | f/avg    | Count   
----------------------------------------------------------------------------------------------------------------------------------------------
010010001100     | 010101101010     |       21 |   0.33 |       42 |   2.67 |   3.00 |   3.33 |   4.00 |   4.67 |   391.44 |     1.08 |    1
010101101010     | 010010001100     |       18 |   0.00 |       12 |  -0.67 |  -0.67 |  -0.67 |  -0.67 |  -0.67 |   332.22 |     0.92 |    1
010101001001     | 010101001010     |       21 |   0.33 |       10 |  -0.89 |  -0.56 |  -0.22 |   0.44 |   1.11 |   362.21 |     1.00 |    1
100100001010     | 100100001001     |       36 |   2.00 |        9 |  -1.00 |   1.00 |   3.00 |   7.00 |  11.00 |   358.00 |     0.99 |    1

                                                                                                            sum =  1443.88
                                                                                                        average =   360.97
                                                                                                        maximum =   391.44

Enter 1 to display next iteration, any other number to exit: 1
                 |                  |          |        |          |        |        |        |        |        |          | Expected |         
                 |                  | C1       |        | C2       |        |        |        |        |        |          | Count =  | Actual  
Selected String  | New String       | Bin      | C1     | Bin      | C2     | y1     | y2     | y3     | y4     | f(x)     | f/avg    | Count   
----------------------------------------------------------------------------------------------------------------------------------------------
010101101010     | 010010001100     |       18 |   0.00 |       12 |  -0.67 |  -0.67 |  -0.67 |  -0.67 |  -0.67 |   332.22 |     0.94 |    1
010010001100     | 010101101010     |       21 |   0.33 |       42 |   2.67 |   3.00 |   3.33 |   4.00 |   4.67 |   391.44 |     1.11 |    1
010101001010     | 010100001001     |       20 |   0.22 |        9 |  -1.00 |  -0.78 |  -0.56 |  -0.11 |   0.33 |   348.52 |     0.98 |    1
100100001001     | 100101001010     |       37 |   2.11 |       10 |  -0.89 |   1.22 |   3.33 |   7.56 |  11.78 |   344.04 |     0.97 |    1

                                                                                                            sum =  1416.22
                                                                                                        average =   354.06
                                                                                                        maximum =   391.44
