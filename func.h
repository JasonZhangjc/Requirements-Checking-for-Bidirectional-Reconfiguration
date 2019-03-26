#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "ads.h"
#include "transition.h"

using namespace std;

/* These are the functions for the FUNDAMENTAL OPERATIONS */

// The trim func is to delete spaces at the beginning and the end of a string.
string& trim(string &);

// The splitString func is used to split strings.
void splitString(const string& s, vector<string>& v, const string& c);

// The splitString func using set instead of vector
// should be more efficient than vector sometimes
// MIE and RE cannot use this, since they have order.
void splitStringSet(const string& s, set<string>& v, const string& c);

// The splitAds func is used to split transitions in .ADS file
tran splitAds(string &s);  // don't set s to be const

// The readin func is used to read in the content from a .ADS file.
void readin(ads& a);

// The readExtra func is used to read in the content from a .txt file.
// void readExtra(vector<string>& v_mie, vector<string>& v_re, vector<vector<string>>& alphabet);

#endif // FUNC_H
