// DynamicDll.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "DynamicDll.h"

//��̬��ʽ����DLL
extern "C" _declspec(dllexport)  int  GetInt()
{
	return fnDynamicDll();
}

// ���ǵ���������һ��ʾ��
DYNAMICDLL_API int nDynamicDll=0;

// ���ǵ���������һ��ʾ����
DYNAMICDLL_API int fnDynamicDll(void)
{
	return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� DynamicDll.h
CDynamicDll::CDynamicDll()
{
	return;
}
