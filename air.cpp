#include <iostream>
#include <string>

using namespace std;

struct Passenger {
    string name;
    int age;
    string destination;
};

void registerPassenger() {
    Passenger passenger;

    cout << "Enter passenger name: ";
    getline(cin, passenger.name);

    cout << "Enter passenger age: ";
    cin >> passenger.age;
    cin.ignore(); // Ignore the newline character left in the buffer

    cout << "Enter destination: ";
    getline(cin, passenger.destination);

    // TODO: Add code to store passenger information in a data structure or database

    cout << "Passenger registration successful!" << endl;
}

int main() {
    registerPassenger();

    return 0;
}
