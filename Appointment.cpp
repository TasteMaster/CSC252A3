#include <iostream>
#include <string>
#include <vector>

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
        int date::getDay(int d) const;
        int date::getMonth(int m) const;
        int date::getYear(int y) const;
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
    
}

// Monthly derived class
class monthly : public appointment
{
    
};  

// Appointment vector filler in main
int main()
{
    

}