#include "checking.h"

void checkFirst(ads& a, vector<string>& v_mie) {
	int flag = 0;
	
	cout << "Checking the first requirement: " << endl;
	for (auto i : v_mie) {
		for (auto j : a.getTrans()) { // need to check: src, evt, tgt
			if (i == j.getEvt() && j.getSrc() == "0" && j.getTgt() != "0") {
				flag++;
				break;
			}
		}
	}
	
	if (flag != v_mie.size()) {
		cout << "The first requirement is NOT satisfied! " << endl;
	}
	else {
		cout << "The first requirement is satisfied! " << endl;
	}
}

// Event alphabets for different modes.
// Mode predicates
// (private events)
// Reachability
// Strict Reachability
// Paths finding

// For the reachability test, backtracking via all events in the specific mode,
// add all states along the way in a list, compare the list with the mode pred.

// For the fouth requirement for nonblocking, figure out the reachability from
// an arbitrary state in the mode to a (or more) marker state in the mode.
// The reachability func should take: 1. a list of destination state, 
// 2. the source state, 3. the event alphabets. The reaching transition just 
// need to exist, instead of for all transitions......


void checkSecond(ads& a, vector<string>& v_re, vector<set<string>>& states,
                  map<string, int>& m_src, map<string, int>& m_tgt) {
	int flag = 0;
	
	// Check twice: 1 for existence, 2 for universality
	cout << "Checking the existence requirement: " << endl;
	int flag_1 = 0;
	vector<tran> tr = a.getTrans();
	
	for (auto i : v_re) {
		for (auto j : tr) {
			if (j.getEvt() == i) {
				flag_1++;
				break;
			}
		}
	}
	if (flag_1 == v_re.size()) {
		cout << "The existence condition of the requirement 2 is satisfied!" 
		     << endl;
	}
	else {
		cout << "The existence condition of the requirement 2 is NOT satisfied!"
		     << endl;
	}
	
	// Check for universality
	cout << "Checking the universality requirement: " << endl;
	int flag_2 = 0;
	int flag_3 = 0; // check the third requirement in check_second func.
	int flag_3n = 0;
	
	for (auto i : tr) {
		vector<string>::iterator ite = find(v_re.begin(), v_re.end(), i.getEvt());
		if (ite != v_re.end()) {
			int m_s = m_src[i.getEvt()]; // The source state with key=i.getEvt()
			int m_t = m_tgt[i.getEvt()]; // The target state with key=i.getEvt()
			// cout << "m_s is: " << m_s << endl;
			// cout << "m_t is: " << m_t << endl;
			
			set<string>::iterator its;
			its = states.at(m_s-1).find(i.getSrc());
			set<string>::iterator itt;
			itt = states.at(m_t-1).find(i.getTgt());
			
			if (its != states.at(m_s-1).end() && itt != states.at(m_t-1).end())
			{}
			else {
				int flag_2 = 1;
			}
			
			// Check the third requirement: back & forth reconfiguration
			flag_3n++;
			string inv_event;
			for (auto j : v_re) {
				if (m_src[j] == m_t && m_tgt[j] == m_s) {
					inv_event = j;
					break;
				}
			}
			for (auto k : tr) {
				if (inv_event == k.getEvt() && k.getSrc() == i.getTgt() &&
				    						   k.getTgt() == i.getSrc()) {
					flag_3++;
					break;
				}
			}
			
		}
	}
	if (flag_2 == 1) {
		cout << "The universality condition of the requirement 2 is NOT satisfied!"
		     << endl;
	}
	else {
		cout << "The universality condition of the requirement 2 is satisfied!"
		     << endl;
	}
	
	if (flag_3 == flag_3n) {
		cout << "The requirement 3 is satisfied!"
		     << " The flag_3 is: " << flag_3 << endl;
	}
	else {
		cout << "The requirement 3 is NOT satisfied!"
		     << endl;
	}
	
}

void checkFifth(vector<set<string>>& states, vector<string>& states_ori) {
	cout << "Checking the fifth requirement: " << endl;
	cout << "If no further message showing that the fifth requirement is not met, " 
		 << "it is met! " << endl;
	set<string> temp;
	set<string> total;
	set<string> total_ori;
	// check intersection
	for (int i = 0; i < states.size(); i++) {
		for (int j = i+1; j < states.size(); j++) {
			set_intersection(states[i].begin(), states[i].end(), 
			                 states[j].begin(), states[j].end(),
			                 inserter(temp, temp.begin()));
			if (temp.empty()) {
			}
			else {
				cout << "The fifth requirement is not met! " << endl;
				cout << "The mode predicate " << i << " and the mode predicate "
				     << j << " have shared states: ";
				for (auto p : temp) {
					cout << p << " ";
				}
				cout << endl;
				break;
			}
		}
	}
	// check union
	for (int i = 0; i < states.size(); i++) {
		for (auto j : states[i]) {
			total.insert(j);
		}
	}
	
	set<string>::iterator it = total.find("0");
	if (it != total.end()) {
		cout << "The fifth requirement is not met! " << endl;
		cout << "The initial state 0 is in the predicate! " << endl;
	}
	
	total.insert("0");
	
	for (auto k : states_ori) {
		total_ori.insert(k);
	}
	
	if (total != total_ori) {
		cout << "The fifth requirement is not met! " << endl;
		cout << "The union of all mode predicates with 0 "
		     << "doesn't cover all states in the reconfiguration plant! "
		     << endl;
	}
	
}

// set_union(A.begin(),A.end(),B.begin(),B.end(),inserter( C1 , C1.begin() ) );
