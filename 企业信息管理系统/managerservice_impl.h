#ifndef MANAGERSERVICE_IMPL_H
#define MANAGERSERVICE_IMPL_H

#include "managerservice.h"
#include "managerdao_file_impl.h"

class ManagerServiceImpl:public ManagerService
{
    // 数据访问对象
    ManagerDao* dao;

    // 管理员对象容器
    vector<Manager> m_vecMana;
public:
    ManagerServiceImpl(ManagerDao* dao,vector<Manager>& m_vecMana);

    ManagerServiceImpl();

    ~ManagerServiceImpl();

    // 覆盖重写,增加管理员
    bool addManager(Manager* manager);

    // 覆盖重写,删除管理员
    bool deleteManager(int id);

    // 覆盖重写,列出所有管理员
    void listManager(void);

    // 登录
    bool load(char* name,char* password);


};

#endif // MANAGERSERVICE_IMPL_H
