#ifndef TICKETREQUEST_H
#define TICKETREQUEST_H

#include <iostream>
#include <set>
#include <string>
using namespace std;

class TicketRequest {
private:
    static int counter;
public:
    int id;
    string destination;
    string passenger;
    string departureDate;

    TicketRequest(string dest, string pass, string date)
        : destination(dest), passenger(pass), departureDate(date) {
        id = ++counter;
    }

    bool operator<(const TicketRequest& other) const {
        if (destination != other.destination) {
            return destination < other.destination;
        }
        else {
            return departureDate < other.departureDate;
        }
    }

    void display() const {
        cout << "ID: " << id << ", Destination: " << destination
            << ", Passenger: " << passenger << ", Date: " << departureDate << endl;
    }
};

int TicketRequest::counter = 0;

#endif
