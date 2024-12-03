#include <iostream>
#include <string>
#include <vector>

class Driver {
public:
    int driver_id;
    std::string name;
    std::string contact_number;

    Driver(int id, const std::string& name, const std::string& contact) 
        : driver_id(id), name(name), contact_number(contact) {}
};

class Vehicle {
public:
    int vehicle_id;
    std::string type;

    Vehicle(int id, const std::string& type) : vehicle_id(id), type(type) {}
};

class MaintenanceRecord {
public:
    int record_id;
    int vehicle_id;
    std::string maintenance_type;

    MaintenanceRecord(int id, int v_id, const std::string& type) 
        : record_id(id), vehicle_id(v_id), maintenance_type(type) {}
};

class Alert {
public:
    int alert_id;
    int vehicle_id;
    std::string alert_type;

    Alert(int id, int v_id, const std::string& type) 
        : alert_id(id), vehicle_id(v_id), alert_type(type) {}
};

class OptimizationRecord {
public:
    int optimization_id;
    int vehicle_id;
    std::string details;

    OptimizationRecord(int id, int v_id, const std::string& details) 
        : optimization_id(id), vehicle_id(v_id), details(details) {}
};

class FleetManagementSystem {
private:
    std::vector<Driver> drivers;
    std::vector<Vehicle> vehicles;
    std::vector<MaintenanceRecord> maintenance_records;
    std::vector<Alert> alerts;
    std::vector<OptimizationRecord> optimization_records;

public:
    void addDriver(int id, const std::string& name, const std::string& contact) {
        drivers.emplace_back(id, name, contact);
    }

    void addVehicle(int id, const std::string& type) {
        vehicles.emplace_back(id, type);
    }

    void addMaintenanceRecord(int id, int vehicle_id, const std::string& type) {
        maintenance_records.emplace_back(id, vehicle_id, type);
    }

    void addAlert(int id, int vehicle_id, const std::string& type) {
        alerts.emplace_back(id, vehicle_id, type);
    }

    void addOptimizationRecord(int id, int vehicle_id, const std::string& details) {
        optimization_records.emplace_back(id, vehicle_id, details);
    }

    void displayAllRecords() const {
        std::cout << "\nAll Drivers:\n";
        for (const auto& driver : drivers) {
            std::cout << "Driver ID: " << driver.driver_id 
                      << ", Name: " << driver.name 
                      << ", Contact: " << driver.contact_number << "\n";
        }

        std::cout << "\nAll Vehicles:\n";
        for (const auto& vehicle : vehicles) {
            std::cout << "Vehicle ID: " << vehicle.vehicle_id 
                      << ", Type: " << vehicle.type << "\n";
        }

        std::cout << "\nAll Maintenance Records:\n";
        for (const auto& record : maintenance_records) {
            std::cout << "Record ID: " << record.record_id 
                      << ", Vehicle ID: " << record.vehicle_id 
                      << ", Maintenance Type: " << record.maintenance_type << "\n";
        }

        std::cout << "\nAll Alerts:\n";
        for (const auto& alert : alerts) {
            std::cout << "Alert ID: " << alert.alert_id 
                      << ", Vehicle ID: " << alert.vehicle_id 
                      << ", Alert Type: " << alert.alert_type << "\n";
        }

        std::cout << "\nAll Optimization Records:\n";
        for (const auto& optimization : optimization_records) {
            std::cout << "Optimization ID: " << optimization.optimization_id 
                      << ", Vehicle ID: " << optimization.vehicle_id 
                      << ", Details: " << optimization.details << "\n";
        }
    }
};

int main() {
    FleetManagementSystem fleet;
    int choice;

    do {
        std::cout << "1. Add Driver\n2. Add Vehicle\n3. Add Maintenance Record\n"
                  << "4. Add Alert\n5. Add Optimization Record\n"
                  << "6. Display All Records\n7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int id;
                std::string name, contact;
                std::cout << "Enter Driver ID: ";
                std::cin >> id;
                std::cout << "Enter Driver Name: ";
                std::cin >> name;
                std::cout << "Enter Contact Number: ";
                std::cin >> contact;
                fleet.addDriver(id, name, contact);
                break;
            }
            case 2: {
                int id;
                std::string type;
                std::cout << "Enter Vehicle ID: ";
                std::cin >> id;
                std::cout << "Enter Vehicle Type: ";
                std::cin >> type;
                fleet.addVehicle(id, type);
                break;
            }
            case 3: {
                int id, vehicle_id;
                std::string type;
                std::cout << "Enter Maintenance Record ID: ";
                std::cin >> id;
                std::cout << "Enter Vehicle ID: ";
                std::cin >> vehicle_id;
                std::cout << "Enter Maintenance Type: ";
                std::cin >> type;
                fleet.addMaintenanceRecord(id, vehicle_id, type);
                break;
            }
            case 4: {
                int id, vehicle_id;
                std::string type;
                std::cout << "Enter Alert ID: ";
                std::cin >> id;
                std::cout << "Enter Vehicle ID: ";
                std::cin >> vehicle_id;
                std::cout << "Enter Alert Type: ";
                std::cin >> type;
                fleet.addAlert(id, vehicle_id, type);
                break;
            }
            case 5: {
                int id, vehicle_id;
                std::string details;
                std::cout << "Enter Optimization Record ID: ";
                std::cin >> id;
                std::cout << "Enter Vehicle ID: ";
                std::cin >> vehicle_id;
                std::cout << "Enter Optimization Details: ";
                std::cin >> details;
                fleet.addOptimizationRecord(id, vehicle_id, details);
                break;
            }
            case 6:
                fleet.displayAllRecords();
                break;
            case 7:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}


