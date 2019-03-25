# CTCT ADS auto-generated

TRG

State size (State set will be (0,1....,size-1)):
# <-- Enter state size, in range 0 to 2000000, on line below.
28

Marker states:
# <-- Enter marker states, one per line.
# To mark all states, enter *.
# If no marker states, leave line blank.
# End marker list with blank line.
1
2
3

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
0     85  3    
1     1   4    
1     5   5    
1     91  2    
1     93  3    
2     1   6    
2     5   7    
2     95  1    
2     97  3    
3     1   8    
3     89  2    
3     99  1    
4     2   9    
4     5   10   
4     91  6    
4     93  8    
5     7   11   
6     2   12   
6     5   13   
6     95  4    
6     97  8    
7     7   14   
8     2   15   
8     89  6    
8     99  4    
9     5   16   
9     13  17   
9     91  12   
9     93  15   
10    7   18   
11    8   1    
12    5   19   
12    23  20   
12    95  9    
12    97  15   
13    7   21   
14    8   2    
15    33  3    
15    89  12   
15    99  9    
16    7   22   
16    13  23   
17    5   23   
17    14  1    
18    8   4    
19    7   24   
19    23  25   
20    5   25   
20    24  2    
21    8   6    
22    8   9    
22    13  26   
23    7   26   
23    14  5    
24    8   12   
24    23  27   
25    7   27   
25    24  7    
26    8   17   
26    14  11   
27    8   20   
27    24  14   

