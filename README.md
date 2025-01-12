# Car Rental System

## Overview

The Car Rental System is an object-oriented application designed for managing car rentals. It allows customers to rent cars, view available vehicles, and process payments. The application is structured to demonstrate key concepts of object-oriented programming, including encapsulation, inheritance, and polymorphism.

## Features

- Manage car inventory
- Customer registration and management
- Rental management
- Payment processing
- Utility functions for date handling

## Project Structure

```
car-rental-system
├── src
│   ├── main.cpp
│   ├── models
│   │   ├── Car.hpp
│   │   ├── Car.cpp
│   │   ├── Customer.hpp
│   │   ├── Customer.cpp
│   │   ├── Rental.hpp
│   │   └── Rental.cpp
│   ├── services
│   │   ├── RentalService.hpp
│   │   ├── RentalService.cpp
│   │   ├── PaymentService.hpp
│   │   └── PaymentService.cpp
│   └── utils
│       ├── Date.hpp
│       └── Date.cpp
├── tests
│   ├── CarTest.cpp
│   ├── CustomerTest.cpp
│   └── RentalTest.cpp
├── CMakeLists.txt
└── README.md
```

## Setup Instructions

1. Clone the repository:
   ```
   git clone <repository-url>
   ```
2. Navigate to the project directory:
   ```
   cd car-rental-system
   ```

## License

This project is licensed under the MIT License.
