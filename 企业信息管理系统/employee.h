#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

using namespace std;

class Employee
{
public:
    // ID号
    int id;
    // 姓名
    char name[20];
    // 性别
    bool gender;
    // 年龄
    int age;

    Employee(int id,const char* name,bool gender,int age);

    Employee& operator=(const Employee& that);

    Employee();

    int get_id(void);

    void set_id(int id);

    char* get_name(void);

    void set_name(const char* name);

    bool get_gender(void);

    void set_gender(bool gender);

    int get_age(void);

    void set_age(int age);

    friend ostream& operator<<(ostream& os,const Employee& employee);
};
#endif // EMPLOYEE_H
