#ifndef MANAGERVIEW_H
#define MANAGERVIEW_H

#include "managerservice.h"


class ManagerView
{
public:
    // 显示主菜单
    virtual void menu(void) = 0;

    // 处理增加管理员菜单项
    virtual void add(void) = 0;

    // 处理删除管理员菜单项
    virtual void del(void) = 0;

    // 处理列出所有管理员菜单项
    virtual void list(void) = 0;

    // 登录
    virtual bool load() = 0;

    virtual  ~ManagerView() {}
};

#endif // MANAGERVIEW_H
