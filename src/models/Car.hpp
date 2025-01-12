#ifndef CAR_H
#define CAR_H

#include <string>

class Car
{
private:
    std::string carId;
    std::string brand;
    std::string model;
    int year;
    double rentalRate;
    bool isAvailable;

public:
    // Constructors
    Car();
    Car(std::string id, std::string brand, std::string model, int year, double rate);

    // Getters
    std::string getCarId() const;
    std::string getBrand() const;
    std::string getModel() const;
    int getYear() const;
    double getRentalRate() const;
    bool getAvailability() const;

    // Setters
    void setCarId(const std::string &id);
    void setBrand(const std::string &brand);
    void setModel(const std::string &model);
    void setYear(int year);
    void setRentalRate(double rate);
    void setAvailability(bool available);

    // Other methods
    std::string getCarDetails() const;
};

#endif