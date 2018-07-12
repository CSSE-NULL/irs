
#include "OsiManager.h"
#include "OsiStringUtils.h"
using namespace osiris;

OsiManager::Result scan(char* path)
{
    char filename[100] = "code/scripts/Template/configuration.ini";
    OsiManager osi;
    try
    {
        osi.loadConfiguration(filename);//读取图片导入和结果输出相关的配置文件
        osi.showConfiguration();//在命令行中展示相关配置
        osi.run(path);//程序执行入口
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

