#ifndef SERVICE_H
#define SERVICE_H

#include "department.h"
#include "employee.h"
#include "servicedao.h"
#include <vector>

class Service
{
public:
    // 增加部门
    virtual bool addDept(Department* dept) = 0;

    // 删除部门
    virtual bool deleteDept(int deptid) = 0;

    // 列出部门
    virtual void listDept(void) = 0;

    // 增加员工
    virtual bool addEmp(int id,Employee* emp) = 0;

    // 删除员工
    virtual bool deleteEmp(int empid) = 0;

    // 修改员工信息
    virtual bool modifyEmp(Employee* emp) = 0;

    // 列出部门员工
    virtual void listEmp(int deptid) = 0;

    // 列出所有员工
    virtual void listAllEmp(void) = 0;

    virtual  ~Service() {}

};

#endif // SERVICE_H
