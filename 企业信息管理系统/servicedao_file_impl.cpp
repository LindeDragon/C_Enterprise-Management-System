#include "servicedao_file_impl.h"
#include "emis.h"


// 从文件读取部门及员工信息
vector<Department>& ServiceDaoFileImpl::load(vector<Department>& m_vecDepts)
{
    ifstream in(SERVICES_DAT,ios::in);
    while(1)
    {
        Department dept;
        int num;
        Employee* emp = new Employee();
        in >> dept.id;
        in >> dept.name;
        in >> num;
        if(in.eof())
            break;
        while(num--)
        {
            in >> emp->id;
            in >> emp->name;
            in >> emp->age;
            in >> emp->gender;
            dept.m_vecEmps.push_back(*emp);
        }
        m_vecDepts.push_back(dept);
    }
    in.close();
    return m_vecDepts;
}

// 将部门及员工信息写入文件
void ServiceDaoFileImpl::save(vector<Department>& m_vecDepts)
{
    ofstream out(SERVICES_DAT,ios::out);
    vector<Department> :: iterator p1 = m_vecDepts.begin();
    vector<Employee> :: iterator p2;
    for(int i = 0;p1 != m_vecDepts.end();i++,p1++)
    {
        out << m_vecDepts.at(i) << endl;
        p2 = m_vecDepts[i].m_vecEmps.begin();
        for(int j = 0;p2 != m_vecDepts[i].m_vecEmps.end();j++,p2++)
        {
            out << m_vecDepts[i].m_vecEmps[j] << endl;
        }
    }
    out.close();
}
