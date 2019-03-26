#ifndef SERVICEVIEW_CONSOLE_IMPL_H
#define SERVICEVIEW_CONSOLE_IMPL_H

#include "serviceview.h"

class ServiceViewConsoleImpl:public ServiceView
{
    // 业务逻辑对象
    Service* m_pService;
public:
    ServiceViewConsoleImpl(Service* m_pService);

    ServiceViewConsoleImpl();

    ~ServiceViewConsoleImpl();

    // 通过控制台显示运营管理子菜单
    void menu(void);

    // 通过控制台处理增加部门菜单项
    void addDept();

    // 通过控制台处理删除部门菜单项
    void deleteDept(void);

    // 通过控制台处理列出部门菜单项
    void listDept();

    // 通过控制台处理增加员工菜单项
    void addEmp();

    // 通过控制台处理删除员工菜单项
    void deleteEmp();

    // 通过控制台处理修改员工信息菜单项
    void modifyEmp();

    // 通过控制台处理列出部门员工菜单项
    void listEmp();

    // 通过控制台处理列出所有员工菜单项
    void listAllEmp(void);
};

#endif // SERVICEVIEW_CONSOLE_IMPL_H
