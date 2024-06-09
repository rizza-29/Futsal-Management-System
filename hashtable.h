#pragma once
#include<iostream>
#include<string>
using namespace std;
class hashtable {
    int size;
    string team1[24];
    string team2[24];
public:
    hashtable() {
        size = 24;
        for (int i = 0; i < size; i++) {
            team1[i] = "aaa";
            team2[i] = "aaa";
        }
    }
    int check_slot(int k) {
        if (k >= 0 && k < size && team1[k] == "aaa" && team2[k] == "aaa") {
            return 0;
        }
        return 1;
    }
    void insert(int key) {
        int opt = 1;
        while (opt == 1) {
            cout << "Enter available slot (0-23): ";
            cin >> key;
            opt = check_slot(key);
            if (opt == 1) {
                cout << "INVALID! Slot already booked. Enter again." << endl;
            }
        }
        cout << "Enter name of 1st team: ";
        cin >> team1[key];
        cout << "Enter name of 2nd team: ";
        cin >> team2[key];
        cout << "The match between " << team1[key] << " and " << team2[key] << " has been fixed" << endl;
    }
    void delete_slot(int key, string team1Name, string team2Name) {
        if (key >= 0 && key < size && team1[key] == team1Name && team2[key] == team2Name) {
            team1[key] = "aaa";
            team2[key] = "aaa";
            cout << "Booking Cancelled!" << endl;
        }
        else {
            cout << "Incorrect Name or Slot." << endl;
        }
    }
    void check_and_display() {
        cout << "The available slots are (24-Hour):" << endl;
        for (int i = 0; i < size; i++) {
            if (team1[i] == "aaa" && team2[i] == "aaa") {
                cout << i << "-" << i + 1 << ":00 to " << i + 1 << ":00" << endl;
            }
            else {
                cout << i << "-TAKEN" << endl;
            }
        }
    }
    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ":00 to " << i + 1 << ":00";
            if (team1[i] == "aaa" && team2[i] == "aaa") {
                cout << "(No Booking)";
            }
            else {
                if (team1[i] != "aaa") {
                    cout << "(" << team1[i] << ")";
                }
                if (team2[i] != "aaa") {
                    cout << "(" << team2[i] << ")";
                }
            }
            cout << endl;
        }
    }
    string get_team1(int k) {
        return team1[k];
    }
    string get_team2(int k) {
        return team2[k];
    }
};

