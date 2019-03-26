#include <iostream>
#include "managerview_console_impl.h"
#include "serviceview_console_impl.h"

using namespace std;

class SuperManager
{
    ManagerView* manager;
    ServiceView* service;
    SuperManager(void)
    {
        manager = new ManagerViewConsoleImpl();
        service = new ServiceViewConsoleImpl();
    }

    SuperManager(const SuperManager&)
    {

    }

    SuperManager& operator=(const SuperManager&)
    {

    }

    ~SuperManager()
    {
        delete manager;
        delete service;
    }

    bool supermanagerload(void)
    {
        clear_scr();
        char password[20] = {};
        cout << "------超管登录------" << endl;
        cout << "密码:";
        get_key_lim(password,20);
        if(0 == strcmp("888888",password))
        {
            show_msg("登录成功",1);
            return true;
        }
        else
        {
            show_msg("登录失败",1);
            return false;
        }
    }

    class AutoRelease
    {
    public:
        AutoRelease()
        {

        }

        ~AutoRelease()
        {
            if(supermanager)
            {
                delete supermanager;
            }
        }
    };

    static SuperManager* supermanager;

    static AutoRelease autoRelease;

public:
    static SuperManager* getSuperManager(void)
    {
        if(NULL == supermanager)
        {
            supermanager = new SuperManager;
        }
        return supermanager;
    }

    void start(void)
    {

        while(1)
        {
            clear_scr();
            cout << "1.管理员菜单" << endl;
            cout << "2.业务菜单" << endl;
            cout << "3.退出" << endl;
            clear_stdin();
            switch(get_cmd('1','3'))
            {
                case '1':if(supermanagerload())
                            manager->menu();
                    break;
                case '2':if(manager->load())
                            service->menu();
                     break;
                case '3':return;
            }
        }
    }
};

SuperManager* SuperManager::supermanager = NULL;
SuperManager::AutoRelease SuperManager::autoRelease;

int main()
{
    SuperManager* supermanager = SuperManager::getSuperManager();
    supermanager->start();
}
