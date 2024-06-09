#pragma once
#include<iostream>
#include"user.h"
#include"court_admin.h"
#include"linkedlist.h"
#pragma once
using namespace std;
class admin{
string name;
string username;
string id;
string password;
public:
void update_profile() {
    int opt;
    cout << "Which Info would you like to update:" << endl;
    cout << "1-Name" << endl;
    cout << "2-Username" << endl;
    cout << "3-Password" << endl;
    cout << "4-ID" << endl;
    cout << "Enter option Number to proceed:";
    cin >> opt;
    string t;
    if (opt == 1) {
        cout << "Enter new name:";
        cin >> t;
        name = t;
    }
    else if (opt == 2) {
        cout << "Enter new Username:";
        cin >> t;
        username = t;
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
        cout << "Enter new ID:";
        cin >> t;
        id = t;
    }
}
void display_profile() {
    cout << "Profile Information:" << endl;
    cout << "Name:" << name << endl;
    cout << "Username:" << username << endl;
    cout << "Password:" << password << endl;
    cout << "ID:" << id << endl;
}
void user_detail(LinkedList<User> u) {
    Nodelist<User>* temp = u.front();
    while (temp != NULL) {
        temp->key.admin_display_profile();
        cout << endl;
        temp = temp->next;
    }
}
void court_detail(LinkedList<Owner> o) {
    Nodelist<Owner>* temp = o.front();
    while (temp != NULL) {
        temp->key.admin_display_profile();
        cout << endl;
        temp = temp->next;
    }
}
string get_UserName() {
    return username;
}
void set_UserName(string s) {
    username = s;
}
void set_name(string s);
void set_ID(string s);
void set_Password(string s);

string get_name();
string get_ID();
string get_password();

};
void admin::set_name(string s){
    name=s;
}
void admin::set_ID(string s){
    id=s;
}
void admin::set_Password(string s){
    password=s;
}
string admin::get_name(){
    return name;
}
string admin::get_ID(){
    return id;
}   
string admin::get_password(){
    return password;
}
