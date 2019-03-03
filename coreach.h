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

/* These are the functions for the REACHABILITY CHECKING */

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


#endif // COREACH_H
