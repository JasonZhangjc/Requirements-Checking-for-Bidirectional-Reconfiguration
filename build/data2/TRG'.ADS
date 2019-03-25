# CTCT ADS auto-generated

TRG'

State size (State set will be (0,1....,size-1)):
# <-- Enter state size, in range 0 to 2000000, on line below.
35

Marker states:
# <-- Enter marker states, one per line.
# To mark all states, enter *.
# If no marker states, leave line blank.
# End marker list with blank line.
1
2
3
12
16

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
5     1   11   
5     6   12   
6     2   13   
6     5   14   
6     95  4    
6     97  8    
7     1   15   
7     6   16   
8     2   17   
8     89  6    
8     99  4    
9     5   18   
9     13  19   
9     91  13   
9     93  17   
10    2   20   
10    6   21   
11    2   20   
11    6   21   
11    91  15   
11    93  22   
12    1   4    
12    5   5    
13    5   23   
13    23  24   
13    95  9    
13    97  17   
14    2   25   
14    6   26   
15    2   25   
15    6   26   
15    95  11   
15    97  22   
16    1   6    
16    5   7    
17    33  3    
17    89  13   
17    99  9    
18    6   27   
18    13  28   
19    5   28   
19    14  1    
20    6   27   
20    13  28   
20    91  25   
20    93  29   
21    2   9    
21    5   10   
22    2   29   
22    89  15   
22    99  11   
23    6   30   
23    23  31   
24    5   31   
24    24  2    
25    6   30   
25    23  31   
25    95  20   
25    97  29   
26    2   13   
26    5   14   
27    5   18   
27    13  19   
28    6   19   
28    14  32   
29    33  33   
29    89  25   
29    99  20   
30    5   23   
30    23  24   
31    6   24   
31    24  34   
32    1   11   
32    6   12   
32    91  34   
32    93  33   
33    1   22   
33    89  34   
33    99  32   
34    1   15   
34    6   16   
34    95  32   
34    97  33   

