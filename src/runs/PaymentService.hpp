#ifndef PAYMENT_SERVICE_H
#define PAYMENT_SERVICE_H

#include <vector>
#include <string>
#include "../models/Rental.hpp"

struct Payment
{
    std::string paymentId;
    std::string rentalId;
    double amount;
    bool status;
    std::string timestamp;
};

class PaymentService
{
private:
    std::vector<Payment> payments;
    double totalRevenue;

public:
    PaymentService();
    bool processPayment(const Rental *rental);
    double getTotalRevenue() const;
    std::vector<Payment> getPaymentHistory() const;
    Payment *getPaymentById(const std::string &paymentId);
};

#endif