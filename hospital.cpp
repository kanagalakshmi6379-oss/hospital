#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Patient {
    int id;
    string name;
    int age;
    string disease;
};

vector<Patient> patients;

void addPatient() {
    Patient p;

    cout << "\nEnter Patient ID: ";
    cin >> p.id;

    for (const auto& patient : patients) {
        if (patient.id == p.id) {
            cout << "Patient ID already exists!\n";
            return;
        }
    }

    cout << "Enter Patient Name: ";
    getline(cin >> ws, p.name);

    cout << "Enter Patient Age: ";
    cin >> p.age;

    cout << "Enter Disease: ";
    getline(cin >> ws, p.disease);

    if (p.age < 0 || p.age > 130) {
        cout << "Invalid age!\n";
        return;
    }

    patients.push_back(p);
    cout << "Patient added successfully!\n";
}

void displayPatients() {
    if (patients.empty()) {
        cout << "\nNo patient records found.\n";
        return;
    }

    cout << "\n--- Patient Records ---\n";

    for (const auto& p : patients) {
        cout << "\nPatient ID: " << p.id
             << "\nName: " << p.name
             << "\nAge: " << p.age
             << "\nDisease: " << p.disease << "\n";
    }
}

void searchPatient() {
    int id;
    cout << "\nEnter Patient ID to search: ";
    cin >> id;

    for (const auto& p : patients) {
        if (p.id == id) {
            cout << "\nPatient Found!\n"
                 << "ID: " << p.id
                 << "\nName: " << p.name
                 << "\nAge: " << p.age
                 << "\nDisease: " << p.disease << "\n";
            return;
        }
    }

    cout << "Patient not found.\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== HOSPITAL MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Patient\n";
        cout << "2. Display All Patients\n";
        cout << "3. Search Patient\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            return 1;
        }

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                displayPatients();
                break;
            case 3:
                searchPatient();
                break;
            case 4:
                cout << "Exiting Hospital Management System.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
