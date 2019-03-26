#ifndef MANAGERSERVICE_H
#define MANAGERSERVICE_H

#include "manager.h"
#include "managerdao.h"
#include "emis.h"
#include <vector>

class ManagerService
{
public:
    // 增加管理员
    virtual bool addManager(Manager* manager) = 0;

    // 删除管理员
    virtual bool deleteManager(int id) = 0;

    // 列出所有管理员
    virtual void listManager(void) = 0;

    // 登录
    virtual bool load(char* name,char* password) = 0;

    virtual  ~ManagerService() {}
};

#endif // MANAGERSERVICE_H
