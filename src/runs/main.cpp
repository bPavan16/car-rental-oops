#include <iostream>
#include <memory>
#include "RentalService.hpp"
#include "PaymentService.hpp"
#include "Car.hpp"
#include "Customer.hpp"
#include "Rental.hpp"
#include "Date.hpp"
#include "RentalService.cpp"
#include "PaymentService.cpp"
#include "Car.cpp"
#include "Customer.cpp"
#include "Rental.cpp"
#include "Date.cpp"

void displayMenu()
{
    std::cout << "\n=== Car Rental System ===\n"
              << "1. Add Car\n"
              << "2. Add Customer\n"
              << "3. Create Rental\n"
              << "4. End Rental\n"
              << "5. View Available Cars\n"
              << "6. View Active Rentals\n"
              << "7. Exit\n"
              << "Enter choice: ";
}

int main()
{
    RentalService rentalService;
    PaymentService paymentService;

    // Add sample cars
    auto car1 = std::make_shared<Car>("C001", "Toyota", "Camry", 2022, 50.0);
    auto car2 = std::make_shared<Car>("C002", "Honda", "Civic", 2021, 45.0);
    auto car3 = std::make_shared<Car>("C003", "Tesla", "Model 3", 2023, 80.0);

    rentalService.addCar(car1);
    rentalService.addCar(car2);
    rentalService.addCar(car3);

    // Add sample customers
    auto customer1 = std::make_shared<Customer>("CUST001", "John Doe",
                                                "john@email.com", "123-456-7890",
                                                "DL123456");
    auto customer2 = std::make_shared<Customer>("CUST002", "Jane Smith",
                                                "jane@email.com", "987-654-3210",
                                                "DL789012");

    rentalService.addCustomer(customer1);
    rentalService.addCustomer(customer2);

    int choice;
    do
    {
        displayMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            std::string id, brand, model;
            int year;
            double rate;

            std::cout << "Enter Car Details (ID Brand Model Year Rate): ";
            std::cin >> id >> brand >> model >> year >> rate;

            auto newCar = std::make_shared<Car>(id, brand, model, year, rate);
            rentalService.addCar(newCar);
            std::cout << "Car added successfully!\n";
            break;
        }
        case 2:
        {
            std::string id, name, email, phone, license;

            std::cout << "Enter Customer Details (ID Name Email Phone License): ";
            std::cin >> id >> name >> email >> phone >> license;

            auto newCustomer = std::make_shared<Customer>(id, name, email, phone, license);
            rentalService.addCustomer(newCustomer);
            std::cout << "Customer added successfully!\n";
            break;
        }
        case 3:
        {
            std::string carId, customerId;
            int startDay, startMonth, startYear;
            int endDay, endMonth, endYear;

            std::cout << "Enter Car ID and Customer ID: ";
            std::cin >> carId >> customerId;
            std::cout << "Enter Start Date (DD MM YYYY): ";
            std::cin >> startDay >> startMonth >> startYear;
            std::cout << "Enter End Date (DD MM YYYY): ";
            std::cin >> endDay >> endMonth >> endYear;

            Date startDate(startDay, startMonth, startYear);
            Date endDate(endDay, endMonth, endYear);

            try
            {
                auto rental = rentalService.createRental(carId, customerId, startDate, endDate);
                if (paymentService.processPayment(rental.get()))
                {
                    std::cout << "Rental created and payment processed successfully!\n";
                }
            }
            catch (const std::exception &e)
            {
                std::cout << "Error: " << e.what() << "\n";
            }
            break;
        }
        case 4:
        {
            std::string rentalId;
            std::cout << "Enter Rental ID to end: ";
            std::cin >> rentalId;
            rentalService.endRental(rentalId);
            std::cout << "Rental ended successfully!\n";
            break;
        }
        case 5:
        {
            auto availableCars = rentalService.getAvailableCars();
            std::cout << "\nAvailable Cars:\n";
            for (const auto &car : availableCars)
            {
                std::cout << car->getCarDetails() << "\n";
            }
            break;
        }
        case 6:
        {
            auto activeRentals = rentalService.getActiveRentals();
            std::cout << "\nActive Rentals:\n";
            for (const auto &rental : activeRentals)
            {
                std::cout << rental->getRentalDetails() << "\n";
            }
            break;
        }
        case 7:
            std::cout << "Thank you for using Car Rental System!\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}