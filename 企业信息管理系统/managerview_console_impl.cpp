#include "managerview_console_impl.h"

using namespace std;

ManagerViewConsoleImpl::ManagerViewConsoleImpl(ManagerService* service):service(service){}

ManagerViewConsoleImpl::ManagerViewConsoleImpl()
{
    service = new ManagerServiceImpl();
}

ManagerViewConsoleImpl::~ManagerViewConsoleImpl()
{
    delete service;
}

void ManagerViewConsoleImpl::menu(void)
{
    while(true)
    {
        clear_scr();
        cout << "1.添加管理员" << endl;
        cout << "2.删除管理员" << endl;
        cout << "3.列出管理员" << endl;
        cout << "4.  退出" << endl;
        switch(get_cmd('1','4'))
        {
            case '1':add();
                break;
            case '2':del();
                break;
            case '3':list();
                break;
            case '4':return;
        }
    }
}

void ManagerViewConsoleImpl::add(void)
{
    char name[20] = {};
    char password[20] = {};
    int id;
    clear_scr();
    cout << "------添加界面------" << endl;
    cout << "用户名:";
    clear_stdin();
    cin >> name;
    cout << "密码:";
    clear_stdin();
    cin >> password;
    id = generator_MgrId();
    Manager* manager = new Manager(id,name,password);
    if(service->addManager(manager))
        show_msg("添加成功",1);
    else
        show_msg("添加失败",1);
}

void ManagerViewConsoleImpl::del(void)
{
    int id;
    clear_scr();
    cout << "------删除界面------" << endl;
    cout << "输入要删除的ID:";
    clear_scr();
    cin >> id;
    if(service->deleteManager(id))
        show_msg("删除成功",1);
    else
        show_msg("删除失败",1);
}

void ManagerViewConsoleImpl::list(void)
{
    clear_scr();
    cout << "------管理员名单------" << endl;
    service->listManager();
    press_anykey();
}

bool ManagerViewConsoleImpl::load()
{
    char name[20] = {};
    char password[20] = {};
    clear_scr();
    cout << "用户名:";
    clear_stdin();
    cin >> name;
    cout << "密码:";
    clear_stdin();
    get_key_lim(password,20);
    if(service->load(name,password))
    {
        clear_scr();
        show_msg("登录成功",1);
        return true;
    }
    else
    {
        clear_scr();
        show_msg("用户名或密码错误",1);
        return false;
    }
}
