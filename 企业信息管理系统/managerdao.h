#ifndef MANAGERDAO_H
#define MANAGERDAO_H

#include "manager.h"
#include <vector>

using namespace std;

class ManagerDao
{
public:
    // 从数据存储读取管理员信息
    virtual vector<Manager>& load(vector<Manager>& manager) = 0;

    // 将管理员信息写入数据存储
    virtual void save(vector<Manager>& manager) = 0;

    virtual  ~ManagerDao() {}
};

#endif // MANAGERDAO_H
