#pragma once
#include<iostream>
#include"court.h"
using namespace std;
class Owner{
    string name;
    string username;
    string password;
    string contact_num;
    Court c;
public:
    void admin_display_profile() {
        cout << "Profile Information:" << endl;
        cout << "Name: " << name << endl;
        cout << "Username: " << username << endl;
        cout << "Password: " << password << endl;
        cout << "Contact Number: " << contact_num << endl;
        cout << "Court Name: " << c.get_name() << endl;
        cout << "Court Location: " << c.get_location() << endl;
    }
    void update_CourtDetails() {
        int opt;
        cout << "What do you want to update from the following: " << endl;
        cout << "1-Name" << endl;
        cout << "2-Location" << endl;
        cout << "Enter option number to proceed: ";
        cin >> opt;
        if (opt == 1) {
            string s;
            cout << "ENTER NEW NAME FOR COURT:  " << endl;
            cin >> s;
            c.set_name(s);
        }
        else if (opt == 2) {
            string s;
            cout << "ENTER NEW LOCATION OF COURT:  " << endl;
            cin >> s;
            c.set_location(s);
        }
    }
    void update_profile() {
        int opt;
        cout << "Which Info would you like to update:" << endl;
        cout << "1-Name" << endl;
        cout << "2-Username" << endl;
        cout << "3-Password" << endl;
        cout << "4-Contact Number" << endl;
        cout << "Enter option Number to proceed: ";
        cin >> opt;
        string t;
        if (opt == 1) {
            cout << "Enter new name: ";
            cin >> t;
            name = t;
        }
        else if (opt == 2) {
            cout << "Enter new Username: ";
            cin >> t;
            username = t;
        }
        else if (opt == 3) {
            cout << "Enter old password: ";
            cin >> t;
            if (t == password) {
                cout << "Enter new password: ";
                cin >> t;
                password = t;
            }
        }
        else if (opt == 4) {
            cout << "Enter new Contact Number: ";
            cin >> t;
            contact_num = t;
        }
    }
    void display_profile() {
        cout << "Profile Information:" << endl;
        cout << "Name: " << name << endl;
        cout << "Username: " << username << endl;
        cout << "Contact Number: " << contact_num << endl;
    }
    void booking() {
        c.book_court();
    }
    void delete_booking() {
        c.delete_booking_user();
    }
    void display_b() {
        c.display_bookings();
    }
    void set_name(string s) {
        name = s;
    }
    void set_Password(string s) {
        password = s;
    }
    void set_ContactNum(string s) {
        contact_num = s;
    }
    void set_username(string s) {
        username = s;
    }
    string get_name() {
        return name;
    }
    string get_username() {
        return username;
    }
    string get_password() {
        return password;
    }
    string get_ContactNum() {
        return contact_num;
    }
    void set_court(string name, string loc) {
        c.set_name(name);
        c.set_location(loc);
    }
    string get_CourtLoc() {
        return c.get_location();
    }
    string get_CourtName() {
        return c.get_name();
    }
};
