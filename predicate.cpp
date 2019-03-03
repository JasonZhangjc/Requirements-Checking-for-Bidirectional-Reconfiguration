#include "predicate.h"

predicate::predicate(){}
vector<set<string>> predicate::getMode_states(){return mode_states;}
void predicate::setMode_states(ads& a, vector<vector<string>>& events, 
                               vector<string>& v_mie, map<int,string>& m_init) {

	cout << "Setting modes now!!! " << endl;
	for (int i = 0; i < events.size(); i++) {

		// insert and delete is fast for 'set'
		// find and push_back is fast for 'vector'
		string ev_init = m_init[i+1];
		set<string> s;
		
		// modify alphabet again!
		for (auto k : a.getTrans()) {
			string ev_mie_temp = k.getEvt();
			string src_temp = k.getSrc();
			if (src_temp == "0" && ev_mie_temp == ev_init) {
				s.insert(k.getTgt());
				break;
			}
		}
		
		cout << "The mie now is : " << endl;
		cout << ev_init << endl;
		
		cout << "In the set<string> s, there are : " << endl;
		for (auto q : s) {
			cout << q << " ";
		}
		cout << endl;
		
		// Redo the predicate core part
		set<string> s_ori;
		while (s_ori != s) { // Take a careful look at the extra_event.txt!!!!!
			s_ori = s;
			
			cout << "In s, there are : " << endl;
			for (auto q1 : s) {
				cout << q1 << " ";
			}
			cout << endl;
			
			cout << "In s_ori, there are : " << endl;
			for (auto q2 : s_ori) {
				cout << q2 << " ";
			}
			cout << endl;
			
			
			for (auto p : a.getTrans()) {
				set<string>::iterator its;
				its = s.find(p.getSrc());
				vector<string>::iterator ite;
				ite = find(events.at(i).begin(), events.at(i).end(), p.getEvt());
				if (its != s.end() && ite != events.at(i).end()) {
					s.insert(p.getTgt());
				}
			}
		}
		
		/*
		for (auto j: a.getTrans()) {
			vector<string>::iterator it = 
			      find(events.at(i).begin(), events.at(i).end(), j.getEvt());
			if (it != events.at(i).end()) {
				s.insert(j.getTgt());
			}
		}
		*/
		cout << "The No." << i+1 << " mode has states: " << endl;
		for (auto i : s) {
			cout << i << " ";
		}
		cout << endl;
		cout << "The number of states in mode " << i+1 << " are: " << endl;
		cout << s.size() << endl;
		
		mode_states.push_back(s);
		
		s.clear();                   // clear and swap are very important!!!!!
		s_ori.clear();
		set<string>().swap(s); 
		set<string>().swap(s_ori); 
	}
}

/*
void predicate::printMode_states() {
	int flag = 1;
	cout << "Printing states of different modes now! " << endl;
	for (auto i : mode_states) {
		cout << "The No." << flag << " mode has states: " << endl;
		set<string> s = i;
		for (auto j : s) {
			cout << j << " ";
		}
		cout << endl;
		flag++;
	}
}
*/
