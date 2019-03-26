#ifndef SERVICE_IMPL_H
#define SERVICE_IMPL_H

#include "service.h"
#include "servicedao_file_impl.h"
#include "emis.h"
#include "tools.h"

class ServiceImpl:public Service
{
    // 数据访问对象
    ServiceDao* m_pDao;

    // 部门对象容器
    vector<Department> m_vecDepts;

public:
    ServiceImpl(ServiceDao* m_pDao,vector<Department> m_vecDepts);

    ServiceImpl();

    ~ServiceImpl();

    // 增加部门
    bool addDept(Department* dept);

    // 删除部门
    bool deleteDept(int deptid);

    // 列出部门
    void listDept();

    // 增加员工
    bool addEmp(int id,Employee* emp);

    // 删除员工
    bool deleteEmp(int empid);

    // 修改员工信息
    bool modifyEmp(Employee* emp);

    // 列出部门员工
    void listEmp(int deptid);

    // 列出所有员工
    void listAllEmp(void);

    friend ostream& operator<<(ostream& os,Department* department);

};

#endif // SERVICE_IMPL_H
