#pragma once

enum eMenu 
{
	eInsert = 1,
	eDel,
	ePrint,
	eExit
};

static const int ARRAY_MIN = 0;
static const int ARRAY_MAX = 10;

class CHeapManager
{
public:
	CHeapManager();
	~CHeapManager();

	int m_ReturnParent(int nGetData);	//�θ��ȯ
	int m_ReturnLeft(int nGetData);		//���ʹ�ȯ
	int m_ReturnRight(int nGetData);	//�����ʹ�ȯ

	int m_ReturnPreference(int nGetIndex);	//��, �� �� �켱 ������ ���� �� ��ȯ

	int m_Start();

	void m_Insert();
	void m_Delete();
	void m_Print();

private:
	static int Heap[ARRAY_MAX];

	int m_nDataNumber;	//����� ������ ����
};