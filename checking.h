#ifndef CHECKING_H
#define CHECKING_H

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

/* These are the functions for the REQUIREMENTS CHECKING */

// Check the first requirement
void checkFirst(ads& a, vector<string>& v_mie);

void firstCheck(map<string, set<string>>& e_s); // check src, evt, tgt

// Check the second requirement
void checkSecond(ads& a, vector<string>& v_re, vector<set<string>>& states,
                 map<string, int>& m_src, map<string, int>& m_tgt);

#endif // CHECKING_H
