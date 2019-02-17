C++/CLI 샘플 코드
================
솔루션 구성
----------
MFCLibrary 프로젝트
- Visual C++의 MFC DLL로 작성
- MFCClass.h/cpp 파일 참고: 일반적인 MFC 클래스

CLRLibrary 프로젝트
- Visual C++의 CLR 클래스 라이브러리
- CLRClass.h/cpp 파일 참고
  - C++/CLI를 이용해 C++ 클래스를 래핑하는 방법을 보여줌
- stdafx.h
  - CString을 이용하기 위해 #include <afx.h> 포함

WindowsFormsApp 프로젝트
- C#의 Windows Form 프로젝트
- 테스트용 프로젝트
- CLRClass를 이용할 때 DLL 파일이 같은 폴더에 있거나 PATH로 지정되어 있어야 함. MFC DLL 파일들도 동일
