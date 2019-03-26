#ifndef MANAGERDAO_FILE_IMPL_H
#define MANAGERDAO_FILE_IMPL_H

#include "managerdao.h"
#include <fstream>

class ManagerDaoFileImpl:public ManagerDao
{
public:
    // 覆盖重写,从文件读取管理员信息
    vector<Manager>& load(vector<Manager>& manager);

    // 覆盖重写,将管理员信息写入文件
    void save(vector<Manager>& manager);
};

#endif // MANAGERDAO_FILE_IMPL_H
