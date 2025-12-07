#ifndef API_H
#define API_H

#include "BTree.h"
#include "HashTable.h"
#include <string>

using namespace std;

class API {
private:
    BTree btree;
    HashTable hashTable;
    int appointmentCounter;
    string generateConfirmationCode(const string& city);
    
public:
    API();
    
    void bookAppointment(const string& name, const string& cnic, const string& phone, 
                        const string& city, const string& office, const string& service, 
                        const string& date, const string& time);
    void searchByCNIC(const string& cnic);
    void searchByConfirmation(const string& code);
    void searchByDateRange(const string& startDate, const string& endDate);
    void viewAllAppointments();
    void loadInitialData();
};

#endif
