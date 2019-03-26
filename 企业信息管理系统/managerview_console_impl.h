#ifndef MANAGERVIEW_CONSOLE_IMPL_H
#define MANAGERVIEW_CONSOLE_IMPL_H

#include <iostream>
#include "managerview.h"
#include "managerservice_impl.h"
#include "tools.h"

class ManagerViewConsoleImpl:public ManagerView
{
    // 业务逻辑对象
    ManagerService* service;
public:
    ManagerViewConsoleImpl(ManagerService* service);

    ManagerViewConsoleImpl();

    ~ManagerViewConsoleImpl();

    // 覆盖重写,通过控制台显示主菜单
    void menu(void);

    // 覆盖重写,通过控制台处理增加管理员菜单项
    void add(void);

    // 覆盖重写,通过控制台处理删除管理员菜单项
    void del(void);

    // 覆盖重写,通过控制台处理列出所有管理员菜单项
    void list(void);

    // 登录
    bool load();

};
#endif // MANAGERVIEW_CONSOLE_IMPL_H
