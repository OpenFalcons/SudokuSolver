#include "SudokuSolver.h"

#pragma once


// CMyEdit

class CMyEdit : public CEdit
{
	DECLARE_DYNAMIC(CMyEdit)

public:
	CMyEdit();
	Matrix sudmat;
	SudokuSolver sudPro;
	static int m_matrix[9][9];
	static bool validity,again;
	static int total;
	bool mats[9][9];
	Error err;
	static bool edit;
	static void declare_win(bool aj);
	CString c;
	CWnd *but;
	int posx,posy;
	virtual ~CMyEdit();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnUpdate();
public:
	afx_msg void OnEnSetfocus();
public:
	afx_msg void OnEnChange();
public:
	afx_msg void OnEnKillfocus();
};


