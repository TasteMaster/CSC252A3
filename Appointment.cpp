#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Checklist:
1. Base class Appointment - Elder
2. Derived class Day - Elder (started)
3. Derived class Monthly
4. Date class (optional) - Elder
5. Appointment vector filler in main
*/

// Date class
class date 
{
    public:
        date(int d, int m, int y);
        int getDay(int d) const;
        int getMonth(int m) const;
        int getYear(int y) const;
    private:
        int day;
        int month;
        int year;
};

// Date constructor
date::date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

// Date value returners
int date::getDay(int d) const
{
    return day;
}

int date::getMonth(int m) const
{
    return month;
}

int date::getYear(int y) const
{
    return year;
}

// Appointment base class
class appointment
{
    public:
        appointment(const std::string& desc, const date& app_date);
        virtual bool occurs_on(int day, int month, int year) const = 0;
        std::string getDescription() const;
        date getDate() const;
    private:
        std::string description;
        date app_date;
};

// Appointment value returners
std::string appointment::getDescription() const
{
    return description;
}

date appointment::getDate() const
{
    return app_date;
}

// Appointment constructor
appointment::appointment(const std::string& desc, const date& app_date) : description(desc), app_date(app_date)
{
    description = desc;
    this->app_date = app_date;    
}

// Day derived class
class day : public appointment
{
    public:
        day(std::string& desc, const date& app_date) : appointment(desc, app_date) {};
        bool occurs_on(int day, int month, int year) const override;
};

bool day::occurs_on(int day, int month, int year) const
{
    if (day == getDate().getDay(day) && month == getDate().getMonth(month) && year == getDate().getYear(year))
        return true;
    else
        return false;
}

// Monthly derived class
class monthly : public appointment
{
    public:
        monthly(std::string& desc, const date& app_date) : appointment(desc, app_date) {};
        bool occurs_on(int day, int year) const;
};  

bool monthly::occurs_on(int day, int year) const
{
    if (day == getDate().getDay(day) && year == getDate().getYear(year))
        return true;
    else
        return false;
}

// Appointment vector filler in main
int main()
{
    std::vector<appointment*> appointments;
    std::string desc;
    int day, month, year;

    // Example appointments
    date date1(15, 8, 2023);
    desc = "Doctor's Appointment";
    appointments.push_back(new day(desc, date1));

    date date2(1, 1, 2023);
    desc = "Monthly Meeting";
    appointments.push_back(new monthly(desc, date2));

    // Check for appointments on a specific date
    int check_day = 15;
    int check_month = 8;
    int check_year = 2023;

    std::cout << "Appointments on " << check_day << "/" << check_month << "/" << check_year << ":\n";
    for (const auto& app : appointments) {
        if (app->occurs_on(check_day, check_month, check_year)) {
            std::cout << "- " << app->getDescription() << "\n";
        }
    }

    // Clean up
    for (auto& app : appointments) {
        delete app;
    }
    appointments.clear();

    return 0;
}