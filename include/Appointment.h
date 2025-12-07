#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>

using namespace std;

struct Appointment {
    string confirmationCode;
    string name;
    string cnic;
    string phone;
    string city;
    string office;
    string service;
    string date;
    string time;
    
    Appointment() {}
    
    Appointment(string code, string n, string c, string p, string ct, string o, string s, string d, string t)
        : confirmationCode(code), name(n), cnic(c), phone(p), city(ct), office(o), service(s), date(d), time(t) {}
};

#endif
