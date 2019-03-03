# Requirements Checking for Dynamic Bidirectional Reconfiguration
This is a program for requirements checking, guaranteed reachability checking, and paths finding of a dynamic bidirectional reconfiguration problem in the DES framework.


Required tools:
 1. cmake (See here: https://cmake.org/download/)
 2. c++11/14
 
To build the project:
 1. Go to 'build' directory
 2. Put 'test.ADS' and 'extra_friendly.txt' in the 'build' directory
 3. Run cmake ..
 4. Run make
 5. Run ./check 
 6. The result is saved in 'result.txt' in the 'build' directory
 
</br>
The 'test.ADS' is the reconfiguration plant generated by the software TCT. Can also be seen as a graph. (see the attached GIF) </br>
The 'extra_friendly.txt' is to specify the reconfiguration specification of users. </br>

