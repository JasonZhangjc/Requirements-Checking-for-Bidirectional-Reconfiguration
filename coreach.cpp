#include "coreach.h"

// This actually checking requirement 4 for nonblockingness. 
// The essence of this part is to check coreachability.
// The reachability has been checked when creating the state predicates.
void looseCoreach(ads& a, vector<set<string>>& states, 
                                   vector<vector<string>>& events) {
	set<string> dst;         // insert and delete are efficient in set
	vector<string> mark = a.getMarker();
	int flag_0 = 0;
	int flag_f = 0;
	for (auto i : states) {  // i is a set<string>, the state set
		for (auto j : mark) { // j is a string in marker of ads
			set<string>::iterator itm;
			itm = i.find(j);
		
			if (itm != i.end()) { // if j is found in i
				dst.insert(j);
			}
		} // dst contains marker states now
		
		vector<tran> tr = a.getTrans();        // the tran set
		vector<string> ev = events.at(flag_0); // the event set
		set<string> dst_ori;
		while (dst_ori.size() != dst.size()) {
			dst_ori = dst;
			for (auto k : tr) {
				vector<string>::iterator ite;
				ite = find(ev.begin(), ev.end(), k.getEvt());
				set<string>::iterator itt;
				itt = dst.find(k.getTgt());
				if (ite != ev.end() && itt != dst.end()) {
					dst.insert(k.getSrc());
				}
			}
		}
		
		cout << "In dst, for mode " << flag_0+1 << " there are : " << endl;
		for (auto p : dst) {
			cout << p << " ";
		}
		cout << endl;
		
		if (dst == i) {
			cout << "The mode " << flag_0+1 << " is nonblocking itself! " << endl;
		}
		else {
			flag_f = 1;
			cout << "The mode " << flag_0+1 << " is NOT nonblocking itself! " << endl;
		}
		
		flag_0++;
		dst.clear(); // Clear the set is very important!!!!!!!!
		// set<string>().swap(dst); 
	}
	if (flag_f == 1) {
		cout << "The requirement 4 is NOT satisfied! " << endl;
	}
	else {
		cout << "The requirement 4 is satisfied! " << endl;;
	}
}


// This is for the strict coreachability checking!
// Need to add forcible events. See the book SCDES for details.
// Without forcibility checking! Hard to implement here. See guaranteedReach below!
void strictCoreach(set<string>& ts, set<string>& tt, vector<tran>& tr, 
                   vector<string>& states, vector<vector<string>>& fe) {
	set<string> state_list = tt;
	set<string> state_rem;
	for (auto q : states) {
		state_rem.insert(q);
	}
	
	for (auto i : state_list) {  // delete tt from state_rem
		set<string>::iterator its = state_rem.find(i);
		if (its != state_rem.end()) {
			state_rem.erase(i);
		}
	}
	
	cout << endl;
	cout << "The state_rem has states: " << endl;
	for (auto rm : state_rem) {
		cout << rm << " ";
	}
	cout << endl << endl;

	
	// Need to consider all controllable events!
	// Need a classification !!!!!
	// Need a while loop!!!!!!!!
	set<string> temp_rem;
	while (temp_rem != state_rem) {
	// if it is k-step coreachable, just let the while loop be a 10-th for loop
	temp_rem = state_rem;
		// Core loop!!!!!!!!!!!!!!!!!
		for (auto a1 : state_rem) {  // for all remaining states
			int flag_2 = 0;  // is for controllable transitions
			int flag_3 = 0;  // is for coreachability
			for (auto a2 : tr) {     // for all transitions
				if (a2.getSrc() == a1) {
					int flag_4 = stoi(a2.getEvt()) % 2;
					if (flag_4 == 0) {
						flag_2 = 1;  // there exists uncontrollable transitions
						break;
					}
					
				}
			}
		
			// Use two loops to accelerate!
			for (auto a3 : tr) {     // for all transitions
				if (a3.getSrc() == a1) {
					set<string>::iterator it3 = state_list.find(a3.getTgt());
					if (it3 != state_list.end()) {
						flag_3 = 1;  // there exists coreachable transitions
						break;
					}
				}
			}
		
			// Three conditions!!!!!!!!!!!!!!!!!!!!
			if (flag_3 == 0) { // controllable and unconreachable
			}
			else if (flag_2 == 0 && flag_3 == 1) { // controllable and coreachable
				for (auto a4 : tr) {
					if (a4.getSrc() == a1) {
						set<string>::iterator it4 = state_list.find(a4.getTgt());
						if (it4 != state_list.end()) {
							state_list.insert(a1);
							state_rem.erase(a1);
							break;
						}
					}
				}
			}
			else if (flag_2 == 1 && flag_3 == 1) { // uncontrollable and coreachable
			// add forcible condition here. Check forcibility first, if there is
			// no forcible transition leading to state_list, check all uncontr.
			// Make sure the physical meaning of forcible events is correct.
				int flag_1 = 0;
				for (auto k : tr) {    // for all transitions
					int flag_even = stoi(k.getEvt()) % 2;
					if (k.getSrc() == a1 && flag_even == 0) {
						set<string>::iterator it2 = state_list.find(k.getTgt());
						if (it2 != state_list.end()) {
						}
						else {
							flag_1 = 1;
						}
					}
				}
				if (flag_1 == 0) { // found a candidate
					state_list.insert(a1);
					state_rem.erase(a1);
				}
				else {
				}
			}
		}
	}


	cout << endl;
	cout << "The state_list has states: " << endl;
	for (auto ls2 : state_list) {
		cout << ls2 << " ";
	}
	cout << endl << endl;
	
	int flag_f = 0;
	for (auto p : ts) {
		set<string>::iterator itf = state_list.find(p);
		if (itf != state_list.end()) {
			cout << "The state " << p << " is strictly coreachable w.r.t "
			     << "the destination states chosen by the user! " << endl;
		}
		else {
			cout << "The state " << p << " is NOT strictly coreachable w.r.t "
			     << "the destination states chosen by the user! " << endl;
			flag_f = 1;
		}
	}
	
	if (flag_f == 1) {
		cout << "There are some source states that are NOT strictly coreachable!" 
		     << endl;
	}
	else {
		cout << "All source states are strictly coreachable! " << endl;
	}
}




// k-step coreachable
// Without forcibility checking! Hard to implement here. See guaranteedReach below!
void kStepCoreach(set<string>& ts, set<string>& tt, vector<tran>& tr, 
                  vector<string>& states, vector<vector<string>>& fe,
                  int steps) {
	set<string> state_list = tt;
	set<string> state_rem;
	for (auto q : states) {
		state_rem.insert(q);
	}
	
	for (auto i : state_list) {  // delete tt from state_rem
		set<string>::iterator its = state_rem.find(i);
		if (its != state_rem.end()) {
			state_rem.erase(i);
		}
	}
	
	cout << endl;
	cout << "The state_rem has states: " << endl;
	for (auto rm : state_rem) {
		cout << rm << " ";
	}
	cout << endl << endl;
	
	// Need to consider all controllable events!
	// Need a classification !!!!!
	// Need a while loop!!!!!!!!
	// if it is k-step coreachable, just let the while loop be a 10-th for loop
	for (int step=1; step<=steps; step++) {
		// Core loop!!!!!!!!!!!!!!!!!
		for (auto a1 : state_rem) {  // for all remaining states
			int flag_2 = 0;  // is for controllable transitions
			int flag_3 = 0;  // is for coreachability
			for (auto a2 : tr) {     // for all transitions
				if (a2.getSrc() == a1) {
					int flag_4 = stoi(a2.getEvt()) % 2;
					if (flag_4 == 0) {
						flag_2 = 1;  // there exists uncontrollable transitions
						break;
					}
					/*
					set<string>::iterator it3 = state_list.find(a2.getTgt());
					if (it3 != state_list.end()) {
						flag_3 = 1;  // there exists coreachable transitions
					}
					*/
				}
			}
		
			// Use two loops to accelerate!
			for (auto a3 : tr) {     // for all transitions
				if (a3.getSrc() == a1) {
					set<string>::iterator it3 = state_list.find(a3.getTgt());
					if (it3 != state_list.end()) {
						flag_3 = 1;  // there exists coreachable transitions
						break;
					}
				}
			}
		
			// Three conditions!!!!!!!!!!!!!!!!!!!!
			if (flag_3 == 0) { // controllable and unconreachable
			}
			else if (flag_2 == 0 && flag_3 == 1) { // controllable and coreachable
				for (auto a4 : tr) {
					if (a4.getSrc() == a1) {
						set<string>::iterator it4 = state_list.find(a4.getTgt());
						if (it4 != state_list.end()) {
							state_list.insert(a1);
							state_rem.erase(a1);
							break;
						}
					}
				}
			}
			else if (flag_2 == 1 && flag_3 == 1) { // uncontrollable and coreachable
			// add forcible condition here. Check forcibility first, if there is
			// no forcible transition leading to state_list, check all uncontr.
			// Make sure the physical meaning of forcible events is correct.
				int flag_1 = 0;
				for (auto k : tr) {    // for all transitions
					int flag_even = stoi(k.getEvt()) % 2;
					if (k.getSrc() == a1 && flag_even == 0) {
						set<string>::iterator it2 = state_list.find(k.getTgt());
						if (it2 != state_list.end()) {
						}
						else {
							flag_1 = 1;
						}
					}
				}
				if (flag_1 == 0) { // found a candidate
					state_list.insert(a1);
					state_rem.erase(a1);
				}
				else {
				}
			}
		}
	}


	cout << endl;
	cout << "The state_list has states: " << endl;
	for (auto ls2 : state_list) {
		cout << ls2 << " ";
	}
	cout << endl << endl;
	
	int flag_f = 0;
	for (auto p : ts) {
		set<string>::iterator itf = state_list.find(p);
		if (itf != state_list.end()) {
			cout << "The state " << p << " is strictly coreachable w.r.t "
			     << "the destination states chosen by the user! " << endl;
		}
		else {
			cout << "The state " << p << " is NOT strictly coreachable w.r.t "
			     << "the destination states chosen by the user! " << endl;
			flag_f = 1;
		}
	}
	
	if (flag_f == 1) {
		cout << "There are some source states that are NOT strictly coreachable!" 
		     << endl;
	}
	else {
		cout << "All source states are strictly coreachable! " << endl;
	}
}



// consistent with my backtracking algo!
// With forcible event setting!!!!!!!!!
// Infinite steps
set<string> guaranteedReach(set<string>& ts, set<string>& tt, vector<tran>& tr, 
                     vector<string>& states, vector<vector<string>>& fe) {
	set<string> state_list = tt;
	set<string> state_rem;
	for (auto q : states) {
		state_rem.insert(q);
	}
	
	for (auto i : state_list) {  // delete tt from state_rem
		set<string>::iterator its = state_rem.find(i);
		if (its != state_rem.end()) {
			state_rem.erase(i);
		}
	}
	
	cout << endl;
	cout << "The state_rem has states: " << endl;
	for (auto rm : state_rem) {
		cout << rm << " ";
	}
	cout << endl << endl;

	
	// Need to consider all controllable events!
	// Need a classification !!!!!
	// Need a while loop!!!!!!!!
	set<string> temp_rem;
	while (temp_rem != state_rem) {
	temp_rem = state_rem;
		// Core loop!!!!!!!!!!!!!!!!!
		for (auto a1 : state_rem) {  // for all remaining states
			int flag_2 = 0;  // is for controllable transitions
			int flag_3 = 0;
			int flag_force = 0;
			
			for (auto a2 : tr) {     // for all transitions
				if (a2.getSrc() == a1) {
					// Checking uncontrollable transitions
					int flag_4 = stoi(a2.getEvt()) % 2;
					set<string>::iterator it2 = state_rem.find(a2.getTgt());
					if (flag_4 == 0 && it2 != state_rem.end()) {
						flag_2 = 1;  // there exists uncontrollable transitions
						/*
						if (flag_3 == 1) {
							break;
						}
						*/
					}
					// Checking reachability
					set<string>::iterator it3 = state_list.find(a2.getTgt());
					if (it3 != state_list.end()) {
						flag_3 = 1;
						/*
						if (flag_2 == 1 || flag_force == 1) {
							break;
						}
						*/
					}
					// Checking forcible events
					for (auto fc : fe) {
						if (fc.at(0) == a2.getEvt()) {
							for (int iter=1; iter<fc.size(); iter++) {
								if (fc[iter] == a1) {
									if (it3 != state_list.end()) {
										flag_force = 1;
										break;
									}
								}
							}
						}
						if (flag_3 == 1 && flag_force == 1) {
							break;
						}
					}
				}
				if (flag_force == 1 && flag_3 == 1) {
					break;
				}
			}
			// Evaluation:
			// (No escape uncontr tran || forcible reach) && reachable
			if ((flag_2 == 0 || flag_force == 1) && flag_3 == 1) { 
				state_list.insert(a1);
				state_rem.erase(a1);
				cout << "State " << a1 << " is added! " << endl;
			}
			else {
			}
		}
	}


	cout << endl;
	cout << "The state_list has states: " << endl;
	for (auto ls2 : state_list) {
		cout << ls2 << " ";
	}
	cout << endl << endl;
	
	int flag_f = 0;
	for (auto p : ts) {
		set<string>::iterator itf = state_list.find(p);
		if (itf != state_list.end()) {
			cout << "The state " << p << " is strictly coreachable w.r.t "
			     << "the destination states chosen by the user! " << endl;
		}
		else {
			cout << "The state " << p << " is NOT strictly coreachable w.r.t "
			     << "the destination states chosen by the user! " << endl;
			flag_f = 1;
		}
	}
	
	if (flag_f == 1) {
		cout << "There are some source states that are NOT strictly coreachable!" 
		     << endl;
	}
	else {
		cout << "All source states are strictly coreachable! " << endl;
	}
	
	return state_list;
}



// For fewest steps! Efficient finding!!!!!!
set<string> efficientGR(set<string>& ts, set<string>& tt, vector<tran>& tr, 
                        vector<string>& states, vector<vector<string>>& fe) {
	
	set<string> state_list = tt;
	set<string> state_rem;
	for (auto q : states) {
		state_rem.insert(q);
	}
	
	for (auto i : state_list) {  // delete tt from state_rem
		set<string>::iterator its = state_rem.find(i);
		if (its != state_rem.end()) {
			state_rem.erase(i);
		}
	}
	
	cout << endl;
	cout << "The state_rem has states: " << endl;
	for (auto rm : state_rem) {
		cout << rm << " ";
	}
	cout << endl << endl;

	
	// Need to consider all controllable events!
	// Need a classification !!!!!
	// Need a while loop!!!!!!!!
	// int flag_found = 0;
	set<string> temp_rem;
	string set_ele = "";
	for (auto set_i : ts) {
		set_ele = set_i;
		// break;
	}
	cout << "The source state is : " << set_ele << endl; // ok
	
	while (temp_rem != state_rem) {
	temp_rem = state_rem;
	set<string> add_list;
		// Core loop!!!!!!!!!!!!!!!!! not okay
		for (auto a1 : state_rem) {  // for all remaining states
			int flag_2 = 0;   // is for controllable transitions
			int flag_3 = 0;
			int flag_force = 0;
			int flag_4 = 0;
			// cout << "enter a1 loop! " << endl;
			
			for (auto a2 : tr) {     // for all transitions
				if (a2.getSrc() == a1) {
					// Checking uncontrollable transitions
					flag_4 = stoi(a2.getEvt()) % 2;
					set<string>::iterator it2 = state_rem.find(a2.getTgt());
					if (flag_4 == 0 && it2 != state_rem.end()) {
						flag_2 = 1;  // there exists uncontrollable transitions
					}
					// Checking reachability
					set<string>::iterator it3 = state_list.find(a2.getTgt());
					if (it3 != state_list.end()) {
						flag_3 = 1;
					}
					// Checking forcible events
					for (auto fc : fe) {
						if (fc.at(0) == a2.getEvt()) {
							for (int iter=1; iter<fc.size(); iter++) {
								if (fc[iter] == a1) {
									if (it3 != state_list.end()) {
										flag_force = 1;
										break;
									}
								}
							}
						}
						if (flag_3 == 1 && flag_force == 1) {
							break;
						}
					}
				}
				if (flag_force == 1 && flag_3 == 1) {
					break;
				}
			} // a2 loop ends
			
			// Evaluation:
			// (No escape uncontr tran || forcible reach) && reachable
			if ((flag_2 == 0 || flag_force == 1) && flag_3 == 1) { 
				// state_list.insert(a1);
				if (a1 == set_ele) {  // Only consider one source state.
					state_list.insert(a1);
					cout << "The state_list contains : " << endl;
					for (auto sta_l : state_list) {
						cout << sta_l << " ";
					}
					cout << endl;
					return state_list;
					// flag_found = 1;
					// break;
				}
				
				add_list.insert(a1);
				state_rem.erase(a1);
				cout << "State " << a1 << " is added! " << endl;
				// deal with set
				cout << "The add_list contains : " << endl;
				for (auto ad : add_list) {
					cout << ad << " ";
				}
				cout << endl;
			}
				
			// cout << "1" << endl; // testing..................................................................
		} // a1 loop ends
// error.........................................
// memory is not enough!!!!!!!!!!!
		
		for (auto addl : add_list) {
		// cout << "2" << endl;
			state_list.insert(addl);
		}
		
		// cout << "3" << endl;
		add_list.clear();
	}


	cout << endl;
	cout << "The state_list has states: " << endl;
	for (auto ls2 : state_list) {
		cout << ls2 << " ";
	}
	cout << endl << endl;
	
	int flag_f = 0;
	for (auto p : ts) {
		set<string>::iterator itf = state_list.find(p);
		if (itf != state_list.end()) {
			cout << "The state " << p << " is strictly coreachable w.r.t "
			     << "the destination states chosen by the user! " << endl;
		}
		else {
			cout << "The state " << p << " is NOT strictly coreachable w.r.t "
			     << "the destination states chosen by the user! " << endl;
			flag_f = 1;
		}
	}
	
	if (flag_f == 1) {
		cout << "There are some source states that are NOT strictly coreachable!" 
		     << endl;
	}
	else {
		cout << "All source states are strictly coreachable! " << endl;
	}
	
	return state_list;

                        
}





// k-step with forcible settings!!!!!!
void kStepGuaReach(set<string>& ts, set<string>& tt, vector<tran>& tr, 
                     vector<string>& states, vector<vector<string>>& fe,
                     int steps) {
	set<string> state_list = tt;
	set<string> state_rem;
	for (auto q : states) {
		state_rem.insert(q);
	}
	
	for (auto i : state_list) {  // delete tt from state_rem
		set<string>::iterator its = state_rem.find(i);
		if (its != state_rem.end()) {
			state_rem.erase(i);
		}
	}
	
	cout << endl;
	cout << "The state_rem has states: " << endl;
	for (auto rm : state_rem) {
		cout << rm << " ";
	}
	cout << endl << endl;

	
	// Need to consider all controllable events!
	// Need a classification !!!!!
	// Need a while loop!!!!!!!!
	
	for (int step=1; step<=steps; step++) {
		// Core loop!!!!!!!!!!!!!!!!!
		for (auto a1 : state_rem) {  // for all remaining states
			int flag_2 = 0;  // is for controllable transitions
			int flag_3 = 0;
			int flag_force = 0;
			
			for (auto a2 : tr) {     // for all transitions
				if (a2.getSrc() == a1) {
					// Checking uncontrollable transitions
					int flag_4 = stoi(a2.getEvt()) % 2;
					set<string>::iterator it2 = state_rem.find(a2.getTgt());
					if (flag_4 == 0 && it2 != state_rem.end()) {
						flag_2 = 1;  // there exists uncontrollable transitions
						/*
						if (flag_3 == 1) {
							break;
						}
						*/
					}
					// Checking reachability
					set<string>::iterator it3 = state_list.find(a2.getTgt());
					if (it3 != state_list.end()) {
						flag_3 = 1;
						/*
						if (flag_2 == 1 || flag_force == 1) {
							break;
						}
						*/
					}
					// Checking forcible events
					for (auto fc : fe) {
						if (fc.at(0) == a2.getEvt()) {
							for (int iter=1; iter<fc.size(); iter++) {
								if (fc[iter] == a1) {
									if (it3 != state_list.end()) {
										flag_force = 1;
										break;
									}
								}
							}
						}
						if (flag_3 == 1 && flag_force == 1) {
							break;
						}
					}
				}
				if (flag_force == 1 && flag_3 == 1) {
					break;
				}
			}
			// Evaluation:
			// (No escape uncontr tran || forcible reach) && reachable
			if ((flag_2 == 0 || flag_force == 1) && flag_3 == 1) { 
				state_list.insert(a1);
				state_rem.erase(a1);
				cout << "State " << a1 << " is added! " << endl;
			}
			else {
			}
		}
	}


	cout << endl;
	cout << "The state_list has states: " << endl;
	for (auto ls2 : state_list) {
		cout << ls2 << " ";
	}
	cout << endl << endl;
	
	int flag_f = 0;
	for (auto p : ts) {
		set<string>::iterator itf = state_list.find(p);
		if (itf != state_list.end()) {
			cout << "The state " << p << " is strictly coreachable w.r.t "
			     << "the destination states chosen by the user in " << steps 
			     << " steps! " << endl;
		}
		else {
			cout << "The state " << p << " is NOT strictly coreachable w.r.t "
			     << "the destination states chosen by the user in " << steps 
			     << " steps! " << endl;
			flag_f = 1;
		}
	}
	
	if (flag_f == 1) {
		cout << "There are some source states that are NOT strictly coreachable!" 
		     << endl;
	}
	else {
		cout << "All source states are strictly coreachable in " << steps 
		     << " steps!" << endl;
	}
}


