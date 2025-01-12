#include "Customer.hpp"
#include <sstream>

Customer::Customer() : customerId(""), name(""), email(""), phone(""),
                       drivingLicense(""), isActive(true) {}

Customer::Customer(const std::string &id, const std::string &n,
                   const std::string &e, const std::string &p,
                   const std::string &license) : customerId(id), name(n), email(e), phone(p),
                                                 drivingLicense(license), isActive(true) {}

// Getter implementations
std::string Customer::getCustomerId() const { return customerId; }
std::string Customer::getName() const { return name; }
std::string Customer::getEmail() const { return email; }
std::string Customer::getPhone() const { return phone; }
std::string Customer::getDrivingLicense() const { return drivingLicense; }
bool Customer::getIsActive() const { return isActive; }

// Setter implementations
void Customer::setName(const std::string &n) { name = n; }
void Customer::setEmail(const std::string &e) { email = e; }
void Customer::setPhone(const std::string &p) { phone = p; }
void Customer::setDrivingLicense(const std::string &license) { drivingLicense = license; }
void Customer::setIsActive(bool status) { isActive = status; }

std::string Customer::getCustomerDetails() const
{
    std::stringstream ss;
    ss << "Customer ID: " << customerId << "\n"
       << "Name: " << name << "\n"
       << "Email: " << email << "\n"
       << "Phone: " << phone << "\n"
       << "Driving License: " << drivingLicense << "\n"
       << "Status: " << (isActive ? "Active" : "Inactive") << "\n";
    return ss.str();
}