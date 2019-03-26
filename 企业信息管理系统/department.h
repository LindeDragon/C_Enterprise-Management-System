#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <vector>
#include "employee.h"
#include <cstring>
#include <iostream>

using namespace std;

class Department
{
public:
    // ID号
    int id;
    // 名称
    char name[20];
    // 员工对象容器
    vector<Employee> m_vecEmps;

    Department(int id,char* name);

    Department();

    int get_id();

    void set_id(int id);

    char* get_name(void);

    void set_name(char* name);

    vector<Employee> get_m_vecEmps();

    void set_m_vecEmps(vector<Employee> m_vecEmps);

    // 删除本部门的员工
    bool deleteEmp(int id);

    // 列出本部门的员工
    void listEmp(void);

    // 修改本部门的员工信息
    bool modifyEmp(Employee *emp);

    friend ostream& operator<<(ostream& os,Department& department);
};

#endif // DEPARTMENT_H
