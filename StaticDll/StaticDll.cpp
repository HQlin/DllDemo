// StaticDll.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "StaticDll.h"

// ���ǵ���������һ��ʾ��
STATICDLL_API int nStaticDll=0;

// ���ǵ���������һ��ʾ����
STATICDLL_API int fnStaticDll(void)
{
	return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� StaticDll.h
CStaticDll::CStaticDll()
{
	return;
}

int CStaticDll::GetInt(int i)
{
	return i;
}
