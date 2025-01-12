#include "PaymentService.hpp"
#include <ctime>
#include <sstream>
#include <iomanip>

PaymentService::PaymentService() : totalRevenue(0.0) {}

bool PaymentService::processPayment(const Rental *rental)
{
    if (!rental)
        return false;

    // Generate payment ID
    std::stringstream ss;
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    ss << "PMT" << std::put_time(&tm, "%Y%m%d%H%M%S");

    // Create payment record
    Payment payment;
    payment.paymentId = ss.str();
    payment.rentalId = rental->getRentalId();
    payment.amount = rental->getTotalCost();
    payment.status = true;
    std::ostringstream timestampStream;
    timestampStream << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    payment.timestamp = timestampStream.str();

    // Update total revenue
    totalRevenue += payment.amount;

    // Store payment
    payments.push_back(payment);

    return true;
}

double PaymentService::getTotalRevenue() const
{
    return totalRevenue;
}

std::vector<Payment> PaymentService::getPaymentHistory() const
{
    return payments;
}

Payment *PaymentService::getPaymentById(const std::string &paymentId)
{
    for (auto &payment : payments)
    {
        if (payment.paymentId == paymentId)
        {
            return &payment;
        }
    }
    return nullptr;
}