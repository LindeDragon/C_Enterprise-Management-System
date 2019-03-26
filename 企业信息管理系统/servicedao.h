#ifndef SERVICEDAO_H
#define SERVICEDAO_H

#include "department.h"
#include <vector>

class ServiceDao
{
public:
    // 从数据存储读取部门及员工信息
    virtual vector<Department>& load(vector<Department>& data) = 0;

    // 将部门及员工信息写入数据存储
    virtual void save(vector<Department>& data) = 0;

    virtual  ~ServiceDao() {}
};

#endif // SERVICEDAO_H
