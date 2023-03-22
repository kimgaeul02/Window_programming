// CString_class.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include "framework.h"
#include "Console2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 유일한 애플리케이션 개체입니다.

CWinApp theApp;

using namespace std;

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // MFC를 초기화합니다. 초기화하지 못한 경우 오류를 인쇄합니다.
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: 여기에 애플리케이션 동작을 코딩합니다.
            wprintf(L"심각한 오류: MFC 초기화 실패\n");
            nRetCode = 1;
        }
        else
        {
            // TODO: 여기에 애플리케이션 동작을 코딩합니다.
            _tsetlocale(LC_ALL, _T(""));    // 유니코드 한국어 출력에 필요
            CString str1;
            str1 = _T("안녕하세요.");       // 문자열을 직접 대입한다.
            CString str2(_T("오늘은"));     // 문자열을 생성자 인자로 전달한다.
            CString str3(str2);             // CString 객체를 생성자 인자로 전달한다.
            // CStirng 객체와 문자열을 붙인다.
            CString str4 = str1 + _T(" ") + str2 + _T(" 즐거운 날입니다.");
            _tprintf(_T("%s\n"), (LPCTSTR)str1);
            _tprintf(_T("%s\n"), (LPCTSTR)str2);
            _tprintf(_T("%s\n"), (LPCTSTR)str3);
            _tprintf(_T("%s\n"), (LPCTSTR)str4);
            // + = 연산자를 이용하여 기존 문자열에 새로운 문자열을 덧붙인다.
            str4 += _T(" 하하하");
            _tprintf(_T("%s\n"), (LPCTSTR)str4);
        }
    }
    else
    {
        // TODO: 오류 코드를 필요에 따라 수정합니다.
        wprintf(L"심각한 오류: GetModuleHandle 실패\n");
        nRetCode = 1;
    }

    return nRetCode;
}
