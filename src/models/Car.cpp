#include "car.hpp"
#include <sstream>

Car::Car() : carId(""), brand(""), model(""), year(0), rentalRate(0.0), isAvailable(true) {}

Car::Car(std::string id, std::string brand, std::string model, int year, double rate)
    : carId(id), brand(brand), model(model), year(year), rentalRate(rate), isAvailable(true) {}

// Getter implementations
std::string Car::getCarId() const { return carId; }
std::string Car::getBrand() const { return brand; }
std::string Car::getModel() const { return model; }
int Car::getYear() const { return year; }
double Car::getRentalRate() const { return rentalRate; }
bool Car::getAvailability() const { return isAvailable; }

// Setter implementations
void Car::setCarId(const std::string &id) { carId = id; }
void Car::setBrand(const std::string &b) { brand = b; }
void Car::setModel(const std::string &m) { model = m; }
void Car::setYear(int y) { year = y; }
void Car::setRentalRate(double rate) { rentalRate = rate; }
void Car::setAvailability(bool available) { isAvailable = available; }

std::string Car::getCarDetails() const
{
    std::stringstream ss;
    ss << "Car ID: " << carId << "\n"
       << "Brand: " << brand << "\n"
       << "Model: " << model << "\n"
       << "Year: " << year << "\n"
       << "Rental Rate: $" << rentalRate << "/day\n"
       << "Available: " << (isAvailable ? "Yes" : "No") << "\n";
    return ss.str();
}