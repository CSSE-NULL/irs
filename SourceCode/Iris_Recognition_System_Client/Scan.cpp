
#include "OsiManager.h"
#include "OsiStringUtils.h"
using namespace osiris;

OsiManager::Result scan(char* path)
{
    char filename[100] = "code/scripts/Template/configuration.ini";
    OsiManager osi;
    try
    {
        osi.loadConfiguration(filename);//��ȡͼƬ����ͽ�������ص������ļ�
        osi.showConfiguration();//����������չʾ�������
        osi.run(path);//����ִ�����
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    //system("pause");
    OsiStringUtils osu;

    char* fname = strrchr(path, '\\');
    std::string short_name = osu.extractFileName(fname + 1);

    return osi.getResult(short_name.c_str());

}

