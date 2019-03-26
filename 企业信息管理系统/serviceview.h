#ifndef SERVICEVIEW_H
#define SERVICEVIEW_H

#include "service.h"
#include "service_impl.h"

class ServiceView
{
public:
    // 显示运营管理子菜单
    virtual void menu(void) = 0;

    // 处理增加部门菜单项
    virtual void addDept(void)= 0;

    // 处理删除部门菜单项
    virtual void deleteDept(void)= 0;

    // 处理列出部门菜单项
    virtual void listDept(void)= 0;

    // 处理增加员工菜单项
    virtual void addEmp(void)= 0;

    // 处理删除员工菜单项
    virtual void deleteEmp(void)= 0;

    // 处理修改员工信息菜单项
    virtual void modifyEmp(void)= 0;

    // 处理列出部门员工菜单项
    virtual void listEmp(void)= 0;

    // 处理列出所有员工菜单项
    virtual void listAllEmp(void)= 0;

    virtual  ~ServiceView() {}
};

#endif // SERVICEVIEW_H

