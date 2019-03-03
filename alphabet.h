#ifndef ALPHABET_H
#define ALPHABET_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <set>

#include "func.h"
 
using namespace std;

/* Need struct for the map
struct Double 
{ 
    int array[2]; 
};
*/ 

/* This is the class for the ALPHABETS OF DIFFERENT MODES */

class alphabet{
public:
	alphabet();
	vector<string> getMIE();
	vector<string> getRE();
	vector<vector<string>> getMode_events();
	map<string, int> getMode_src();
	map<string, int> getMode_tgt();	
	map<int, string> getMode_init();
	set<string> getTest_src();
	set<string> getTest_tgt();
	vector<vector<string>> getForce();
	int getNum_step();
	
	void readExtra();
	void readExtraFriendly();
	void printMIE();
	void printRE();
	void printMode_events();
	void printMode_src();
	void printMode_tgt();
	void printMode_init();
	void printTest_src();
	void printTest_tgt();
	void printForce();
	void printNum_step();
private:
	vector<string> MIE;
	vector<string> RE;
	vector<vector<string>> mode_events;
	map<string, int> mode_src;
	map<string, int> mode_tgt;	
	map<int, string> mode_init;
	set<string> test_src;
	set<string> test_tgt;
	vector<vector<string>> force;
	int num_step;
};

#endif // ALPHABET_H
