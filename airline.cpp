#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Flight {
    string flightNumber;
    string origin;
    string destination;
    int capacity;
    int seatsBooked;
};

vector<Flight> flights;

void addFlight() {
    Flight newFlight;
    cout << "Enter Flight Number: ";
    cin >> newFlight.flightNumber;
    cout << "Enter Origin: ";
    cin >> newFlight.origin;
    cout << "Enter Destination: ";
    cin >> newFlight.destination;
    cout << "Enter Capacity: ";
    cin >> newFlight.capacity;
    newFlight.seatsBooked = 0;
    
    flights.push_back(newFlight);
    
    cout << "Airline Registration Successful!" << endl;
}

void viewFlights() {
    if (flights.empty()) {
        cout << "No flights available." << endl;
        return;
    }
    
    cout << "Available Flights: " << endl;
    for (const Flight& flight : flights) {
        cout << "Flight Number: " << flight.flightNumber << endl;
        cout << "Origin: " << flight.origin << endl;
        cout << "Destination: " << flight.destination << endl;
        cout << "Available Seats: " << flight.capacity - flight.seatsBooked << endl;
        cout << "-------------------------" << endl;
    }
}

void bookFlight() {
    if (flights.empty()) {
        cout << "No flights available." << endl;
        return;
    }
    
    string flightNumber;
    cout << "Enter Flight Number: ";
    cin >> flightNumber;
    
    for (Flight& flight : flights) {
        if (flight.flightNumber == flightNumber) {
            if (flight.seatsBooked < flight.capacity) {
                flight.seatsBooked++;
                cout << "Flight booked successfully!" << endl;
            } else {
                cout << "No available seats on this flight." << endl;
            }
            return;
        }
    }
    
    cout << "Flight not found." << endl;
}

void cancelReservation() {
    if (flights.empty()) {
        cout << "No flights available." << endl;
        return;
    }
    
    string flightNumber;
    cout << "Enter Flight Number: ";
    cin >> flightNumber;
    
    for (Flight& flight : flights) {
        if (flight.flightNumber == flightNumber) {
            if (flight.seatsBooked > 0) {
                flight.seatsBooked--;
                cout << "Reservation canceled successfully!" << endl;
            } else {
                cout << "No reservations to cancel for this flight." << endl;
            }
            return;
        }
    }
    
    cout << "Flight not found." << endl;
}

int main() {
    int choice;
    
    do {
        cout << "-------------------------" << endl;
        cout << "Airline Reservation System" << endl;
        cout << "-------------------------" << endl;
        cout << "1. Add Flight" << endl;
        cout << "2. View Flights" << endl;
        cout << "3. Book Flight" << endl;
        cout << "4. Cancel Reservation" << endl;
        cout << "5. Exit" << endl;
        cout << "-------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                addFlight();
                break;
            case 2:
                viewFlights();
                break;
            case 3:
                bookFlight();
                break;
            case 4:
                cancelReservation();
                break;
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
        
        cout << endl;
    } while (choice != 5);
    
    return 0;
}