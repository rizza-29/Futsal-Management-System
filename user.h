#pragma once
#include<iostream>
using namespace std;
class User{
    string name;
    string user_name;
    string password;
    int age;
    string contact_num;
public:
    void update_profile() {
        int opt;
        cout << "Which Info would you like to update:" << endl;
        cout << "1-Name" << endl;
        cout << "2-Username" << endl;
        cout << "3-Password" << endl;
        cout << "4-Age" << endl;
        cout << "5-Contact Number" << endl;
        cout << "Enter option Number to proceed:";
        cin >> opt;
        int a;
        string t;
        if (opt == 1) {
            cout << "Enter new name:";
            cin >> t;
            name = t;
        }
        else if (opt == 2) {
            cout << "Enter new Username:";
            cin >> t;
            user_name = t;
        }
        else if (opt == 3) {
            cout << "Enter old password:";
            cin >> t;
            if (t == password) {
                cout << "Enter new password:";
                cin >> t;
                password = t;
            }
        }
        else if (opt == 4) {
            cout << "Enter new age:";
            cin >> a;
            age = a;
        }
        else if (opt == 5) {
            cout << "Enter new Contact Number:";
            cin >> t;
            contact_num = t;
        }
    }
    void display_profile() {
        cout << "Profile Information:";
        cout << "Name:" << name << endl;
        cout << "Username:" << user_name << endl;
        cout << "Age:" << age << endl;
        cout << "Contact Number:" << contact_num << endl;
    }
    void admin_display_profile() {
        cout << "Profile Information:" << endl;
        cout << "Name:" << name << endl;
        cout << "Username:" << user_name << endl;
        cout << "Password:" << password << endl;
        cout << "Age:" << age << endl;
        cout << "Contact Number:" << contact_num << endl;
    }

    void set_name(string s) {
        name = s;
    }
    void set_UserName(string s) {
        user_name = s;
    }
    void set_Password(string s) {
        password = s;
    }
    void set_age(int a) {
        age = a;
    }
    void set_ContactNum(string s) {
        contact_num = s;
    }
    string get_name() {
        return name;
    }
    string get_UserName() {
        return user_name;
    }
    string get_password() {
        return password;
    }
    string get_contact_num() {
        return contact_num;
    }
    int get_age() {
        return age;
    }
};