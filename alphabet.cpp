#include "alphabet.h"

/* This is the class for the alphabet */

alphabet::alphabet(){}

vector<string> alphabet::getMIE(){return MIE;}
vector<string> alphabet::getRE(){return RE;}
vector<vector<string>> alphabet::getMode_events(){return mode_events;}
// map<string, int*> alphabet::getRec(){return rec;}
map<string, int> alphabet::getMode_src(){return mode_src;}
map<string, int> alphabet::getMode_tgt(){return mode_tgt;}
map<int, string> alphabet::getMode_init(){return mode_init;}
set<string> alphabet::getTest_src(){return test_src;}
set<string> alphabet::getTest_tgt(){return test_tgt;}
vector<vector<string>> alphabet::getForce(){return force;}
int alphabet::getNum_step(){return num_step;}
set<string> alphabet::getWeak_force(){return weak_force;}

// Not using this any more......
void alphabet::readExtra() {
	string temp;             // Store the content of every line.
	
   	ifstream myfile("extra_event.txt");

    if (!myfile.is_open()) { 
        cerr << "Couldn't open the extra file!" << endl;  
    }
    
    // Store the MIEs.
    getline(myfile, temp);
    splitString(temp, MIE, ",");
    // Store the REs.
    getline(myfile, temp);
    splitString(temp, RE, ",");
	// Store the event alphabets for different modes.
    getline(myfile, temp);
    while (temp != "") {
    	vector<string> temp_vec;
    	splitString(temp, temp_vec, ",");
    	mode_events.push_back(temp_vec);
    	getline(myfile, temp);
    }
    
    // Store the meanings of each mode initialization event
    getline(myfile, temp);
    while (temp != "") {
    	vector<string> temp_init;
    	splitString(temp, temp_init, ",");
    	cout << "What is the mode number for MIE? " << stoi(temp_init.at(1)) 
    	     << endl;
    	mode_init.insert(pair<int,string>(stoi(temp_init.at(1)), temp_init.at(0)));
    	getline(myfile, temp);
    }
    
    // Store the meanings of each reconfiguration event
    getline(myfile, temp);
    while (temp != "") {
    	vector<string> temp_rec;
    	splitString(temp, temp_rec, ",");
    	cout << "What is the mode number for RE? " << stoi(temp_rec.at(1)) << " & " 
    	     << stoi(temp_rec.at(2)) << endl;
    	// int array[2] = {0};
    	// array[0] = stoi(temp_rec.at(1));
    	// array[1] = stoi(temp_rec.at(2));
    	// rec.insert(pair<string, int*>(temp_rec.at(0), arr));
    	mode_src.insert(pair<string,int>(temp_rec.at(0), stoi(temp_rec.at(1))));
    	mode_tgt.insert(pair<string,int>(temp_rec.at(0), stoi(temp_rec.at(2))));
    	getline(myfile, temp);
    }
}


// User-friendly reading function!!!!! Don't need to modify.......
void alphabet::readExtraFriendly() {
	string temp;             // Store the content of every line.
	
   	ifstream myfile("extra_friendly.txt");

    if (!myfile.is_open()) { 
        cerr << "Couldn't open the extra file!" << endl;  
    }
    
    // Store the MIEs.
    getline(myfile, temp);
    getline(myfile, temp);
    splitString(temp, MIE, ",");
    getline(myfile, temp);
    // Store the REs.
    getline(myfile, temp);
    getline(myfile, temp);
    splitString(temp, RE, ",");
    getline(myfile, temp);
	// Store the event alphabets for different modes.
    getline(myfile, temp);
    getline(myfile, temp);
    while (temp != "") {
    	vector<string> temp_vec;
    	splitString(temp, temp_vec, ",");
    	mode_events.push_back(temp_vec);
    	getline(myfile, temp);
    }
    
    // Store the meanings of each mode initialization event
    getline(myfile, temp);
    getline(myfile, temp);
    while (temp != "") {
    	vector<string> temp_init;
    	splitString(temp, temp_init, ",");
    	cout << "What is the mode number for MIE? " << stoi(temp_init.at(1)) 
    	     << endl;
    	mode_init.insert(pair<int,string>(stoi(temp_init.at(1)), temp_init.at(0)));
    	getline(myfile, temp);
    }
    
    // Store the meanings of each reconfiguration event
    getline(myfile, temp);
    getline(myfile, temp);
    while (temp != "") {
    	vector<string> temp_rec;
    	splitString(temp, temp_rec, ",");
    	cout << "What is the mode number for RE? " << stoi(temp_rec.at(1)) << " & " 
    	     << stoi(temp_rec.at(2)) << endl;
    	// int array[2] = {0};
    	// array[0] = stoi(temp_rec.at(1));
    	// array[1] = stoi(temp_rec.at(2));
    	// rec.insert(pair<string, int*>(temp_rec.at(0), arr));
    	mode_src.insert(pair<string,int>(temp_rec.at(0), stoi(temp_rec.at(1))));
    	mode_tgt.insert(pair<string,int>(temp_rec.at(0), stoi(temp_rec.at(2))));
    	getline(myfile, temp);
    }
    
    // Store the source set and the target set for testing!
    getline(myfile, temp);
    getline(myfile, temp);     // source states
    vector<string> temp_src;
    splitString(temp, temp_src, ",");
    cout << "What are the source states? " << endl;
    for (auto i : temp_src) {
    	test_src.insert(i);
    	cout << i << " ";
    }
    cout << endl;
    
    getline(myfile, temp);     // target states
    vector<string> temp_tgt;
    splitString(temp, temp_tgt, ",");
    cout << "What are the target states? " << endl;
    for (auto j : temp_tgt) {
    	test_tgt.insert(j);
    	cout << j << " ";
    }
    cout << endl; 
    
    // The forcible events and the corresponding states:
    getline(myfile, temp);
    getline(myfile, temp);
    getline(myfile, temp);   // Triple getline~
    while (temp != "") {
    	vector<string> temp_force;
    	splitString(temp, temp_force, ",");
    	cout << "What is the forcible event and the corresponding states? " 
    	     << endl;
        for (auto fc : temp_force) {
        	cout << fc << " ";
        }
        cout << endl;
    	force.push_back(temp_force);
    	getline(myfile, temp);
    }
    
    // The step limit of guaranteed reachability checking:
    getline(myfile, temp);
    getline(myfile, temp);
    num_step = stoi(temp);
    getline(myfile, temp);
    
    // weakly forcible events:
    getline(myfile, temp);
    getline(myfile, temp);
    splitStringSet(temp, weak_force, ",");
    getline(myfile, temp);
}




void alphabet::printMIE() {
	cout << "The MIEs are: " << endl;
	for (auto i : MIE) {
		cout << i << endl;
	}
}
void alphabet::printRE() {
	cout << "The REs are: " << endl;
	for (auto i : RE) {
		cout << i << endl;
	}
}
void alphabet::printMode_events() {
	cout << "The alphabets for different modes are: " << endl;
	int idx = 0;
	for (auto i : mode_events) {
		for (auto j : mode_events.at(idx)) {
			cout << j << " ";
		}
		cout << endl;
		idx++;
	}
}
/*
void alphabet::printRec() {
	cout << "The meanings of REs are: " << endl;
	for (auto i : rec) {
		cout << i.first << ": " 
		     << i.second[0] << " -> " << i.second[1] << endl;
	}
}
*/
void alphabet::printMode_src() {
	cout << "The source mode of the RE is : " << endl;
	for (auto i : mode_src) {
		cout << i.first << ": " << i.second << endl;
	}
}
void alphabet::printMode_tgt() {
	cout << "The target mode of the RE is : " << endl;
	for (auto i : mode_tgt) {
		cout << i.first << ": " << i.second << endl;
	}
}
void alphabet::printMode_init() {
	cout << "The mode of MIE is : " << endl;
	for (auto i : mode_init) {
		cout << i.second << ": " << i.first << endl;
	}
}
void alphabet::printTest_src() {
	cout << "The source states for test are : " << endl;
	for (auto i : test_src) {
		cout << i << " ";
	}
	cout << endl;
}
void alphabet::printTest_tgt() {
	cout << "The target states for test are : " << endl;
	for (auto i : test_tgt) {
		cout << i << " ";
	}
	cout << endl;
}
void alphabet::printForce() {
	cout << "The forcible events and corresponding states are : " << endl;
	for (auto i : force) {
		for (auto j : i) {
			cout << j << " ";;
		}
		cout << endl;
	}
	cout << endl;
}
void alphabet::printNum_step() {
	cout << "The step limit is : " << num_step << endl;
}
void alphabet::printWeak_force() {
	cout << "The weakly forcible events are : " << endl;
	for (auto i : weak_force) {
		cout << i << " ";
	}
	cout << endl;
}
