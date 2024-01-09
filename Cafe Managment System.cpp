#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Admin;

class Admin {
public:
    string username;
    string password;

    Admin() : username("admin"), password("adminpass") {}

    bool authenticateStaff(const string& staffUsername, const string& staffPassword, const vector<Admin*>& staffList) {
        auto it = find_if(staffList.begin(), staffList.end(),
                          [staffUsername, staffPassword](const Admin* admin) {
                              return admin->username == staffUsername && admin->password == staffPassword;
                          });

        return it != staffList.end();
    }

    bool authenticateCustomer(const string& customerUsername, const string& customerPassword, const vector<Admin*>& customerList) {
        auto it = find_if(customerList.begin(), customerList.end(),
                          [customerUsername, customerPassword](const Admin* admin) {
                              return admin->username == customerUsername && admin->password == customerPassword;
                          });

        return it != customerList.end();
    }

    void addStaff(vector<Admin*>& staffList) {
        Admin* newStaff = new Admin;  
        cout << "Enter new staff username: ";
        cin >> newStaff->username;
        cout << "Enter new staff password: ";
        cin >> newStaff->password;

        staffList.push_back(newStaff);
        cout << "New staff added successfully.\n";
    }

    void removeStaff(vector<Admin*>& staffList) {
        string username;
        cout << "Enter staff username to remove: ";
        cin >> username;

        auto it = find_if(staffList.begin(), staffList.end(),
                          [username](const Admin* admin) {
                              return admin->username == username;
                          });

        if (it != staffList.end()) {
            delete *it;  // Deallocate memory for the Staff object
            staffList.erase(it);
            cout << "Staff removed successfully.\n";
        } else {
            cout << "Staff not found.\n";
        }
    }

    void viewStaff(const vector<Admin*>& staffList) {
        cout << "List of Staff Members:\n";
        for (const Admin* staff : staffList) {
            cout << staff->username << "\n";
        }
    }

    void modifyStaffUsername(vector<Admin*>& staffList) {
        string oldUsername, newUsername;
        cout << "Enter staff username to modify: ";
        cin >> oldUsername;

        auto it = find_if(staffList.begin(), staffList.end(),
                          [oldUsername](const Admin* admin) {
                              return admin->username == oldUsername;
                          });

        if (it != staffList.end()) {
            cout << "Enter new username: ";
            cin >> newUsername;
            (*it)->username = newUsername;
            cout << "Username modified successfully.\n";
        } else {
            cout << "Staff not found.\n";
        }
    }

    void modifyStaffPassword(vector<Admin*>& staffList) {
        string username, newPassword;
        cout << "Enter staff username to modify password: ";
        cin >> username;

        auto it = find_if(staffList.begin(), staffList.end(),
                          [username](const Admin* admin) {
                              return admin->username == username;
                          });

        if (it != staffList.end()) {
            cout << "Enter new password: ";
            cin >> newPassword;
            (*it)->password = newPassword;
            cout << "Password modified successfully.\n";
        } else {
            cout << "Staff not found.\n";
        }
    }

    void addCustomer(vector<Admin*>& customerList) {
        Admin* newCustomer = new Admin;  
        cout << "Enter new customer username: ";
        cin >> newCustomer->username;
        cout << "Enter new customer password: ";
        cin >> newCustomer->password;

        customerList.push_back(newCustomer);
        cout << "New customer added successfully.\n";
    }

    void removeCustomer(vector<Admin*>& customerList) {
        string username;
        cout << "Enter customer username to remove: ";
        cin >> username;

        auto it = find_if(customerList.begin(), customerList.end(),
                          [username](const Admin* admin) {
                              return admin->username == username;
                          });

        if (it != customerList.end()) {
            delete *it;  
            customerList.erase(it);
            cout << "Customer removed successfully.\n";
        } else {
            cout << "Customer not found.\n";
        }
    }

    void viewCustomer(const vector<Admin*>& customerList) {
        cout << "List of Customers:\n";
        for (const Admin* customer : customerList) {
            cout << customer->username << "\n";
        }
    }

    void modifyCustomerUsername(vector<Admin*>& customerList) {
        string oldUsername, newUsername;
        cout << "Enter customer username to modify: ";
        cin >> oldUsername;

        auto it = find_if(customerList.begin(), customerList.end(),
                          [oldUsername](const Admin* admin) {
                              return admin->username == oldUsername;
                          });

        if (it != customerList.end()) {
            cout << "Enter new username: ";
            cin >> newUsername;
            (*it)->username = newUsername;
            cout << "Username modified successfully.\n";
        } else {
            cout << "Customer not found.\n";
        }
    }

    void modifyCustomerPassword(vector<Admin*>& customerList) {
        string username, newPassword;
        cout << "Enter customer username to modify password: ";
        cin >> username;

        auto it = find_if(customerList.begin(), customerList.end(),
                          [username](const Admin* admin) {
                              return admin->username == username;
                          });

        if (it != customerList.end()) {
            cout << "Enter new password: ";
            cin >> newPassword;
            (*it)->password = newPassword;
            cout << "Password modified successfully.\n";
        } else {
            cout << "Customer not found.\n";
        }
    }

    void viewServices() {
        int choice,pages,hours;    
        do{
            cout<<"=== Available Services ===\n";
        cout<<"1. Printing $1 per 5 pages\n";
        cout<<"2. Scanning $1 per 5 pages\n";
        cout<<"3. Gaming $5 per hour\n";
        cout<<"4. Internet Browsing - $2 per hour\n";
        cout<<"5.Exist to main menu\n";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"How many pages do you want to print?\n";
                cin>>pages;
                cout<<"That will be $"<< (float)pages*0.20<<" for "<<pages<<" pages\n";
                break;
            case 2:
                cout<<"How many pages do you want to scan?\n";
                cin>>pages;
                cout<<"That will be $"<< (float)pages*0.20<<" for "<<pages<<" pages\n";
                break;
            case 3:
                cout<<"How many hours do you want to game?\n";
                cin>>hours;
                cout<<"That will be $"<< hours*5<<" for "<<hours<<" hours\n";
                break;
            case 4:
                cout<<"How many hours do you want to use the internet?\n";
                cin>>hours;
                cout<<"That will be $"<< hours*2<<" for "<<hours<<" hours\n";
                break;
            case 5:
                cout<<"Thanks for using our services";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
        } while(choice !=5);
    }

    void changeAdminPassword() {
        string newPassword;
        cout << "Enter new admin password: ";
        cin >> newPassword;

        this->password = newPassword;

        cout << "Admin password changed successfully.\n";
    }
    
    
     void changePassword() {
        string newPassword;
    cout << "Enter your current password: ";
    cin >> newPassword;

    if (password == newPassword) {
        cout << "Enter your new password: ";
        cin >> newPassword;

        this->password = newPassword;

        cout << "Password changed successfully.\n";
    } else {
        cout << "Incorrect current password. Password change failed.\n";
    }
    }  
    
    void staffMenu(vector<Admin*>& staffList, vector<Admin*>& customerList);
    void customerMenu(vector<Admin*>& customerList, vector<Admin*>& staffList);
    void menu(vector<Admin*>& staffList, vector<Admin*>& customerList);
};


  

void Admin::menu(vector<Admin*>& staffList, vector<Admin*>& customerList) {
    int choice;
    do {
        cout << "\nAdmin Menu\n";
        cout << "1. Add Staff\n";
        cout << "2. Remove Staff\n";
        cout << "3. View Staff\n";
        cout << "4. Modify Staff Username\n";
        cout << "5. Modify Staff Password\n";
        cout << "6. Add Customer\n";
        cout << "7. Remove Customer\n";
        cout << "8. View Customers\n";
        cout << "9. Modify Customer Username\n";
        cout << "10. Modify Customer Password\n";
        cout << "11. View Services\n";
        cout << "12. Change Admin Password\n";
        cout << "13. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStaff(staffList);
                break;
            case 2:
                removeStaff(staffList);
                break;
            case 3:
                viewStaff(staffList);
                break;
            case 4:
                modifyStaffUsername(staffList);
                break;
            case 5:
                modifyStaffPassword(staffList);
                break;
            case 6:
                addCustomer(customerList);
                break;
            case 7:
                removeCustomer(customerList);
                break;
            case 8:
                viewCustomer(customerList);
                break;
            case 9:
                modifyCustomerUsername(customerList);
                break;
            case 10:
                modifyCustomerPassword(customerList);
                break;
            case 11:
                viewServices();
                break;
            case 12:
                changeAdminPassword();
                break;
            case 13:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 13);
}

void Admin::staffMenu(vector<Admin*>& staffList, vector<Admin*>& customerList) {
    int choice;
    do {
        cout << "\nStaff Menu\n";
        cout << "1. Add Customer\n";
        cout << "2. Remove Customer\n";
        cout << "3. View Customers\n";
        cout << "4. Modify Customer Username\n";
        cout << "5. Modify Customer Password\n";
        cout << "6. View Services\n";
        cout << "7. Change Password\n";
        cout << "8. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addCustomer(customerList);
                break;
            case 2:
                removeCustomer(customerList);
                break;
            case 3:
                viewCustomer(customerList);
                break;
            case 4:
                modifyCustomerUsername(customerList);
                break;
            case 5:
                modifyCustomerPassword(customerList);
                break;
            case 6:
                viewServices();
                break;
            case 7:
                 changePassword();
                break;
            case 8:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);
}

void Admin::customerMenu(vector<Admin*>& customerList, vector<Admin*>& staffList) {
    int choice;
    do {
        cout << "\nCustomer Menu\n";
        cout << "1. View Services\n";
        cout << "2. Change Password\n";
        cout << "3. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                viewServices();
                break;
            case 2:
                 changePassword();
                break;
            case 3:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
}

int main() {
    vector<Admin*> staffList;
    vector<Admin*> customerList;
    Admin admin;

    staffList.push_back(&admin);

    int choice;
    do {
        cout << "Welcome to Cyber Cafe Management System\n";
        cout << "1. Login as Admin\n";
        cout << "2. Login as Staff\n";
        cout << "3. Login as Customer\n";
        cout << "4. Register as New Customer\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    string username, password;
                    cout << "Enter Admin username: ";
                    cin >> username;
                    cout << "Enter Admin password: ";
                    cin >> password;

                    if (admin.authenticateStaff(username, password, staffList)) {
                        admin.menu(staffList, customerList);
                    } else {
                        cout << "Invalid username or password. Login failed.\n";
                    }
                }
                break;
            case 2:
                {
                    string username, password;
                    cout << "Enter Staff username: ";
                    cin >> username;
                    cout << "Enter Staff password: ";
                    cin >> password;

                    if (admin.authenticateStaff(username, password, staffList)) {
                        Admin staff;  // Creating an Admin object for staff
                        staff.staffMenu(staffList, customerList);
                    } else {
                        cout << "Invalid username or password. Login failed.\n";
                    }
                }
                break;
            case 3:
                {
                    string username, password;
                    cout << "Enter Customer username: ";
                    cin >> username;
                    cout << "Enter Customer password: ";
                    cin >> password;

                    if (admin.authenticateCustomer(username, password, customerList)) {
                        Admin customer;  
                        customer.customerMenu(customerList, staffList);
                    } else {
                        cout << "Invalid username or password. Login failed.\n";
                    }
                }
                break;
            case 4:
                {
                    Admin* newCustomer = new Admin;  
                    cout << "Enter new customer username: ";
                    cin >> newCustomer->username;
                    cout << "Enter new customer password: ";
                    cin >> newCustomer->password;
                    customerList.push_back(newCustomer);
                    cout << "New customer registered successfully.\n";
                }
                break;
            case 0:
                cout << "Exiting Cyber Cafe Management System. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    
    for (Admin* admin : staffList) {
        delete admin;
    }

    for (Admin* admin : customerList) {
        delete admin;
    }

    return 0;
}
