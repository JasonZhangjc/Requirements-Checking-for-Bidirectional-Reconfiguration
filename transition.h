#ifndef TRANSITION_H
#define TRANSITION_H

#include <iostream>
#include <string>
 
using namespace std;

/* This is the class for TRANSITION */

class tran{
public:
	tran();
	tran(string _source, string _event, string _target);
	string getSrc();
	string getEvt();
	string getTgt();
	void setSrc(string _source);
	void setEvt(string _event);
	void setTgt(string _target);
	void printTran();
private:
	string source;
	string event;
	string target;
};

#endif // TRANSITION_H
