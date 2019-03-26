#include "tools.h"
#include "emis.h"

// 清屏
void clear_scr(void)
{
    system("clear");
}

// 清理输入缓冲区
void clear_stdin(void)
{
    stdin->_IO_read_ptr = stdin->_IO_read_end;
}

// get_0to9()
char get_0to9(void)
{
    char ch = 0;
    while(1)
    {
        ch = getch();
        if((ch >= '0' && ch <= '9' )|| ch == '.' || ch == '\n' || ch == 127)
            break;
    }
    return ch;
}

// 输入字符限制,str为存放输入数据的数组,size为存放上限
char* get_lim(char* str ,int size)
{
    clear_stdin();
    char ch;
    int cnt = 0;
    while(1)
    {
        // 判断是否为空字符
        if((ch = get_0to9()) == '\n' && cnt == 0)
        {
            return NULL;
        }

        // 判断是否按下回车
        if(ch  == '\n')
        {
            // 最后一个输入'\0'作为结束
            str[cnt] = '\0';

            puts("");
            //返回得到的数组
            return str;
        }

        // 判断是否按下退格
        if(ch == 127)
        {
            // 判断当前是否已经有字符了
            if(cnt > 0)
            {

                //　下标减一
                cnt--;
                printf("\b \b");
            }
            continue;
        }

        // 判断是否到达上限
        if(cnt == size - 1)
        {
            continue;
        }

        // 将输入的字符放入数组中
        str[cnt++] = ch;

        // 打印字符
        printf("%c",ch);
    }
}

// 密码保密输入
char* get_key_lim(char* str ,int size)
{
    clear_stdin();
    char ch;
    int cnt = 0;
    while(1)
    {
        // 判断是否为空字符
        if((ch = getch()) == '\n' && cnt == 0)
        {
            return NULL;
        }
        // 判断是否按下回车
        if(ch == '\n')
        {
            // 最后一个输入'\0'作为结束
            str[cnt] = '\0';
            puts("");
            //返回得到的数组
            return str;
        }

        // 判断是否按下退格
        if(ch == 127)
        {
            // 判断当前是否已经有字符了
            if(cnt > 0)
            {

                //　下标减一
                cnt--;
                printf("\b \b");
            }
            continue;
        }

        // 判断是否到达上限
        if(cnt == size - 1)
        {
            continue;
        }

        // 将输入的字符放入数组中
        str[cnt++] = ch;

        // 打印字符
        printf("*");
    }
}


//显示提示信息
void show_msg(char* msg,size_t sec)
{
    printf("\33[;36m");
    printf("*** %s *** \n",msg);
    sleep(sec);
    printf("\33[0m");
}

//获取指令
char get_cmd(char start,char end)
{
    clear_stdin();

    printf("请输入指令:");
    while(true)
    {
        char val = getch();
        if(val >= start && val <= end)
        {
            printf("%c\n",val);
            return val;
        }
    }
}


void press_anykey(void)
{
    clear_stdin();
    puts("");
    puts("-------按任意键返回-------");
    getch();
}

char y_or_n(void)
{
    char ch;
    while(1)
    {
        ch = getch();
        if(ch == 'n' || ch == 'N' || ch == 'y' || ch == 'Y')
            break;
    }
    return ch;
}

int generator_MgrId()
{
    if(0 > access(ID_DAT,0))
    {
        char str[40] = {};
        // 不存在时,创建文件
        fstream fs(ID_DAT,ios::out);
        int nownum = MgrId + 1;
        sprintf(str,"MgrId:%d\nDeptId:%d\nEmpId:%d",nownum,DeptId,EmpId);
        fs.write(str,sizeof(str));
        fs.close();
        return MgrId;
    }
    else
    {
        int M_id,D_id,E_id,back_num;
        char str[40] = {};
        fstream fs(ID_DAT,ios::out|ios::in);
        fs.read(str,sizeof(str));
        sscanf(str,"MgrId:%d\nDeptId:%d\nEmpId:%d",&M_id,&D_id,&E_id);
        back_num = M_id++;
        sprintf(str,"MgrId:%d\nDeptId:%d\nEmpId:%d",M_id,D_id,E_id);
        fs.seekg(0);
        fs.write(str,sizeof(str));
        fs.close();
        return back_num;
    }
}

int generator_DeptId()
{
    if(0 > access(ID_DAT,0))
    {
        char str[40] = {};
        // 不存在时,创建文件
        fstream fs(ID_DAT,ios::out);
        int nownum = DeptId + 1;
        sprintf(str,"MgrId:%d\nDeptId:%d\nEmpId:%d",MgrId,nownum,EmpId);
        fs.write(str,sizeof(str));
        fs.close();
        cout <<  "1" <<DeptId << endl;
        return DeptId;
    }
    else
    {
        int M_id,D_id,E_id,back_num;
        char str[40] = {};
        fstream fs(ID_DAT,ios::out|ios::in);
        fs.read(str,sizeof(str));
        sscanf(str,"MgrId:%d\nDeptId:%d\nEmpId:%d",&M_id,&D_id,&E_id);
        back_num = D_id++;
        sprintf(str,"MgrId:%d\nDeptId:%d\nEmpId:%d",M_id,D_id,E_id);
        fs.seekg(0);
        fs.write(str,sizeof(str));
        fs.close();
        return back_num;
    }
}

int generator_EmpId()
{
    if(0 > access(ID_DAT,0))
    {
        char str[40] = {};
        // 不存在时,创建文件
        fstream fs(ID_DAT,ios::out);
        int nownum = EmpId + 1;
        sprintf(str,"MgrId:%d\nDeptId:%d\nEmpId:%d",MgrId,DeptId,nownum);
        fs.write(str,sizeof(str));
        fs.close();
        return EmpId;
    }
    else
    {
        int M_id,D_id,E_id,back_num;
        char str[40] = {};
        fstream fs(ID_DAT,ios::out|ios::in);
        fs.read(str,sizeof(str));
        sscanf(str,"MgrId:%d\nDeptId:%d\nEmpId:%d",&M_id,&D_id,&E_id);
        back_num = E_id++;
        sprintf(str,"MgrId:%d\nDeptId:%d\nEmpId:%d",M_id,D_id,E_id);
        fs.seekg(0);
        fs.write(str,sizeof(str));
        fs.close();
        return back_num;
    }
}

