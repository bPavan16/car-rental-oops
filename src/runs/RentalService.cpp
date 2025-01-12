#include "RentalService.hpp"
#include <algorithm>
#include <stdexcept>

RentalService::RentalService() : nextRentalId(1) {}

void RentalService::addCar(std::shared_ptr<Car> car)
{
    cars.push_back(car);
}

void RentalService::removeCar(const std::string &carId)
{
    cars.erase(
        std::remove_if(cars.begin(), cars.end(),
                       [&carId](const auto &car)
                       { return car->getCarId() == carId; }),
        cars.end());
}

std::vector<std::shared_ptr<Car>> RentalService::getAvailableCars() const
{
    std::vector<std::shared_ptr<Car>> availableCars;
    for (const auto &car : cars)
    {
        if (car->getAvailability())
        {
            availableCars.push_back(car);
        }
    }
    return availableCars;
}

std::shared_ptr<Car> RentalService::findCarById(const std::string &carId) const
{
    auto it = std::find_if(cars.begin(), cars.end(),
                           [&carId](const auto &car)
                           { return car->getCarId() == carId; });
    return (it != cars.end()) ? *it : nullptr;
}

void RentalService::addCustomer(std::shared_ptr<Customer> customer)
{
    customers.push_back(customer);
}

void RentalService::removeCustomer(const std::string &customerId)
{
    customers.erase(
        std::remove_if(customers.begin(), customers.end(),
                       [&customerId](const auto &customer)
                       {
                           return customer->getCustomerId() == customerId;
                       }),
        customers.end());
}

std::shared_ptr<Customer> RentalService::findCustomerById(
    const std::string &customerId) const
{
    auto it = std::find_if(customers.begin(), customers.end(),
                           [&customerId](const auto &customer)
                           {
                               return customer->getCustomerId() == customerId;
                           });
    return (it != customers.end()) ? *it : nullptr;
}

std::shared_ptr<Rental> RentalService::createRental(
    const std::string &carId,
    const std::string &customerId,
    const Date &startDate,
    const Date &endDate)
{

    auto car = findCarById(carId);
    auto customer = findCustomerById(customerId);

    if (!car || !customer)
    {
        throw std::invalid_argument("Invalid car or customer ID");
    }

    if (!car->getAvailability())
    {
        throw std::runtime_error("Car is not available");
    }

    std::string rentalId = "R" + std::to_string(nextRentalId++);
    auto rental = std::make_shared<Rental>(rentalId, car.get(),
                                           customer.get(), startDate, endDate);
    rental->startRental();
    rentals.push_back(rental);

    return rental;
}

void RentalService::endRental(const std::string &rentalId)
{
    auto rental = findRentalById(rentalId);
    if (rental)
    {
        rental->endRental();
    }
}

std::vector<std::shared_ptr<Rental>> RentalService::getActiveRentals() const
{
    std::vector<std::shared_ptr<Rental>> activeRentals;
    for (const auto &rental : rentals)
    {
        if (rental->getIsActive())
        {
            activeRentals.push_back(rental);
        }
    }
    return activeRentals;
}

std::shared_ptr<Rental> RentalService::findRentalById(
    const std::string &rentalId) const
{
    auto it = std::find_if(rentals.begin(), rentals.end(),
                           [&rentalId](const auto &rental)
                           {
                               return rental->getRentalId() == rentalId;
                           });
    return (it != rentals.end()) ? *it : nullptr;
}