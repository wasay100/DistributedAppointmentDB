#include "API.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    API api;
    int choice;
    do {
        cout << "   GOVERNMENT APPOINTMENT SYSTEM - MENU" << endl;
        cout << "1. Book New Appointment" << endl;
        cout << "2. Search by Date Range" << endl;
        cout << "3. Search by CNIC" << endl;
        cout << "4. Search by Confirmation Code" << endl;
        cout << "5. View All Appointments" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (choice == 1) {
            string name, cnic, phone, city, office, service, date, time;
            cin.ignore();
            cout << endl << "Enter Name: ";
            getline(cin, name);
            cout << "Enter CNIC (xxxxx-xxxxxxx-x): ";
            getline(cin, cnic);
            cout << "Enter Phone: ";
            getline(cin, phone);
            cout << "Enter City (Karachi/Lahore/Islamabad): ";
            getline(cin, city);
            cout << "Enter Office: ";
            getline(cin, office);
            cout << "Enter Service (New CNIC/CNIC Renewal/New Passport/Passport Renewal): ";
            getline(cin, service);
            cout << "Enter Date (YYYY-MM-DD): ";
            getline(cin, date);
            cout << "Enter Time (HH:MM): ";
            getline(cin, time);
            api.bookAppointment(name, cnic, phone, city, office, service, date, time);
        } else if (choice == 2) {
            string startDate, endDate;
            cin.ignore();
            cout << endl << "Enter Start Date (YYYY-MM-DD): ";
            getline(cin, startDate);
            cout << "Enter End Date (YYYY-MM-DD): ";
            getline(cin, endDate);
            api.searchByDateRange(startDate, endDate);
        } else if (choice == 3) {
            string cnic;
            cin.ignore();
            cout << endl << "Enter CNIC: ";
            getline(cin, cnic);
            api.searchByCNIC(cnic);
        } else if (choice == 4) {
            string code;
            cin.ignore();
            cout << endl << "Enter Confirmation Code: ";
            getline(cin, code);
            api.searchByConfirmation(code);
        } else if (choice == 5) {
            api.viewAllAppointments();
        } else if (choice == 6) {
            cout << endl << "Thank you for using Government Appointment System!" << endl;
        } else {
            cout << endl << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);
    return 0;
}
