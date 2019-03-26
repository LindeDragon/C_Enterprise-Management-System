#ifndef MANAGER_H
#define MANAGER_H

#include <cstring>
#include <iostream>

using namespace std;

class Manager
{
public:
    // ID号
    int id;
    // 用户名
    char name[20];
    // 密码
    char password[20];

    Manager(int id,char* name,char* password);

    Manager();

    int get_id();

    void set_id(int id);

    char* get_name();

    void set_name(char* name);

    char* get_password();

    void set_password(char* password);

    friend ostream& operator<<(ostream& os,Manager& manager);

};

#endif // MANAGER_H
