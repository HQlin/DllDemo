// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� DYNAMICDLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// DYNAMICDLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef DYNAMICDLL_EXPORTS
#define DYNAMICDLL_API __declspec(dllexport)
#else
#define DYNAMICDLL_API __declspec(dllimport)
#endif

// �����Ǵ� DynamicDll.dll ������
class DYNAMICDLL_API CDynamicDll {
public:
	CDynamicDll(void);
	// TODO: �ڴ�������ķ�����
};

extern DYNAMICDLL_API int nDynamicDll;

DYNAMICDLL_API int fnDynamicDll(void);
