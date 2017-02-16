DllDemo
===

Dll动态与静态调用模板
---

* 编程语言
    * C++
* 程序说明 
    * 静态调用
        * 导入文件：
            * #include "StaticDll.h"
            * pragma comment(lib, "StaticDll.lib") 
        * 可调用方式：
            * 类（头文件声明）->CStaticDll
            * 全局变量->nStaticDll
            * 全局函数->fnStaticDll()   
    * 动态调用
        * 导入文件：
            * 如需要外部调用自定义类，则导入相关类头文件；
            * 此例无需要外部调用自定义类
        * 可调用方式：
            * 全局函数->GetInt
* 程序设置
   *    
   ![](https://github.com/HQlin/DllDemo/blob/master/img/setting.png "程序设置")
* 程序界面
   *    
   ![](https://github.com/HQlin/DllDemo/blob/master/img/interface.png "程序界面")