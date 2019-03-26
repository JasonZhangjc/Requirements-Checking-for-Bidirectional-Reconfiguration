#ifndef COREACH_H
#define COREACH_H

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#include "transition.h"
#include "ads.h"
#include "func.h"
#include "checking.h"
#include "alphabet.h"
#include "predicate.h"

using namespace std;

/* These are the functions for the GUARANTEED REACHABILITY CHECKING */

// Check the reachability without considering controllability,
// namely the loose reachability
void looseCoreach(ads& a, vector<set<string>>& states, 
                  vector<vector<string>>& events);

// Check the second requirement
void strictCoreach(set<string>& ts, set<string>& tt, vector<tran>& tr, 
                   vector<string>& states, vector<vector<string>>& fe);
                   
// k-step coreachable
void kStepCoreach(set<string>& ts, set<string>& tt, vector<tran>& tr, 
                  vector<string>& states, vector<vector<string>>& fe,
                  int steps);

// Guaranteed Rechability on SCDES
// Please use this func and the func below!
set<string> guaranteedReach(set<string>& ts, set<string>& tt, vector<tran>& tr, 
                     vector<string>& states, vector<vector<string>>& fe);
                     
// Using map to implement the original GR function
set<string> mapOriGR(set<string>& ts, set<string>& tt,
					 map<string, set<vector<string>>>& set_map, 
                     vector<string>& states, vector<vector<string>>& fe);

// Guaranteed Rechability with fewest steps needed.
// Under development. Design for efficiency.
set<string> efficientGR(set<string>& ts, set<string>& tt, vector<tran>& tr, 
                        vector<string>& states, vector<vector<string>>& fe);
                     
// K-step Guaranteed Rechability on SCDES
// Is not the real k-step
// k-step needs to be realized in forcible paths
void kStepGuaReach(set<string>& ts, set<string>& tt, vector<tran>& tr, 
                   vector<string>& states, vector<vector<string>>& fe, 
                   int steps);

// Guaranteed Rechability with fewer steps needed.
// Using 'map' (black-red-tree) for efficiency
set<string> mapGR(set<string>& ts, set<string>& tt, 
                  map<string, set<vector<string>>>& set_map, 
                  vector<string>& states, vector<vector<string>>& fe);

// GR for timed-DES.
// Using 'map' (black-red-tree) for efficiency
// Must consider weakly-forcible events and locally-strongly-forcible-event
set<string> timedGR(set<string>& ts, set<string>& tt, set<string> wf,
                    map<string, set<vector<string>>>& set_map, 
                    vector<string>& states, vector<vector<string>>& fe);

// original timed GR checking
set<string> timedOriGR(set<string>& ts, set<string>& tt, set<string> wf,
					   map<string, set<vector<string>>>& set_map, 
                       vector<string>& states, vector<vector<string>>& fe);


#endif // COREACH_H
