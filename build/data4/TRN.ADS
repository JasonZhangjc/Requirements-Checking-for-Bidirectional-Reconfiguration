# CTCT ADS auto-generated

TRN

State size (State set will be (0,1....,size-1)):
# <-- Enter state size, in range 0 to 2000000, on line below.
6

Marker states:
# <-- Enter marker states, one per line.
# To mark all states, enter *.
# If no marker states, leave line blank.
# End marker list with blank line.
1
2
3
4
5

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
1     1   1    
1     2   1    
1     5   1    
1     7   1    
1     8   1    
1     3   4    
1     91  2    
1     93  3    
2     1   2    
2     2   2    
2     5   2    
2     7   2    
2     8   2    
2     3   5    
2     95  1    
2     97  3    
3     1   3    
3     2   3    
3     33  3    
3     89  2    
3     99  1    
4     14  1 
4     13  4   
5     24  2
5     23  5    

