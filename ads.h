#ifndef ADS_H
#define ADS_H

#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

#include "transition.h"
 
using namespace std;

/* This is the class for the ADS */

class ads{
public:
	ads();
	ads(string _name);
	string getName();
	int getSize();
	vector<string> getStates();
	vector<string> getMarker();
	vector<tran> getTrans();
	map<string, set<string>> getSrc_evt();
	map<string, set<string>> getTgt_evt();
	map<string, set<string>> getEvt_src();
	map<string, set<string>> getEvt_tgt();
	map<string, set<string>> getSrc_tgt();
	map<string, set<string>> getTgt_src();
	
	map<string, set<vector<string>>> getS_e_t();
	
	void setName(string _name);
	void setSize(int _size);
	void setStates();
	void addMarker(string _marker);
	void addTrans(tran _trans);
	void setMap();     // set six maps!!!! Very important
	
	void printAds();
	void printSrc_evt();
	void printTgt_evt();
	void printEvt_src();
	void printEvt_tgt();
	void printSrc_tgt();
	void printTgt_src();
	
	void printS_e_t();
	
private:
	string name;
	int size;
	vector<string> states;
	vector<string> marker;
	vector<tran> trans;
	map<string, set<string>> src_evt;
	map<string, set<string>> tgt_evt;
	map<string, set<string>> evt_src;
	map<string, set<string>> evt_tgt;
	map<string, set<string>> src_tgt;
	map<string, set<string>> tgt_src;
	
	map<string, set<vector<string>>> s_e_t;
};

#endif // ADS_H
