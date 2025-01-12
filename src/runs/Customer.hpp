#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer
{
private:
    std::string customerId;
    std::string name;
    std::string email;
    std::string phone;
    std::string drivingLicense;
    bool isActive;

public:
    // Constructors
    Customer();
    Customer(const std::string &id, const std::string &name,
             const std::string &email, const std::string &phone,
             const std::string &license);

    // Getters
    std::string getCustomerId() const;
    std::string getName() const;
    std::string getEmail() const;
    std::string getPhone() const;
    std::string getDrivingLicense() const;
    bool getIsActive() const;

    // Setters
    void setName(const std::string &name);
    void setEmail(const std::string &email);
    void setPhone(const std::string &phone);
    void setDrivingLicense(const std::string &license);
    void setIsActive(bool status);

    // Utility methods
    std::string getCustomerDetails() const;
};

#endif