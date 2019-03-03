#ifndef PREDICATE_H
#define PREDICATE_H

#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>

#include "ads.h"
#include "transition.h"
#include "alphabet.h"
 
using namespace std;

/* This is the class for the MODE PREDICATE */

class predicate{
public:
	predicate();
	vector<set<string>> getMode_states();
	void setMode_states(ads& a, vector<vector<string>>& events, 
	                    vector<string>& v_mie, map<int,string>& m_init);
	// void printMode_states();
private:
	vector<set<string>> mode_states;
};

#endif // PREDICATE_H
