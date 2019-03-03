#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>

#include "transition.h"
#include "ads.h"
#include "func.h"
#include "checking.h"
#include "alphabet.h"
#include "predicate.h"
#include "coreach.h"
#include "allpath.h"


using namespace std;

int main() {

	ofstream ou("results.txt");
	streambuf *x = cout.rdbuf(ou.rdbuf());


	ads ad_0;                  // needs two constructors for ads class
	readin(ad_0);
	ad_0.setStates();
	ad_0.printAds();
	
	
	alphabet alp;
	// alp.readExtra();           // not using this func any more
	alp.readExtraFriendly();
	vector<string> mie = alp.getMIE();
	alp.printMIE();
	alp.printRE();
	alp.printMode_events();
	alp.printMode_src();
	alp.printMode_tgt();
	alp.printMode_init();
	alp.printTest_src();
	alp.printTest_tgt();
	alp.printForce();
	
	
	
	predicate pred;
	vector<vector<string>> m_events = alp.getMode_events();
	map<int, string> minit = alp.getMode_init();
	pred.setMode_states(ad_0, m_events, mie, minit);     // try predicate!
	
	
	vector<string> re = alp.getRE();
	vector<set<string>> m_states = pred.getMode_states();
	map<string, int> msrc = alp.getMode_src();
	map<string, int> mtgt = alp.getMode_tgt();
	 
	cout << endl;
	checkFirst(ad_0, mie);                     // Check the first requirement!
	checkSecond(ad_0, re, m_states, msrc, mtgt); // Check the second and the third requirement!
	looseCoreach(ad_0, m_states, m_events);        // Check the fourth requirement!
	
	// Check the strict coreachability or the so-called guaranteed reachability
	set<string> ts = alp.getTest_src();
	set<string> tt = alp.getTest_tgt();
	vector<tran> tr = ad_0.getTrans();
	vector<string> states_ori = ad_0.getStates();
	vector<vector<string>> forcible_ev = alp.getForce();
	int num_of_step = alp.getNum_step();
	
	strictCoreach(ts, tt, tr, states_ori, forcible_ev);
	set<string> gr;
	gr = guaranteedReach(ts, tt, tr, states_ori, forcible_ev); // most useful func for GR
	kStepGuaReach(ts, tt, tr, states_ori, forcible_ev, num_of_step);
	
	// The only task left is to generate all paths
	// six maps!
	ad_0.setMap();
	ad_0.printSrc_evt();
	ad_0.printTgt_evt();
	ad_0.printEvt_src();
	ad_0.printEvt_tgt();
	ad_0.printSrc_tgt();
	ad_0.printTgt_src();
	

	// Use 'src_tgt' or 'tgt_src' with the result of GR, which is 'gr'
	map<string, set<string>> s_t = ad_0.getSrc_tgt();
	set<string> test_src = alp.getTest_src();
	set<string> test_tgt = alp.getTest_tgt();
	vector<string> paths;
	string path_s = *test_src.begin();
	cout << "The path_s is : " << path_s << endl;
	string path_t = *test_tgt.begin();
	cout << "The path_t is : " << path_t << endl;
	
	paths = findAllPaths(path_s, path_t, gr, s_t);     // Paths finding! Output lots of things
	cout << endl;
	
	// Efficient GR Checking! 
	set<string> eff_gr;
	eff_gr = efficientGR(ts, tt, tr, states_ori, forcible_ev); // most useful func for GR
	paths = findAllPaths(path_s, path_t, eff_gr, s_t);     // Paths finding! Output lots of things
	ou.close();
	
	getchar();
	getchar();

return 0;
}

