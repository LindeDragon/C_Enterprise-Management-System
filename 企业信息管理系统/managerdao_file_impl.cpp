#include "managerdao_file_impl.h"
#include "emis.h"

using namespace std;

vector<Manager>& ManagerDaoFileImpl::load(vector<Manager>& manager)
{
    ifstream in(MANAGER_DAT,ios::in);
    while(true)
    {
        Manager mana;
        if(!in.read((char*)&mana,sizeof(Manager))) break;
        manager.push_back(mana);
    }
    in.close();
    return manager;
}

void ManagerDaoFileImpl::save(vector<Manager>& manager)
{
    ofstream out(MANAGER_DAT,ios::out);
    vector<Manager> :: iterator p = manager.begin();
    for(int i = 0;p != manager.end();i++,p++)
    {
        out.write((char*)&(manager.at(i)),sizeof(Manager));
    }
    out.close();
}
