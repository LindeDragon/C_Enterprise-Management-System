#include "department.h"

Department::Department(int id,char* name)
{
    this->id = id;
    strcpy(this->name,name);
}

Department::Department(){}

int Department::get_id()
{
    return this->id;
}

void Department::set_id(int id)
{
    this->id = id;
}

char* Department::get_name(void)
{
    return this->name;
}

void Department::set_name(char *name)
{
    strcpy(this->name,name);
}

vector<Employee> Department::get_m_vecEmps()
{
    return this->m_vecEmps;
}

void Department::set_m_vecEmps(vector<Employee> m_vecEmps)
{
    this->m_vecEmps = m_vecEmps;
}

// 删除本部门的员工
bool Department::deleteEmp(int id)
{
    vector<Employee> :: iterator p = m_vecEmps.begin();
    for(int i = 0;p != m_vecEmps.end();i++,p++)
    {
        if(id == m_vecEmps.at(i).id)
        {
            m_vecEmps.erase(p);
            return true;
        }
    }
    return false;
}

// 列出本部门的员工,
void Department::listEmp(void)
{
    vector<Employee> :: iterator p = m_vecEmps.begin();
    for(int i = 0;p != m_vecEmps.end();i++,p++)
    {
        cout << "ID:" << m_vecEmps[i].id << "\t姓名:" << m_vecEmps[i].name << "\t年龄:" << m_vecEmps[i].age << "\t性别:" << (m_vecEmps[i].gender?"男":"女") << endl;
    }
}

// 修改本部门的员工信息
bool Department::modifyEmp(Employee* emp)
{
    vector<Employee> :: iterator p = m_vecEmps.begin();
    for(int i = 0;p != m_vecEmps.end();i++,p++)
    {
        if(emp->get_id() == m_vecEmps.at(i).id)
        {
            m_vecEmps.at(i) = *emp;
            return true;
        }
    }
    return false;
}

ostream& operator<<(ostream& os,Department& department)
{
    return os << department.id << " " << department.name << " " << department.m_vecEmps.size();
}
