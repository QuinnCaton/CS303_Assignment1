#pragma once
#include <string>
#include <sstream>
#include <list>
#include <iterator>
using namespace std;

struct date {
	int month, day, year;
	// override the == operator
	friend bool operator==(date a, date b) {
		if (a.month = b.month && a.day == b.day && a.year == b.year) {
			return true;
		}
		else {
			return false;
		}
	}
	friend bool operator<(date a, date b) {
		if (a.year < b.year) {
			return true;
		}
		if (a.year > b.year) {
			return false;
		}
		if (a.year == b.year) {
			if (a.month < b.month) {
				return true;
			}
			if (a.month > b.month) {
				return false;
			}
			if (a.month == b.month) {
				if (a.day <= b.day) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
	friend bool operator>(date a, date b) {
		if (a.year > b.year) {
			return true;
		}
		if (a.year < b.year) {
			return false;
		}
		if (a.year == b.year) {
			if (a.month > b.month) {
				return true;
			}
			if (a.month < b.month) {
				return false;
			}
			if (a.month == b.month) {
				if (a.day >= b.day) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
};

class Assignment
{
private:
	string name, subject;
	date dateDue, dateAssigned;
	bool isComplete;
public:
	Assignment();
	Assignment(string, string, date, date);

	string getName() { return name; }
	void setName(string);

	string getSubject() { return subject; }
	void setSubject(string);

	date getDateDue() { return dateDue; }
	void setDateDue(date);

	date getDateAssigned() { return dateAssigned; }
	void setDateAssigned(date);

	bool getStatus() { return isComplete; }
	void setStatus(bool);

	friend bool operator==(Assignment a, Assignment b) {
		if (a.getDateAssigned() == b.getDateAssigned()) {
			return true;
		}
	}
	friend bool operator>(Assignment a, Assignment b) {
		if (a.getDateAssigned() > b.getDateAssigned()) {
			return true;
		}
	}
	friend bool operator<(Assignment a, Assignment b) {
		if (a.getDateAssigned() < b.getDateAssigned()) {
			return true;
		}
	}
};

void addAssignment(list<Assignment>&);
void printAssignments(list<Assignment>&);
void removeAssignment(list<Assignment>&);
void earliestDue(list<Assignment>&);