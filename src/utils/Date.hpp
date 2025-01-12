#ifndef DATE_H
#define DATE_H

#include <string>

class Date
{
private:
    int day;
    int month;
    int year;

    bool isLeapYear(int year) const;
    int getDaysInMonth(int month, int year) const;
    bool isValidDate(int day, int month, int year) const;

public:
    Date();
    Date(int day, int month, int year);

    // Getters
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // Utility methods
    int daysBetween(const Date &other) const;
    bool operator==(const Date &other) const;
    bool operator<(const Date &other) const;
    std::string toString() const;
};

#endif