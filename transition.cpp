#include "transition.h"

// Constructor
tran::tran() {}
tran::tran(string _source, string _event, string _target): 
		   source{_source}, event{_event}, target{_target}{}

string tran::getSrc(){return source;}
string tran::getEvt(){return event;}
string tran::getTgt(){return target;}
void tran::setSrc(string _source){source = _source;}
void tran::setEvt(string _event){event = _event;}
void tran::setTgt(string _target){target = _target;}

void tran::printTran() {
	cout << source << " " << event << " " << target << endl;
}
