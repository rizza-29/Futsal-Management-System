#pragma once
#include"hashtable.h"
#include<sstream>
#include<string>
string getNextDate(string& current_date) {
	istringstream date_stream(current_date);
	char delimiter;
	int day, month, year;
	date_stream >> day >> delimiter >> month >> delimiter >> year;
	const int daysInMonth[] = { 0, 31, 28 + ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (day < 1 || day > daysInMonth[month]) {
		return "";
	}
	day++;
	if (day > daysInMonth[month]) {
		day = 1;
		month++;

		if (month > 12) {
			month = 1;
			year++;
		}
	}
	return to_string(day) + '/' + to_string(month) + '/' + to_string(year % 100);
}
class Court;
class court_node{
	string date;
	hashtable h;
public:
	court_node* next;
	court_node(string d) {
		date = d;
		next = NULL;
	}
	string get_date() {
		return date;
	}
	friend class Court;
};
class Court {
	string name;
	string location;
	court_node* front;
	court_node* rear;
	string date;
public:
	Court() {
		date = "2/12/23";
		string d;
		front = new court_node(date);
		d = getNextDate(date);
		front->next = new court_node(d);
		d = getNextDate(d);
		front->next->next = new court_node(d);
		d = getNextDate(d);
		rear=front->next->next->next = new court_node(d);
	}
	void enqueue(string d) {
		if (front == NULL) {
			front = rear = new court_node(d);
		}
		else {
			rear->next = new court_node(d);
			rear = rear->next;
		}
	}
	void dequeue() {
		if (front == NULL) {
			return;
		}
		else {
			court_node* temp = front;
			front = front->next;
			temp->next = NULL;
			delete temp;
		}
	}
	string get_name() {
		return name;
	}
	string get_location() {
		return location;
	}
	void set_name(string n) {
		name = n;
	}
	void set_location(string l) {
		location = l;
	}
	void book_court() {
		court_node* temp = front;
		int i = 1;
		while (temp != NULL) {
			cout << i << "-" << temp->get_date() << endl;
			temp = temp->next;
			i++;
		}
		int opt;
		cout << "Which date do you want to book the court?Enter option number:";
		cin >> opt;
		temp = front;
		i = 1;
		while (i < opt && temp->next!= NULL) {
			temp = temp->next;
		}
		temp->h.check_and_display();
		cout << endl << "Which slot would you like to book:";
		cin >> opt;
		temp->h.insert(opt);
	}
	void delete_booking_user() {
		court_node* temp = front;
		int i = 1;
		while (temp != NULL) {
			cout << i << "-" << temp->get_date() << endl;
			temp = temp->next;
			i++;
		}
		int opt;
		cout << "Which date did you book the court?Enter option number:";
		cin >> opt;
		temp = front;
		i = 1;
		while (i < opt && temp->next!= NULL) {
			temp = temp->next;
		}
		cout << endl << "Which slot did you book(Enter start time):";
		cin >> opt;
		string team1, team2;
		cout << "Enter name of 1st team:";
		cin >> team1;
		cout << "Enter name of 2nd team:";
		cin >> team2;
		temp->h.delete_slot(opt, team1, team2);
	}
	void display_bookings() {
		court_node* temp = front;
		int i;
		while (temp != NULL) {
			cout << "Date:" << temp->date << endl;
			temp->h.display();
			temp = temp->next;
		}
	}
	void delete_booking_owner() {
		court_node* temp = front;
		int i = 1;
		while (temp != NULL) {
			cout << i << "-" << temp->get_date() << endl;
			temp = temp->next;
			i++;
		}
		int opt;
		cout << "Select Date. Enter option number:";
		cin >> opt;
		temp = front;
		i = 1;
		while (i < opt && temp->next!= NULL) {
			temp = temp->next;
		}
		cout << endl << "Slot(Enter start time):";
		cin >> opt;
		temp->h.delete_slot(opt, temp->h.get_team1(opt),temp->h.get_team2(opt));
	}
};