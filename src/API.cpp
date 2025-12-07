#include "API.h"
#include <iostream>
#include <iomanip>

using namespace std;

API::API() : btree(3), appointmentCounter(100) {
    loadInitialData();
}

string API::generateConfirmationCode(const string& city) {
    string cityCode;
    if (city == "Karachi") cityCode = "KHI";
    else if (city == "Lahore") cityCode = "LHR";
    else if (city == "Islamabad") cityCode = "ISB";
    else cityCode = "PKT";    
    appointmentCounter++;
    return "APT-" + cityCode + "-" + to_string(appointmentCounter);
}

void API::bookAppointment(const string& name, const string& cnic, const string& phone, 
                         const string& city, const string& office, const string& service, 
                         const string& date, const string& time) {
    string confirmationCode = generateConfirmationCode(city);
    Appointment apt(confirmationCode, name, cnic, phone, city, office, service, date, time);
    btree.insert(apt);
    hashTable.insert(cnic, apt);
    hashTable.insert(confirmationCode, apt);
    cout << endl << "=== Appointment Booked Successfully ===" << endl;
    cout << "Confirmation Code: " << confirmationCode << endl;
    cout << "Name: " << name << endl;
    cout << "CNIC: " << cnic << endl;
    cout << "City: " << city << endl;
    cout << "Office: " << office << endl;
    cout << "Service: " << service << endl;
    cout << "Date: " << date << endl;
    cout << "Time: " << time << endl;
}

void API::searchByCNIC(const string& cnic) {
    Appointment* apt = hashTable.search(cnic);
    if (apt) {
        cout << endl << "=== Appointment Found ===" << endl;
        cout << "Confirmation Code: " << apt->confirmationCode << endl;
        cout << "Name: " << apt->name << endl;
        cout << "CNIC: " << apt->cnic << endl;
        cout << "Phone: " << apt->phone << endl;
        cout << "City: " << apt->city << endl;
        cout << "Office: " << apt->office << endl;
        cout << "Service: " << apt->service << endl;
        cout << "Date: " << apt->date << endl;
        cout << "Time: " << apt->time << endl;
    } else {
        cout << endl << "No appointment found for CNIC: " << cnic << endl;
    }
}

void API::searchByConfirmation(const string& code) {
    Appointment* apt = hashTable.search(code);
        if (apt) {
        cout << endl << "=== Appointment Found ===" << endl;
        cout << "Confirmation Code: " << apt->confirmationCode << endl;
        cout << "Name: " << apt->name << endl;
        cout << "CNIC: " << apt->cnic << endl;
        cout << "Phone: " << apt->phone << endl;
        cout << "City: " << apt->city << endl;
        cout << "Office: " << apt->office << endl;
        cout << "Service: " << apt->service << endl;
        cout << "Date: " << apt->date << endl;
        cout << "Time: " << apt->time << endl;
    } else {
        cout << endl << "No appointment found for confirmation code: " << code << endl;
    }
}

void API::searchByDateRange(const string& startDate, const string& endDate) {
    vector<Appointment> results = btree.searchByDateRange(startDate, endDate);
    cout << endl << "=== Appointments from " << startDate << " to " << endDate << " ===" << endl;
    if (results.empty()) {
        cout << "No appointments found in this date range." << endl;
    } else {
        for (size_t i = 0; i < results.size(); i++) {
            cout << i + 1 << ". " << results[i].date << " " << results[i].time 
                 << " - " << results[i].name << " (" << results[i].city << ")" << endl;
        }
    }
}

void API::viewAllAppointments() {
    vector<Appointment> all = btree.getAll();   
    cout << endl << "=== All Appointments ===" << endl;
    if (all.empty()) {
        cout << "No appointments found." << endl;
    } else {
        for (size_t i = 0; i < all.size(); i++) {
            cout << endl << i + 1 << ". " << all[i].confirmationCode << endl;
            cout << "   Name: " << all[i].name << endl;
            cout << "   CNIC: " << all[i].cnic << endl;
            cout << "   City: " << all[i].city << endl;
            cout << "   Office: " << all[i].office << endl;
            cout << "   Service: " << all[i].service << endl;
            cout << "   Date: " << all[i].date << endl;
            cout << "   Time: " << all[i].time << endl;
        }
    }
}

void API::loadInitialData() {
    bookAppointment("Ali Khan", "42101-1234567-1", "0300-1234567", "Karachi", "NADRA Saddar", "New CNIC", "2025-12-10", "09:00");
    bookAppointment("Sara Ahmed", "42201-2345678-2", "0321-2345678", "Karachi", "Passport Office Clifton", "Passport Renewal", "2025-12-10", "10:30");
    bookAppointment("Hassan Ali", "35202-3456789-3", "0333-3456789", "Lahore", "NADRA Gulberg", "CNIC Renewal", "2025-12-11", "11:00");
    bookAppointment("Fatima Noor", "61101-4567890-4", "0345-4567890", "Islamabad", "NADRA G-6", "New CNIC", "2025-12-12", "14:00");
    bookAppointment("Usman Shah", "42301-5678901-5", "0312-5678901", "Karachi", "NADRA Clifton", "CNIC Renewal", "2025-12-13", "09:30");
    cout << endl << "Initial data loaded successfully!" << endl;
}
