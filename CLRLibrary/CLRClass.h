#pragma once

// MFCClass 클래스가 CString을 사용하므로 1) stdafx.h에 #include <afx.h>를 포함, 2) 프로젝트 속성에서 "공유 DLL에서 MFC 사용" 설정
#include <MFCClass.h>
#include <msclr\marshal_atl.h> // CString과 C#의 String간 변환을 위해 포함

// C#에서만 사용할 것이면 꼭 CPP 파일에 구현부를 작성하지 않고, 헤더 파일에서 모두 작성해도 문제 없습니다.

using namespace System; // C#의 String을 사용하기 위해 포함
using namespace msclr::interop; // CString과 C#의 String간 변환을 위해 포함

// namespace를 추가해줘야 C#에서 사용할 때 관리가 쉽습니다.
namespace CLRLibrary
{
	// 앞에 public ref를 붙어야 합니다.
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

		// C#에서는 delete를 이용해 포인터를 삭제하는 것이 아니라, 자동으로 메모리를 해제해 줍니다. 이를 위한 특별한 finalizer 함수를 정의합니다.
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

		// C#에서는 String 클래스가 문자를 다루는 클래스입니다.
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

