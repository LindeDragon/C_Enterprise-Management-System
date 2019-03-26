#include "service_impl.h"

ServiceImpl::ServiceImpl(ServiceDao *m_pDao, vector<Department> m_vecDepts):m_pDao(m_pDao),m_vecDepts(m_vecDepts){}

ServiceImpl::ServiceImpl()
{
    m_pDao = new ServiceDaoFileImpl();
    m_vecDepts = m_pDao->load(m_vecDepts);
}

ServiceImpl::~ServiceImpl()
{
    m_pDao->save(m_vecDepts);
    delete m_pDao;
}

bool ServiceImpl::addDept(Department* dept)
{
    m_vecDepts.push_back(*dept);
    return true;
}

bool ServiceImpl::deleteDept(int deptid)
{
    vector<Department> :: iterator p = m_vecDepts.begin();
    for(int i = 0;p != m_vecDepts.end();i++,p++)
    {
        if(deptid == m_vecDepts.at(i).id)
        {
            m_vecDepts.erase(p);
            return true;
        }
    }
    return false;
}

void ServiceImpl::listDept()
{
    vector<Department> :: iterator p = m_vecDepts.begin();
    for(int i = 0;p != m_vecDepts.end();i++,p++)
    {
        cout << "部门ID:" << m_vecDepts[i].id << "\t部门名称:" << m_vecDepts[i].name << "\t部门人数:" << m_vecDepts[i].m_vecEmps.size() << endl;
    }
}

bool ServiceImpl::addEmp(int id, Employee *emp)
{
    vector<Department> :: iterator p = m_vecDepts.begin();
    for(int i = 0;p != m_vecDepts.end();i++,p++)
    {
        if(id == m_vecDepts.at(i).id)
        {
            (m_vecDepts[i].m_vecEmps).push_back(*emp);
            return true;
        }
    }
    return false;
}

bool ServiceImpl::deleteEmp(int empid)
{
    vector<Department> :: iterator p = m_vecDepts.begin();
    for(int i = 0;p != m_vecDepts.end();i++,p++)
    {
        if(m_vecDepts.at(i).deleteEmp(empid))
            return true;
    }
    return false;
}

bool ServiceImpl::modifyEmp(Employee *emp)
{
    vector<Department> :: iterator p = m_vecDepts.begin();
    for(int i = 0;p != m_vecDepts.end();i++,p++)
    {
        if(m_vecDepts.at(i).modifyEmp(emp))
            return true;
    }
    return false;
}

void ServiceImpl::listEmp(int deptid)
{
    vector<Department> :: iterator p = m_vecDepts.begin();
    for(int i = 0;p != m_vecDepts.end();i++,p++)
    {
        if(deptid == m_vecDepts.at(i).get_id())
        {
            m_vecDepts.at(i).listEmp();
            press_anykey();
            return;
        }
    }
    cout << "部门不存在" << endl;
    press_anykey();
}

void ServiceImpl::listAllEmp()
{
    vector<Department> :: iterator p = m_vecDepts.begin();
    Department d;
    for(int i = 0;p != m_vecDepts.end();i++,p++)
    {
       cout << "部门ID:" << m_vecDepts[i].id << "\t部门名称:" << m_vecDepts[i].name << "\t部门人数:" << m_vecDepts[i].m_vecEmps.size() << endl;
        m_vecDepts.at(i).listEmp();
        cout << endl;
    }
}
