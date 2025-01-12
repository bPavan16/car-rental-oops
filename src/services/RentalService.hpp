#ifndef RENTAL_SERVICE_H
#define RENTAL_SERVICE_H

#include <vector>
#include <memory>
#include "../models/Car.hpp"
#include "../models/Customer.hpp"
#include "../models/Rental.hpp"
#include "../utils/Date.hpp"

class RentalService
{
private:
    std::vector<std::shared_ptr<Car>> cars;
    std::vector<std::shared_ptr<Customer>> customers;
    std::vector<std::shared_ptr<Rental>> rentals;
    int nextRentalId;

public:
    RentalService();

    // Car operations
    void addCar(std::shared_ptr<Car> car);
    void removeCar(const std::string &carId);
    std::vector<std::shared_ptr<Car>> getAvailableCars() const;
    std::shared_ptr<Car> findCarById(const std::string &carId) const;

    // Customer operations
    void addCustomer(std::shared_ptr<Customer> customer);
    void removeCustomer(const std::string &customerId);
    std::shared_ptr<Customer> findCustomerById(const std::string &customerId) const;

    // Rental operations
    std::shared_ptr<Rental> createRental(const std::string &carId,
                                         const std::string &customerId,
                                         const Date &startDate,
                                         const Date &endDate);
    void endRental(const std::string &rentalId);
    std::vector<std::shared_ptr<Rental>> getActiveRentals() const;
    std::shared_ptr<Rental> findRentalById(const std::string &rentalId) const;
};

#endif