#include <iostream>

using namespace std;

class appointment
{
    public:
        virtual void occurs_on(int day, int month, int year);
    private:
        string description;
        date app_date;
};

class daily : public appointment
{
    public:

    private:

};

class monthly : public appointment
{
    public:

    private:

};  

class date
{
    public:
        date(int d, int m, int y);
    private:
        int day;
        int month;
        int year;
};



int main()
{

}