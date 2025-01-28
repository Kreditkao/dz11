#include <iostream>
#include <set>
#include <string>
#include "TicketRequest.h"
using namespace std;

int main() {
    set<TicketRequest> requests;
    int choice;

    while (true) {
        cout << "Select an action:\n"
            << "1 - Add ticket request\n"
            << "2 - Remove ticket request\n"
            << "3 - Display requests by destination\n"
            << "4 - Count requests by date range and destination\n"
            << "5 - Display all requests\n"
            << "6 - Exit\n";
        cin >> choice;

        if (choice == 1) {
            string destination, passenger, date;
            cout << "Enter destination: ";
            cin >> destination;
            cout << "Enter passenger: ";
            cin >> passenger;
            cout << "Enter departure date (yyyy-mm-dd): ";
            cin >> date;
            requests.emplace(destination, passenger, date);

        }
        else if (choice == 2) {
            int id;
            cout << "Enter request ID to remove: ";
            cin >> id;
            for (auto it = requests.begin(); it != requests.end(); ++it) {
                if (it->id == id) {
                    requests.erase(it);
                    cout << "Request removed successfully.\n";
                    break;
                }
            }

        }
        else if (choice == 3) {
            string destination;
            cout << "Enter destination: ";
            cin >> destination;
            for (const auto& req : requests) {
                if (req.destination == destination) {
                    req.display();
                }
            }

        }
        else if (choice == 4) {
            string destination, startDate, endDate;
            cout << "Enter destination: ";
            cin >> destination;
            cout << "Enter start date (yyyy-mm-dd): ";
            cin >> startDate;
            cout << "Enter end date (yyyy-mm-dd): ";
            cin >> endDate;
            int count = 0;
            for (const auto& req : requests) {
                if (req.destination == destination && req.departureDate >= startDate && req.departureDate <= endDate) {
                    count++;
                }
            }
            cout << "Number of requests in range: " << count << endl;

        }
        else if (choice == 5) {
            for (const auto& req : requests) {
                req.display();
            }

        }
        else if (choice == 6) {
            break;

        }
        else {
            cout << "Invalid choice. Please select a valid option.\n";
        }
    }

    return 0;
}
