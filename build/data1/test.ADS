# CTCT ADS auto-generated

RG_392

State size (State set will be (0,1....,size-1)):
# <-- Enter state size, in range 0 to 2000000, on line below.
19

Marker states:
# <-- Enter marker states, one per line.
# To mark all states, enter *.
# If no marker states, leave line blank.
# End marker list with blank line.
1
2

Vocal states:
# <-- Enter vocal output states, one per line.
# Format: State  Vocal_Output.  Vocal_Output in range 10 to 99.
# Example: 0 10
# If no vocal states, leave line blank.
# End vocal list with blank line.

Transitions:
# <-- Enter transition triple, one per line.
# Format: Exit_(Source)_State  Transition_Label  Entrance_(Target)_State.
# Transition_Label in range 0 to 999.
# Example: 2 0 1 (for transition labeled 0 from state 2 to state 1).
0     81  1    
0     83  2    
1     11  3    
1     21  4    
1     91  2    
2     11  5    
2     93  1    
2     211 6    
3     10  1    
3     12  7    
3     21  8    
3     91  5    
4     11  8    
4     20  1    
4     22  9    
4     91  6    
5     12  10   
5     93  3    
5     100 2    
5     211 11   
6     11  11   
6     20  2    
6     22  12   
6     93  4    
7     13  1    
7     21  13   
7     91  10   
8     10  4    
8     12  13   
8     20  3    
8     22  14   
8     91  11   
9     11  14   
9     23  1    
9     91  12   
10    13  2    
10    93  7    
10    211 15   
11    12  15   
11    20  5    
11    22  16   
11    93  8    
11    100 6    
12    11  16   
12    23  2    
12    93  9    
13    13  4    
13    20  7    
13    22  17   
13    91  15   
14    10  9    
14    12  17   
14    23  3    
14    91  16   
15    13  6    
15    20  10   
15    22  18   
15    93  13   
16    12  18   
16    23  5    
16    93  14   
16    100 12   
17    13  9    
17    23  7    
17    91  18   
18    13  12   
18    23  10   
18    93  17   

