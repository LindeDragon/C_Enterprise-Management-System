#include"serviceview_console_impl.h"
#include "tools.h"

ServiceViewConsoleImpl::ServiceViewConsoleImpl(Service* m_pService):m_pService(m_pService){}

ServiceViewConsoleImpl::ServiceViewConsoleImpl()
{
    m_pService = new ServiceImpl();
}

ServiceViewConsoleImpl::~ServiceViewConsoleImpl()
{
    delete m_pService;
}

void ServiceViewConsoleImpl::menu()
{
    while(true)
    {
        clear_scr();
        cout << "1.添加部门" << endl;
        cout << "2.删除部门" << endl;
        cout << "3.列出部门" << endl;
        cout << "4.添加员工" << endl;
        cout << "5.删除员工" << endl;
        cout << "6.修改员工信息" << endl;
        cout << "7.列出部门员工" << endl;
        cout << "8.列出全部员工" << endl;
        cout << "9. 退出" << endl;
        clear_stdin();
        switch(get_cmd('1','9'))
        {
            case '1':addDept();
                break;
            case '2':deleteDept();
                break;
            case '3':listDept();
                break;
            case '4':addEmp();
                break;
            case '5':deleteEmp();
                break;
            case '6':modifyEmp();
                break;
            case '7':listEmp();
                break;
            case '8':listAllEmp();
                break;
            case '9':return;
        }
    }
}

void ServiceViewConsoleImpl::addDept()
{
    char deptname[20] = {};
    int id = 0;
    clear_scr();
    cout << "------新建部门------" << endl;
    cout << "新添部门名称:";
    clear_stdin();
    cin >> deptname;
    id = generator_DeptId();
    Department* dept = new Department(id,deptname);
    if(m_pService->addDept(dept))
        show_msg("新建成功",1);
    else
        show_msg("新建失败",1);
}

void ServiceViewConsoleImpl::deleteDept()
{
    int id = 0;
    clear_scr();
    cout << "------删除部门------" << endl;
    cout << "要删除的部门id:";
    clear_stdin();
    cin >> id;
    if(m_pService->deleteDept(id))
        show_msg("删除成功",1);
    else
        show_msg("部门不存在",1);
}

void ServiceViewConsoleImpl::listDept()
{
    clear_scr();
    cout << "------部门名单------" << endl;
    m_pService->listDept();
    press_anykey();
}

void ServiceViewConsoleImpl::addEmp()
{
    int age;
    int empId;
    int deptId;
    char name[20] = {};
    bool gender = true;
    clear_scr();
    cout << "------添加员工------" << endl;
    cout << "员工姓名:";
    clear_stdin();
    cin >> name;
    cout << "员工性别(1:男，0:女):";
    clear_stdin();
    cin >> gender;
    cout << "年龄:";
    clear_stdin();
    cin >> age;
    cout << "要加入的部门id:";
    clear_stdin();
    cin >> deptId;
    empId = generator_EmpId();
    Employee* emp = new Employee(empId,name,gender,age);
    if(m_pService->addEmp(deptId,emp))
        show_msg("添加成功",1);
    else
        show_msg("部门不存在",1);
}

void ServiceViewConsoleImpl::deleteEmp()
{
    int empId = 0;
    clear_scr();
    cout << "------删除员工------" << endl;
    cout << "要删除的员工id:";
    clear_stdin();
    cin >> empId;
    if(m_pService->deleteEmp(empId))
        show_msg("删除成功",1);
    else
        show_msg("员工不存在",1);
}

void ServiceViewConsoleImpl::modifyEmp()
{
    int age;
    int empId;
    char name[20] = {};
    bool gender = true;
    clear_scr();
    cout << "------修改员工信息------" << endl;
    cout << "要修改的员工id:";
    clear_stdin();
    cin >> empId;
    cout << "员工姓名:";
    clear_stdin();
    cin >> name;
    cout << "员工性别(1:男，0:女):";
    clear_stdin();
    cin >> gender;
    cout << "年龄:";
    clear_stdin();
    cin >> age;
    Employee* emp = new Employee(empId,name,gender,age);
    if(m_pService->modifyEmp(emp))
        show_msg("修改成功",1);
    else
        show_msg("员工不存在",1);
}

void ServiceViewConsoleImpl::listEmp()
{
    int deptId = 0;
    clear_scr();
    cout << "要查询的部门id:";
    clear_stdin();
    cin >> deptId;
    m_pService->listEmp(deptId);
}

void ServiceViewConsoleImpl::listAllEmp()
{
    clear_scr();
    cout << "------全部员工名单------" << endl;
    m_pService->listAllEmp();
    press_anykey();
}
