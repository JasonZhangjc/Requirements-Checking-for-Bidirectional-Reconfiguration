#include "allpath.h"

vector<string> findAllPaths(const string& src, const string& dst, 
	set<string>& sta_rch, map<string, set<string>>& s_t) {
	
	Path p = {};  // p is to store a forcible paths found
	string shortest_path;
	int length = sta_rch.size();
	
	// Before that, an 'if statement' is needed
	if (sta_rch.find(src) == sta_rch.end()) {
		cout << "The source state is not in the GR set! " << endl;
		return p;
	}
	
	if (sta_rch.find(dst) == sta_rch.end()) {
		cout << "The destination state is not in the GR set! " << endl;
		return p;
	}
		

	
	cout << "The initialization has started! " << endl;
	// The only way to solve is to restrict p_s
	PathSet p_s;
	int i = 0;
	for (auto j : s_t) { // The state should be in sta_rch
		//cout << " 1 " << endl;
		set<string>::iterator it_sta_rch = sta_rch.find(j.first);
		//cout << " 2 " << endl;
		if (it_sta_rch != sta_rch.end()) {
		//cout << " 3 " << endl;
			Path temp_i;
			temp_i.insert(temp_i.end(), j.first);
			p_s.insert(p_s.end(), temp_i);
		//cout << " 4 " << endl;
			for (auto k : j.second) {
				set<string>::iterator it_k = sta_rch.find(k);
				if (it_k != sta_rch.end()) {
					p_s[i].insert(p_s[i].end(), k);
				}
			}
			i++;
		}
	}
	cout << "The p_s is: " << endl;
	for (auto i : p_s) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	
	
	// initialize the "in_stack" marker with all "0" (not in stack)
	map<string, string> in_stack;
	for (auto i : p_s) {
		in_stack.insert(pair<string, string>(i[0], "0"));
	}
	cout << "The in_stack is: " << endl;
	for (auto i : in_stack) {
		cout << i.first << " " << i.second << endl;
	}
	
	
	map<string, vector<string>> is_visited;
	for (auto i : p_s) {
		string key = i[0];
		// cout << "The key is : " << key << endl;
		is_visited.insert(pair<string, vector<string>>(key, i));
		vector<string>::iterator k = is_visited[key].begin();
    	is_visited[key].erase(k);
		for (auto &j : is_visited[key]) { // use 'yinyong' here!!1
			// cout << "6" << endl;
			// cout << j << endl;
			j = "0";
		}
	}
	cout << "The is_visited is: " << endl;
	for (auto i : is_visited) {
		cout << i.first << " : ";
		for (auto j : i.second) {
			cout << j << " ";
		}
		cout << endl;
	}
	
	
	// The algorithm is based on DFS
	Path stack = {};
	stack.insert(stack.end(), src);
	in_stack[src] = "1";
	cout << " Main loop starts! " << endl;
	
	  // Main loop
	while (!stack.empty()) {		
		  // Based on DFS 
		  // Use find to decide
		Path_it it_ele = find(is_visited[stack.back()].begin(), 
		                      is_visited[stack.back()].end(), "0");
		int n_pos = distance(is_visited[stack.back()].begin(), it_ele);
		while (it_ele != is_visited[stack.back()].end()) {
			int idx = 0;
		    for (int j=0; j<p_s.size(); j++) {
		    	if (p_s[j][0] == stack.back())
		       		break;
		       	idx++;
		    }
			if (in_stack[p_s[idx][n_pos + 1]] == "1") {
				is_visited[stack.back()][n_pos] = "1";
				break;
			}
			else {				
				if (!is_visited[stack.back()].empty())
					is_visited[stack.back()][n_pos] = "1";
				stack.insert(stack.end(), p_s[idx][n_pos + 1]);
				in_stack[p_s[idx][n_pos + 1]] = "1";
				//cout << "Push a new state in stack!" << endl;
				break;
			}
		}
        
		if (stack.back() == dst) {	
			string forcible_path = "";
			int length_temp = 0;
			
			Path_it it = stack.begin();
			for (; it != stack.end(); it++) {
				forcible_path = forcible_path + "->" + *it;
				length_temp++;
			}
			if (length_temp <= length) {
				length = length_temp;
				shortest_path = forcible_path;
			}
		
			cout << "Found a forcible path: " << forcible_path << endl;
			p.insert(p.end(), forcible_path);
		
			in_stack[stack.back()] = "0";
			stack.pop_back();	
		} 
            
		string marker = "0";
		Path_it itm = is_visited[stack.back()].begin();
		for( ; itm!=is_visited[stack.back()].end(); ++itm) {
			if (*itm == "0")
				marker = "1";
    	}
    	
    	if (marker == "0") {
    		in_stack[stack.back()] = "0";
    		Path_it itc = is_visited[stack.back()].begin();
			for( ; itc!=is_visited[stack.back()].end(); ++itc) {
				*itc = "0";
    		}
    		stack.pop_back();
    	}
    	
    	Path_it ito = stack.begin();			
    }
	
	cout << "There are " << sta_rch.size() << " states in the Q_RG." << endl;
	cout << "The states in the Q_RG are: " << endl;
	for (auto q_rg : sta_rch) {
		cout << q_rg << " ";
	}
	cout << endl;
	
	cout << "There are " << p.size() << " paths in total!" << endl;
	
	cout << "The shortest path has size " << length-1 << " !" << endl;
	cout << shortest_path << endl;
	
	return p;
	
}
