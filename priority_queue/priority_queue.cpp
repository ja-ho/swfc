#include <iostream>
#include "priority_queue.h"
using namespace std;

int CHeapManager::Heap[ARRAY_MAX];

CHeapManager::CHeapManager()
{
	cout << "CHeapManager ������" << endl;
	m_nDataNumber = 0;
}

CHeapManager::~CHeapManager()
{
	cout << "CHeapManager �Ҹ���" << endl;
}

int CHeapManager::m_Start()
{
	int nChoice = 0;
	
	while (true) {
		std::cout << "1. ����, 2. ����, 3. ���, 4. ����" << endl;
		cin >> nChoice;
		
		switch (nChoice)
		{
		case eInsert:
		{
			m_Insert();
			break;
		}
		case eDel:
		{
			m_Delete();
			break;
		}
		case ePrint:
		{
			m_Print();
			break;
		}
		case eExit:
		{
			return eExit;
		}
		default:
			break;
		}
	}
}

int CHeapManager::m_ReturnParent(int nGetData)
{
	return (nGetData / 2);
}

int CHeapManager::m_ReturnLeft(int nGetData)
{
	return (nGetData * 2);
}

int CHeapManager::m_ReturnRight(int nGetData)
{
	return (nGetData * 2) + 1;
}

int CHeapManager::m_ReturnPreference(int nGetIndex)
{//�켱���� ��� ��ȯ
	//���� ���� Ʈ�� Ư���� ������ �����ʺ��� ���� ���� ����.(���ʺ��� ä������.)
	if (m_ReturnLeft(nGetIndex) > m_nDataNumber) {
		//���� ��忡 �ڽ��� �������� ������
		//�ڽ��� ����.
		return NULL;
	}
	else if (m_ReturnLeft(nGetIndex) == m_nDataNumber) {
		return m_ReturnLeft(nGetIndex);
	}
	else {
		if (Heap[m_ReturnLeft(nGetIndex)] > Heap[m_ReturnRight(nGetIndex)]) {
			return m_ReturnRight(nGetIndex);
		}
		else
			return m_ReturnLeft(nGetIndex);
	}
}


void CHeapManager::m_Insert()
{
	if (ARRAY_MAX <= m_nDataNumber) {
		cout << "���� á���ϴ�" << endl;
	}
	else
	{
		int nIndex = m_nDataNumber + 1;
		int nData;
		cout << "������ �Է��� �ּ���." << endl;
		cin >> nData;
		//������ ���ڰ� �������� �켱������ ���ٴ� ����

		while (nIndex != 1) {
			//�� ��� ��ġ�� ���� ������ �������� while �ݺ�
			if (Heap[m_ReturnParent(nIndex)] > nData) {
				Heap[nIndex] = Heap[m_ReturnParent(nIndex)];
				nIndex = m_ReturnParent(nIndex);
			}
			else
				break;
		}
		Heap[nIndex] = nData;
		m_nDataNumber++;
	}
}

void CHeapManager::m_Delete()
{
	if (ARRAY_MIN >= m_nDataNumber) {
		cout << "������ϴ�" << endl;
	}
	else
	{
		int nLastParentIndex = ARRAY_MIN + 1;
		int nLastNodeData = Heap[m_nDataNumber];
		int	nChildIndex;

		while(nChildIndex = m_ReturnPreference(nLastParentIndex)) {
			if (nLastNodeData <= Heap[nChildIndex]) {
				break;
			}
			else
			{
				Heap[nLastParentIndex] = Heap[nChildIndex];
				nLastParentIndex = nChildIndex;
			}
		}

		Heap[nLastParentIndex] = nLastNodeData;
		m_nDataNumber--;	
	}
}

void CHeapManager::m_Print()
{
	cout << m_nDataNumber << "���� �����͸� ���� ��" << endl;

	for (int i = 1; i <= m_nDataNumber; i++) {
		cout << i << "��° : " << Heap[i] << endl;
	}

}