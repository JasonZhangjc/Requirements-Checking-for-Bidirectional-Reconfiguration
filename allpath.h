#ifndef ALLPATH_H
#define ALLPATH_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef vector<string> Path;
typedef vector<string>::iterator Path_it;
typedef vector<Path> PathSet;
typedef vector<Path>::const_iterator Paths;

vector<string> findAllPaths(const string& src, const string& dst, 
	                        set<string>& sta_rch, map<string, set<string>>& s_t);

#endif // ALLPATH_H
