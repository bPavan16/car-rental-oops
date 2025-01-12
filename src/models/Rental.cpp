#include "Rental.hpp"
#include <sstream>

Rental::Rental(const std::string &id, Car *c, Customer *cust,
               const Date &start, const Date &end)
    : rentalId(id), car(c), customer(cust),
      startDate(start), endDate(end),
      totalCost(0.0), isActive(false)
{
    calculateTotalCost();
}

Rental::~Rental()
{
    // Note: Car and Customer pointers are not owned by Rental
    // They should be managed by RentalService
}

// Getter implementations
std::string Rental::getRentalId() const { return rentalId; }
Car *Rental::getCar() const { return car; }
Customer *Rental::getCustomer() const { return customer; }
Date Rental::getStartDate() const { return startDate; }
Date Rental::getEndDate() const { return endDate; }
double Rental::getTotalCost() const { return totalCost; }
bool Rental::getIsActive() const { return isActive; }

void Rental::calculateTotalCost()
{
    int days = getRentalDuration();
    totalCost = days * car->getRentalRate();
}

void Rental::startRental()
{
    if (!isActive && car->getAvailability())
    {
        isActive = true;
        car->setAvailability(false);
    }
}

void Rental::endRental()
{
    if (isActive)
    {
        isActive = false;
        car->setAvailability(true);
    }
}

int Rental::getRentalDuration() const
{
    return startDate.daysBetween(endDate);
}

std::string Rental::getRentalDetails() const
{
    std::stringstream ss;
    ss << "Rental ID: " << rentalId << "\n"
       << "Customer: " << customer->getName() << "\n"
       << "Car: " << car->getBrand() << " " << car->getModel() << "\n"
       << "Duration: " << getRentalDuration() << " days\n"
       << "Total Cost: $" << totalCost << "\n"
       << "Status: " << (isActive ? "Active" : "Inactive") << "\n";
    return ss.str();
}