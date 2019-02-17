#include "stdafx.h"
#include "MFCClass.h"


MFCClass::MFCClass()
{
}


MFCClass::~MFCClass()
{
}

CString MFCClass::GetOutput(void) const
{
	CString output;
	output.Format(_T("%s%d"), GetText(), GetValue());

	return output;
}