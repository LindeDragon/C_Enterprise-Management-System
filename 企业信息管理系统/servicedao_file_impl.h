#ifndef SERVICEDAO_FILE_IMPL_H
#define SERVICEDAO_FILE_IMPL_H

#include "servicedao.h"
#include <fstream>

class ServiceDaoFileImpl:public ServiceDao
{
public:
    // 从文件读取部门及员工信息
    vector<Department>& load(vector<Department>& data);

    // 将部门及员工信息写入文件
    void save(vector<Department>& data);
};

#endif // SERVICEDAO_FILE_IMPL_H
