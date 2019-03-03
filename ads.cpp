#include "ads.h"

ads::ads() {}
ads::ads(string _name): name{_name}{}

string ads::getName(){return name;}
int ads::getSize(){return size;}
vector<string> ads::getStates(){return states;}
vector<string> ads::getMarker(){return marker;}
vector<tran> ads::getTrans(){return trans;}
map<string, set<string>> ads::getSrc_evt(){return src_evt;}
map<string, set<string>> ads::getTgt_evt(){return tgt_evt;}
map<string, set<string>> ads::getEvt_src(){return evt_src;}
map<string, set<string>> ads::getEvt_tgt(){return evt_tgt;}
map<string, set<string>> ads::getSrc_tgt(){return src_tgt;}
map<string, set<string>> ads::getTgt_src(){return tgt_src;}

void ads::setName(string _name){name = _name;}
void ads::setSize(int _size){size = _size;}
void ads::setStates() {
	for (int i = 0; i < size; i++) {
		states.push_back(to_string(i));
	}
}
void ads::addMarker(string _marker){marker.push_back(_marker);}
void ads::addTrans(tran _trans){trans.push_back(_trans);}

void ads::setMap() {
	for (auto i : this->getTrans()) {
		string src = i.getSrc();
		string evt = i.getEvt();
		string tgt = i.getTgt();
		// use map::find(key) to find key
		map<string, set<string>>::iterator se = src_evt.find(src);
		map<string, set<string>>::iterator te = tgt_evt.find(tgt);
		map<string, set<string>>::iterator es = evt_src.find(evt);
		map<string, set<string>>::iterator et = evt_tgt.find(evt);
		map<string, set<string>>::iterator st = src_tgt.find(src);
		map<string, set<string>>::iterator ts = tgt_src.find(tgt);
		
		// source_event map
		if (se != src_evt.end()) {
			src_evt[src].insert(evt);
		}
		else {
			set<string> se_temp;
			se_temp.insert(evt);
			src_evt.insert(pair<string, set<string>>(src, se_temp));
		}
		
		// target_event map
		if (te != tgt_evt.end()) {
			tgt_evt[tgt].insert(evt);
		}
		else {
			set<string> te_temp;
			te_temp.insert(evt);
			tgt_evt.insert(pair<string, set<string>>(tgt, te_temp));
		}
		
		// event_src map
		if (es != evt_src.end()) {
			evt_src[evt].insert(src);
		}
		else {
			set<string> es_temp;
			es_temp.insert(src);
			evt_src.insert(pair<string, set<string>>(evt, es_temp));
		}
		
		// event_tgt map
		if (et != evt_tgt.end()) {
			evt_tgt[evt].insert(tgt);
		}
		else {
			set<string> et_temp;
			et_temp.insert(tgt);
			evt_tgt.insert(pair<string, set<string>>(evt, et_temp));
		}
		
		// source_target map
		if (st != src_tgt.end()) {
			src_tgt[src].insert(tgt);
		}
		else {
			set<string> st_temp;
			st_temp.insert(tgt);
			src_tgt.insert(pair<string, set<string>>(src, st_temp));
		}
		
		// target_source map
		if (ts != tgt_src.end()) {
			tgt_src[tgt].insert(src);
		}
		else {
			set<string> ts_temp;
			ts_temp.insert(src);
			tgt_src.insert(pair<string, set<string>>(tgt, ts_temp));
		}
	}
}

void ads::printAds() {
	cout << "The name of ADS is: " << this->getName() << endl;
	cout << "The size of ADS is: " << this->getSize() << endl;
	cout << "The states of ADS are: " << endl;
	for (auto i : this->getStates()) {
		cout << i << " ";
	}
	cout << endl;;
	cout << "The marker states are: " << endl;
	for (auto i : this->getMarker()) {
		cout << i << endl;
	}
	cout << "The transitions are: " << endl;
	for (auto i : this->getTrans()) {
		i.printTran();
	}
}

void ads::printSrc_evt() {
	cout << "The source-state-event map is: " << endl;
	for (auto i : src_evt) {
		cout << i.first << " : ";
		for (auto j : i.second) {
			cout << j << " ";
		}
		cout << endl;
	}
}
void ads::printTgt_evt() {
	cout << "The target-state-event map is: " << endl;
	for (auto i : tgt_evt) {
		cout << i.first << " : ";
		for (auto j : i.second) {
			cout << j << " ";
		}
		cout << endl;
	}
}
void ads::printEvt_src() {
	cout << "The event-source-state map is: " << endl;
	for (auto i : evt_src) {
		cout << i.first << " : ";
		for (auto j : i.second) {
			cout << j << " ";
		}
		cout << endl;
	}
}
void ads::printEvt_tgt() {
	cout << "The event-target-state map is: " << endl;
	for (auto i : evt_tgt) {
		cout << i.first << " : ";
		for (auto j : i.second) {
			cout << j << " ";
		}
		cout << endl;
	}
}
void ads::printSrc_tgt() {
	cout << "The source-target-state map is: " << endl;
	for (auto i : src_tgt) {
		cout << i.first << " : ";
		for (auto j : i.second) {
			cout << j << " ";
		}
		cout << endl;
	}
}
void ads::printTgt_src() {
	cout << "The target-source-state map is: " << endl;
	for (auto i : tgt_src) {
		cout << i.first << " : ";
		for (auto j : i.second) {
			cout << j << " ";
		}
		cout << endl;
	}
}
