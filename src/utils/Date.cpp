#include "Date.hpp"
#include <sstream>
#include <iomanip>
#include <stdexcept>

Date::Date() : day(1), month(1), year(2024) {}

Date::Date(int d, int m, int y)
{
    if (!isValidDate(d, m, y))
    {
        throw std::invalid_argument("Invalid date");
    }
    day = d;
    month = m;
    year = y;
}

bool Date::isLeapYear(int y) const
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int Date::getDaysInMonth(int m, int y) const
{
    static const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && isLeapYear(y))
    {
        return 29;
    }
    return daysInMonth[m];
}

bool Date::isValidDate(int d, int m, int y) const
{
    if (y < 1900 || y > 2100 || m < 1 || m > 12 || d < 1)
    {
        return false;
    }
    return d <= getDaysInMonth(m, y);
}

int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }

int Date::daysBetween(const Date &other) const
{
    // Simple implementation using Julian Day Number
    int j1 = (1461 * (year + 4800 + (month - 14) / 12)) / 4 +
             (367 * (month - 2 - 12 * ((month - 14) / 12))) / 12 -
             (3 * ((year + 4900 + (month - 14) / 12) / 100)) / 4 + day - 32075;

    int j2 = (1461 * (other.year + 4800 + (other.month - 14) / 12)) / 4 +
             (367 * (other.month - 2 - 12 * ((other.month - 14) / 12))) / 12 -
             (3 * ((other.year + 4900 + (other.month - 14) / 12) / 100)) / 4 + other.day - 32075;

    return j2 - j1;
}

bool Date::operator==(const Date &other) const
{
    return year == other.year && month == other.month && day == other.day;
}

bool Date::operator<(const Date &other) const
{
    if (year != other.year)
        return year < other.year;
    if (month != other.month)
        return month < other.month;
    return day < other.day;
}

std::string Date::toString() const
{
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << day << "/"
       << std::setfill('0') << std::setw(2) << month << "/"
       << year;
    return ss.str();
}