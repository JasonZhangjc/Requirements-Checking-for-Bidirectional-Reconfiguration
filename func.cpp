#include "func.h"

string& trim(string &s) 
{
    if (s.empty()) 
    {
        return s;
    }

    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
}


void splitString(const string& s, vector<string>& v, const string& c)
{
  	string::size_type pos1, pos2;
  	pos2 = s.find(c);
  	pos1 = 0;
  	while(string::npos != pos2)
  	{
    	v.push_back(s.substr(pos1, pos2-pos1));
 
    	pos1 = pos2 + c.size();
    	pos2 = s.find(c, pos1);
  	}
  	if(pos1 != s.length())
    	v.push_back(s.substr(pos1));
}


tran splitAds(string &s) {
	if (s.empty()) 
    {
        cerr << "The input string to <splitAds> is empty!";
    }
    // There are only three substrings to push, so easy
    // For the source state
    tran v;
    string::size_type pos1, pos2;
    pos1 = 0;
    pos2 = s.find(" ");
    // cout << "The source state is: " << s.substr(pos1, pos2-pos1) << endl;
    // cout << "The size of the substring 'source' is: "
    //     << s.substr(pos1, pos2-pos1).size() << endl;
   	v.setSrc(s.substr(pos1, pos2-pos1));
    // For the event
    s.erase(pos1, pos2);
    pos2 = s.find_first_not_of(" ");  // All spaces before the event
    s.erase(pos1, pos2);
    pos2 = s.find(" ");
    // cout << "The event is: " << s.substr(pos1, pos2-pos1) << endl;
    // cout << "The size of the substring 'event' is: "
    //     << s.substr(pos1, pos2-pos1).size() << endl;
   	v.setEvt(s.substr(pos1, pos2-pos1));
    // For the target state
    s.erase(pos1, pos2);
    pos2 = s.find_first_not_of(" ");  // All spaces before the target
    s.erase(pos1, pos2);
    pos2 = s.find(" ");
    // cout << "The target state is: " << s.substr(pos1, pos2-pos1) << endl;
    // cout << "The size of the substring 'target' is: "
    //     << s.substr(pos1, pos2-pos1).size() << endl;
    v.setTgt(s.substr(pos1, pos2-pos1));
    
    return v;
}


void readin(ads& a) {
	string temp;             // Store the content of every line.
	
   	ifstream myfile("test.ADS"); // Need to copy the content to a new .ADS file

    if (!myfile.is_open()) { 
        cerr << "Couldn't open the file!" << endl;  
    }
    
    // Count from the right place of the file.
    while(getline(myfile,temp)) { 	
    	if (temp == "# CTCT ADS auto-generated") {
    		getline(myfile,temp);
    		getline(myfile,temp);
    		cout << "Read in name of the .ADS " << temp << endl;
    		a.setName(temp);
    	}
    	
    	if (temp == "# <-- Enter state size, in range 0 to 2000000, on line below.") {
    		// Need a conversion from string to int
    		getline(myfile,temp);
    		int i = stoi(temp);
    		a.setSize(i);
    	}
    	
    	
    	if (temp == "# End marker list with blank line.") {
    		getline(myfile,temp);
    		while(temp != "") {
    			a.addMarker(temp);
    			getline(myfile,temp);
    		}
    	}
    	
    	
    	if (temp == "# Example: 2 0 1 (for transition labeled 0 from state 2 to state 1).") {
    		tran v;
    		getline(myfile,temp);
    		while(temp != "") {
    			v = splitAds(temp);
    			a.addTrans(v);
    			getline(myfile,temp);
    		}
    	}
    	
    }
    myfile.close();
    // fclose(myfile);
}


/*
void readExtra(vector<string>& v_mie, vector<string>& v_re, 
               vector<vector<string>>& alphabet) {
	string temp;             // Store the content of every line.
	
   	ifstream myfile("extra_event.txt");

    if (!myfile.is_open()) { 
        cerr << "Couldn't open the extra file!" << endl;  
    }
    
    // Store the MIEs.
    getline(myfile, temp);
    splitString(temp, v_mie, ",");
    // Store the REs.
    getline(myfile, temp);
    splitString(temp, v_re, ",");
	// Store the event alphabets for different modes.
    getline(myfile, temp);
    while (temp != "") {
    	vector<string> temp_vec;
    	splitString(temp, temp_vec, ",");
    	alphabet.push_back(temp_vec);
    	getline(myfile, temp);
    }
    
}
*/
