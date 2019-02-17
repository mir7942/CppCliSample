#pragma once

// MFCClass Ŭ������ CString�� ����ϹǷ� 1) stdafx.h�� #include <afx.h>�� ����, 2) ������Ʈ �Ӽ����� "���� DLL���� MFC ���" ����
#include <MFCClass.h>
#include <msclr\marshal_atl.h> // CString�� C#�� String�� ��ȯ�� ���� ����

// C#������ ����� ���̸� �� CPP ���Ͽ� �����θ� �ۼ����� �ʰ�, ��� ���Ͽ��� ��� �ۼ��ص� ���� �����ϴ�.

using namespace System; // C#�� String�� ����ϱ� ���� ����
using namespace msclr::interop; // CString�� C#�� String�� ��ȯ�� ���� ����

// namespace�� �߰������ C#���� ����� �� ������ �����ϴ�.
namespace CLRLibrary
{
	// �տ� public ref�� �پ�� �մϴ�.
	public ref class CLRClass
	{
	public:
		CLRClass(void)
		{
			m_pMFCClass = new MFCClass();
		}

		~CLRClass(void)
		{
			this->!CLRClass();
		}

		// C#������ delete�� �̿��� �����͸� �����ϴ� ���� �ƴ϶�, �ڵ����� �޸𸮸� ������ �ݴϴ�. �̸� ���� Ư���� finalizer �Լ��� �����մϴ�.
		!CLRClass(void)
		{
			delete m_pMFCClass;
		}

		void SetValue(int value)
		{
			GetMFCClass()->SetValue(value);
		}

		int GetValue()
		{
			return GetMFCClass()->GetValue();
		}

		// C#������ String Ŭ������ ���ڸ� �ٷ�� Ŭ�����Դϴ�.
		void SetText(String ^ text)
		{
			CString strText = marshal_as<CString>(text);

			GetMFCClass()->SetText(strText);
		}

		String ^ GetText(void)
		{
			CString strText = GetMFCClass()->GetText();
			String ^ stringText = marshal_as<String^>(strText);
			
			return stringText;
		}

		String ^ GetOutput()
		{
			CString strOutput = GetMFCClass()->GetOutput();
			String ^ stringOutput = marshal_as<String^>(strOutput);

			return stringOutput;
		}

	private:
		MFCClass * GetMFCClass(void) { return m_pMFCClass; }

	private:
		MFCClass * m_pMFCClass;
	};
}

