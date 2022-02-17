#include "Assignment.h"
#include <iostream>
#include <string>
#include <list>
#include <iterator>
using namespace std;

Assignment::Assignment()
{
	date defDate;
	defDate.year = 2000;
	defDate.day = 1;
	defDate.month = 1;

	name = "NULL";
	subject = "NULL";
	dateDue = defDate;
	dateAssigned = defDate;
	isComplete = false;
}

Assignment::Assignment(string name, string subject, date dateDue, date dateAssigned)
{
	this->name = name;
	this->subject = subject;
	this->dateDue = dateDue;
	this->dateAssigned = dateAssigned;
	isComplete = false;
}

void Assignment::setName(string name)
{
	this->name = name;
}

void Assignment::setSubject(string subject)
{
	this->subject = subject;
}

void Assignment::setDateDue(date dateDue)
{
	this->dateDue = dateDue;
}

void Assignment::setDateAssigned(date dateAssigned)
{
	this->dateAssigned = dateAssigned;
}

void Assignment::setStatus(bool isComplete)
{
	this->isComplete = isComplete;
}

void addAssignment(list<Assignment>& myList)
{

	string name, subject;
	int day, month, year;
	date dateDue, dateAssigned;

	cout << "Title of new assignment: ";
	getline(cin, name);
	cout << "\nSubject: ";
	getline(cin, subject);
	cout << "\nDate Assigned (separate day/month/year by spaces): ";
	cin >> day >> month >> year;
	dateAssigned.day = day;
	dateAssigned.month = month;
	dateAssigned.year = year;
	cout << "\nDate Due (separate by spaces): ";
	cin >> day >> month >> year;
	dateDue.day = day;
	dateDue.month = month;
	dateDue.year = year;
	Assignment newAssignment(name, subject, dateDue, dateAssigned);

	myList.push_back(newAssignment);
	myList.sort();

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
}

void printAssignments(list<Assignment> &myList)
{
	int i = 1;
	for (auto f = myList.begin(); f != myList.end(); f++) {
		cout << i << ": " << f->getName() << ", Due Date " 
			 << f->getDateDue().day << "/" << f->getDateDue().month << "/"
			 << f->getDateDue().year << endl;
		i++;
	}
}

void removeAssignment(list<Assignment> &myList)
{
	int i;
	cout << "Which assignment would you like to remove:" << endl;
	printAssignments(myList);
	cin >> i;
	list<Assignment>::iterator r = myList.begin();
	advance(r, i - 1);
	myList.erase(r);
}

void earliestDue(list<Assignment>& myList)
{
	int i = 0;
	int min = 0;
	date temp = myList.front().getDateDue();
	for (auto f = myList.begin(); f != myList.end(); f++) {
		if (f->getDateDue() < temp) {
			temp = f->getDateDue();
			min = i;
		}
		i++;
	}

	list<Assignment>::iterator r = myList.begin();
	advance(r, min);
	cout << "Earliest Due Date: " << r->getName() << " in " << r->getSubject() << " due " << 
		r->getDateDue().day << "/" << r->getDateDue().month << "/"
		<< r->getDateDue().year << endl;
}
