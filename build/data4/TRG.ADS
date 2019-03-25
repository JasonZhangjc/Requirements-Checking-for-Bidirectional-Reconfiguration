# CTCT ADS auto-generated

TRG

State size (State set will be (0,1....,size-1)):
# <-- Enter state size, in range 0 to 2000000, on line below.
40

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
5     1   10   
5     7   11   
5     91  7    
5     93  12   
6     2   13   
6     5   14   
6     95  4    
6     97  8    
7     1   14   
7     7   15   
7     95  5    
7     97  12   
8     2   16   
8     89  6    
8     99  4    
9     3   17   
9     5   18   
9     91  13   
9     93  16   
10    2   18   
10    7   19   
10    91  14   
10    93  20   
11    1   19   
11    8   1    
11    91  15   
11    93  21   
12    1   20   
12    89  7    
12    99  5    
13    3   22   
13    5   23   
13    95  9    
13    97  16   
14    2   23   
14    7   24   
14    95  10   
14    97  20   
15    1   24   
15    8   2    
15    95  11   
15    97  21   
16    33  3    
16    89  13   
16    99  9    
17    13  25   
18    3   26   
18    7   27   
18    91  23   
18    93  28   
19    2   27   
19    8   4    
19    91  24   
19    93  29   
20    2   28   
20    89  14   
20    99  10   
21    1   29   
21    89  15   
21    99  11   
22    23  30   
23    3   31   
23    7   32   
23    95  18   
23    97  28   
24    2   32   
24    8   6    
24    95  19   
24    97  29   
25    14  1    
26    13  33   
27    3   34   
27    8   9    
27    91  32   
27    93  35   
28    33  12   
28    89  23   
28    99  18   
29    2   35   
29    89  24   
29    99  19   
30    24  2    
31    23  36   
32    3   37   
32    8   13   
32    95  27   
32    97  35   
33    14  5    
34    13  38   
35    33  21   
35    89  32   
35    99  27   
36    24  7    
37    23  39   
38    14  11   
39    24  15   

