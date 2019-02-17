#pragma once

#ifdef EXPORT_MY_DLL
#define DLL_CLASS __declspec(dllexport)
#else
#define DLL_CLASS __declspec(dllimport)
#endif

class DLL_CLASS MFCClass
{
public:
	MFCClass();
	~MFCClass();

	void SetValue(int value) { m_value = value; }
	int GetValue(void) const { return m_value; }

	void SetText(const CString & text) { m_text = text; }
	CString GetText(void) const { return m_text; }

	CString GetOutput(void) const;

private:
	int m_value;
	CString m_text;
};

