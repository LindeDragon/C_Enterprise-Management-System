#include "managerservice_impl.h"

ManagerServiceImpl::ManagerServiceImpl(ManagerDao* dao,vector<Manager> &m_vecMana):dao(dao),m_vecMana(m_vecMana){}

ManagerServiceImpl::ManagerServiceImpl()
{
    dao = new ManagerDaoFileImpl();
    m_vecMana = dao->load(m_vecMana);
}

ManagerServiceImpl::~ManagerServiceImpl()
{
    dao->save(m_vecMana);
    delete dao;
}

bool ManagerServiceImpl::addManager(Manager* manager)
{
    m_vecMana.push_back(*manager);
    return true;
}

bool ManagerServiceImpl::deleteManager(int id)
{
    vector<Manager> :: iterator p = m_vecMana.begin();
    for(int i = 0;p != m_vecMana.end();i++,p++)
    {
        if(id == m_vecMana.at(i).get_id())
        {
            m_vecMana.erase(p);
            return true;
        }
    }
    return false;
}

void ManagerServiceImpl::listManager(void)
{
    vector<Manager> :: iterator p = m_vecMana.begin();
    for(int i = 0;p != m_vecMana.end();i++,p++)
    {
        cout << m_vecMana[i] << endl;
    }
}

bool ManagerServiceImpl::load(char* name,char* password)
{
    vector<Manager> :: iterator p = m_vecMana.begin();
    for(int i = 0;p != m_vecMana.end();i++,p++)
    {
        if(0 == strcmp(m_vecMana.at(i).name,name) && 0 == strcmp(m_vecMana.at(i).password,password))
            return true;
    }
    return false;
}
