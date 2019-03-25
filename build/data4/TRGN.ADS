# CTCT ADS auto-generated

TRGN

State size (State set will be (0,1....,size-1)):
# <-- Enter state size, in range 0 to 2000000, on line below.
34

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
9     3   16   
9     5   17   
9     91  12   
9     93  15   
10    7   18   
11    8   1    
12    3   19   
12    5   20   
12    95  9    
12    97  15   
13    7   21   
14    8   2    
15    33  3    
15    89  12   
15    99  9    
16    5   22   
16    13  23   
17    3   22   
17    7   24   
18    8   4    
19    5   25   
19    23  26   
20    3   25   
20    7   27   
21    8   6    
22    7   28   
22    13  29   
23    5   29   
23    14  1    
24    3   28   
24    8   9    
25    7   30   
25    23  31   
26    5   31   
26    24  2    
27    3   30   
27    8   12   
28    8   16   
28    13  32   
29    7   32   
29    14  5    
30    8   19   
30    23  33   
31    7   33   
31    24  7    
32    8   23   
32    14  11   
33    8   26   
33    24  14   

