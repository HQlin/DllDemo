// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� STATICDLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// STATICDLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef STATICDLL_EXPORTS
#define STATICDLL_API __declspec(dllexport)
#else
#define STATICDLL_API __declspec(dllimport)
#endif

// �����Ǵ� StaticDll.dll ������
class STATICDLL_API CStaticDll {
public:
	CStaticDll(void);
	// TODO: �ڴ�������ķ�����

	int GetInt(int i);
};

extern STATICDLL_API int nStaticDll;

STATICDLL_API int fnStaticDll(void);
