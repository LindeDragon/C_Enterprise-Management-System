#include "manager.h"

Manager::Manager(int id,char* name,char* password)
{
    this->id = id;
    strcpy(this->name,name);
    strcpy(this->password,password);
}

Manager::Manager(){}

int Manager::get_id()
{
    return this->id;
}

void Manager::set_id(int id)
{
    this->id = id;
}

char* Manager::get_name()
{
    return this->name;
}

void Manager::set_name(char* name)
{
    strcpy(this->name,name);
}

char* Manager::get_password()
{
    return this->password;
}

void Manager::set_password(char* password)
{
    strcpy(this->password,password);
}

ostream& operator<<(ostream& os,Manager& manager)
{
    return os << "ID:" << manager.id << "\t用户名:" << manager.name << "\t密码:" << manager.password;
}
