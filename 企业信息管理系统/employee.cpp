#include "employee.h"
#include <cstring>

Employee::Employee(int id, const char *name, bool gender, int age)
{
    this->id = id;
    strcpy(this->name,name);
    this->gender = gender;
    this->age = age;
}

Employee& Employee::operator=(const Employee& that)
{
    if(this != &that)
    {
        this->id = that.id;
        strcpy(this->name,that.name);
        this->gender = that.gender;
        this->age = that.age;
    }

    return *this;
}

Employee::Employee(){}

int Employee::get_id(void)
{
    return this->id;
}

void Employee::set_id(int id)
{
    this->id = id;
}

char* Employee::get_name(void)
{
    return this->name;
}

void Employee::set_name(const char* name)
{
    strcpy(this->name,name);
}

bool Employee::get_gender(void)
{
    return this->gender;
}

void Employee::set_gender(bool gender)
{
    this->gender = gender;
}

int Employee::get_age(void)
{
    return this->age;
}

void Employee::set_age(int age)
{
   this->age = age;
}

ostream& operator<<(ostream& os,const Employee& employee)
{
    return os << employee.id << " " << employee.name << " " << employee.age << " " << employee.gender;
}
