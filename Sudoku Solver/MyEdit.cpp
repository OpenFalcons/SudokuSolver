// MyEdit.cpp : implementation file
//
#include "stdafx.h"
#include "Sudoku Solver.h"
#include "MyEdit.h"
#include "Sudoku SolverDlg.h"
#include "Cgenerator.h"
#include "mmsystem.h"
#pragma comment(lib,"Winmm")
bool CMyEdit::validity;
bool CMyEdit::edit;
// CMyEdit
bool CSudokuSolverDlg::valid1;
int CMyEdit::m_matrix[9][9];
int CMyEdit::total;
Error col;
IMPLEMENT_DYNAMIC(CMyEdit, CEdit)

CMyEdit::CMyEdit()
{
CMyEdit::validity=false;
total=0;

}

CMyEdit::~CMyEdit()
{
}


BEGIN_MESSAGE_MAP(CMyEdit, CEdit)
	ON_CONTROL_REFLECT(EN_UPDATE, &CMyEdit::OnEnUpdate)
	ON_CONTROL_REFLECT(EN_SETFOCUS, &CMyEdit::OnEnSetfocus)
	ON_CONTROL_REFLECT(EN_CHANGE, &CMyEdit::OnEnChange)
	ON_CONTROL_REFLECT(EN_KILLFOCUS, &CMyEdit::OnEnKillfocus)
END_MESSAGE_MAP()

void CMyEdit::OnEnUpdate()
{
	edit=true;
	total=0;
	if(CMyEdit::validity){
    
	for(int i=0;i<9;i++)
	for(int j=0;j<9;j++)
	{
		CSudokuSolverDlg::buts[i][j].GetWindowTextW(c);
		CSudokuSolverDlg::buts[i][j].Invalidate(1);
		CMyEdit::m_matrix[i][j]=_wtoi(c);
		total+=CMyEdit::m_matrix[i][j];
		if(total==405)
		declare_win(true);
	}   
       
	
	CSudokuSolverDlg::asolve.setMatrix(CMyEdit::m_matrix); 
	Error e=CSudokuSolverDlg::asolve.getError();
	if(!sudmat.setMatrix(CMyEdit::m_matrix))
	{
		if(CSudokuSolverDlg::sound)
	PlaySound(MAKEINTRESOURCE(IDR_WAVE1),AfxGetInstanceHandle(),SND_ASYNC |SND_RESOURCE);
	CString errh(e.getErrorReport().c_str());
	CSudokuSolverDlg::msg->SetWindowTextW(errh);
	CSudokuSolverDlg::redcolor=RGB(255,0,0);
	}
	else
	{
	CSudokuSolverDlg::msg->SetWindowTextW(_T(""));
	CSudokuSolverDlg::redcolor=RGB(0,255,0);
	}
    
	CSudokuSolverDlg::undonow(false);
	e.~Error();
	}
}

void CMyEdit::OnEnSetfocus()
{   
	CSudokuSolverDlg::focs=reinterpret_cast<CMyEdit*>(this);
}

void CMyEdit::OnEnChange()
{  
}
void CMyEdit::declare_win(bool aj)
{
CSudokuSolverDlg::msg->ShowWindow(SW_HIDE);
for(int i=0;i<9;i++)
for(int j=0;j<9;j++)
CSudokuSolverDlg::buts[i][j].ShowWindow(SW_HIDE);
CSudokuSolverDlg::win->ShowWindow(SW_SHOW);
CSudokuSolverDlg::win->SetWindowTextW(_T("CONGRATULATIONS\nYOU WON"));


}

void CMyEdit::OnEnKillfocus()
{
	/*CSudokuSolverDlg::focs=reinterpret_cast<CMyEdit *>(this);
	
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
		{
	   if((CSudokuSolverDlg::buts[i][j].GetDlgCtrlID()==CSudokuSolverDlg::focs->GetDlgCtrlID())&&mats[i][j])
	   {CSudokuSolverDlg::redcolor=RGB(255,0,0);
	    CSudokuSolverDlg::buts[i][j].RedrawWindow();
	    CSudokuSolverDlg::msg->SetWindowTextW(_T("culprit found"));
	   }
	   else
	   CSudokuSolverDlg::redcolor=RGB(0,255,0);
	}
	*/
}
