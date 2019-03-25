# CTCT ADS auto-generated

RG_391

State size (State set will be (0,1....,size-1)):
# <-- Enter state size, in range 0 to 2000000, on line below.
29

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
2     31  6    
2     93  1    
3     10  1    
3     12  7    
3     21  8    
3     91  5    
4     11  8    
4     20  1    
4     22  9    
5     10  2    
5     12  10   
5     31  11   
5     93  3    
6     11  11   
6     30  2    
6     32  12   
7     13  13   
7     15  3    
7     21  14   
7     91  10   
8     10  4    
8     12  14   
8     20  3    
8     22  15   
9     11  15   
9     23  1    
10    13  16   
10    15  5    
10    31  17   
10    93  7    
11    10  6    
11    12  17   
11    30  5    
11    32  18   
12    11  18   
12    33  19   
12    35  6    
13    14  1    
13    21  20   
13    91  16   
14    13  20   
14    15  8    
14    20  7    
14    22  21   
15    10  9    
15    12  21   
15    23  3    
16    14  2    
16    31  22   
16    93  13   
17    13  22   
17    15  11   
17    30  10   
17    32  23   
18    10  12   
18    12  23   
18    33  24   
18    35  11   
19    11  24   
19    34  2    
20    14  4    
20    20  13   
20    22  25   
21    13  25   
21    15  15   
21    23  7    
22    14  6    
22    30  16   
22    32  26   
23    13  26   
23    15  18   
23    33  27   
23    35  17   
24    10  19   
24    12  27   
24    34  5    
25    14  9    
25    23  13   
26    14  12   
26    33  28   
26    35  22   
27    13  28   
27    15  24   
27    34  10   
28    14  19   
28    34  16   

