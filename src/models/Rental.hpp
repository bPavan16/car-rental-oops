#ifndef RENTAL_H
#define RENTAL_H

#include "Car.hpp"
#include "Customer.hpp"
#include "../utils/Date.hpp"
#include <string>

class Rental
{
private:
    std::string rentalId;
    Car *car;
    Customer *customer;
    Date startDate;
    Date endDate;
    double totalCost;
    bool isActive;

public:
    Rental(const std::string &id, Car *car, Customer *customer,
           const Date &start, const Date &end);
    ~Rental();

    // Getters
    std::string getRentalId() const;
    Car *getCar() const;
    Customer *getCustomer() const;
    Date getStartDate() const;
    Date getEndDate() const;
    double getTotalCost() const;
    bool getIsActive() const;

    // Business Logic
    void calculateTotalCost();
    void startRental();
    void endRental();
    int getRentalDuration() const;
    std::string getRentalDetails() const;
};

#endif