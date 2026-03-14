#include <iostream>
#include <vector>
using namespace std;

class Vehicle {
public:
    int id;
    string name;
    int pricePerDay;
    bool available;

    Vehicle(int i, string n, int p) {
        id = i;
        name = n;
        pricePerDay = p;
        available = true;
    }
};

class Rental {
public:
    int vehicleId;
    string vehicleName;
    int days;
    int bill;

    Rental(int id, string name, int d, int b) {
        vehicleId = id;
        vehicleName = name;
        days = d;
        bill = b;
    }
};

vector<Vehicle> vehicles;
vector<Rental> history;

void showVehicles() {
    cout << "\nAvailable Vehicles\n";
    for (auto &v : vehicles) {
        cout << "ID: " << v.id
             << " Name: " << v.name
             << " Price/Day: " << v.pricePerDay
             << " Available: " << (v.available ? "Yes" : "No")
             << endl;
    }
}

void rentVehicle() {
    int id, days;

    cout << "\nEnter Vehicle ID: ";
    cin >> id;

    for (auto &v : vehicles) {
        if (v.id == id && v.available) {
            cout << "Enter number of days: ";
            cin >> days;

            int bill = days * v.pricePerDay;

            v.available = false;

            history.push_back(Rental(v.id, v.name, days, bill));

            cout << "Vehicle Booked Successfully\n";
            cout << "Total Bill: " << bill << endl;

            return;
        }
    }

    cout << "Vehicle not available\n";
}

void returnVehicle() {
    int id;

    cout << "\nEnter Vehicle ID to return: ";
    cin >> id;

    for (auto &v : vehicles) {
        if (v.id == id) {
            v.available = true;
            cout << "Vehicle Returned Successfully\n";
            return;
        }
    }

    cout << "Vehicle not found\n";
}

void showHistory() {
    cout << "\nRental History\n";

    for (auto &h : history) {
        cout << "Vehicle ID: " << h.vehicleId
             << " Name: " << h.vehicleName
             << " Days: " << h.days
             << " Bill: " << h.bill
             << endl;
    }
}

int main() {

    vehicles.push_back(Vehicle(1, "Car", 2000));
    vehicles.push_back(Vehicle(2, "Bike", 500));
    vehicles.push_back(Vehicle(3, "Scooter", 300));

    int choice;

    do {

        cout << "\n===== Vehicle Rental System =====\n";
        cout << "1. Show Vehicles\n";
        cout << "2. Rent Vehicle\n";
        cout << "3. Return Vehicle\n";
        cout << "4. Rental History\n";
        cout << "5. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            showVehicles();
            break;

        case 2:
            rentVehicle();
            break;

        case 3:
            returnVehicle();
            break;

        case 4:
            showHistory();
            break;

        case 5:
            cout << "Thank You\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while (choice != 5);

    return 0;
}