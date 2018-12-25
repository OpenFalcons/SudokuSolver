// Sudoku SolverDlg.h : header file
//
#include "BTSButton.h"
#include "MyEdit.h"
#include "Cgenerator.h"
#include "UndoRedo.h"
#include "SudokuSolver.h"
#pragma once


// CSudokuSolverDlg dialog
class CSudokuSolverDlg : public CDialog
{
	
// Construction
public:
	CSudokuSolverDlg(CWnd* pParent = NULL);	// standard constructor
    
	 static bool valid1; 
	 bool matiz[9][9];
	 static CMyEdit buts[9][9];
	 CMyEdit *refs;
     static CMyEdit *focs;
	 void color_numbers(bool val);
	 static void undonow(bool aj);
	 static void prevsol(bool aj);
	 void win_declare(bool aj);
	 static int ulim,rlim;
	 static CStatic *win;
	 static CStatic *msg;
	 static int undo[50][9][9],ucount;
     static int prevsoln[30][9][9],rcount;
	 static Matrix ans,nextans,nexty;
	 static Matrix asolve;
	 static SudokuSolver nextsud;
	 static COLORREF redcolor;
	 static CString cf;
	 static bool sound;
	 void display_ans();
	 CString strFilter;
	enum { IDD = IDD_SUDOKUSOLVER_DIALOG };
    
protected:
	CWnd wnd1;
	virtual void DoDataExchange(CDataExchange* pDX);
    CSize bitmapSize; 
	CBitmap Bacground;
	BITMAP bm;
	Cgenerator objg;
	CString sout,tout;
	char c[5];
	CString cc;
    int incx,incy,gapx,gapy;
	CBrush bluebrush;
    COLORREF bluecolor,green,timec;
	CDC *line;
	CRect rec1;
	CFile fp;
	char s;
	CButton *btn;

	CBTSButton m_btnMyButton,cancel,mins,next,prev,newg,endg,abt,easy,mod,diff,asol,time,cancer,backtrack,one,two,three,four,five,six,seven,eight,nine,savefile,clear,music;
	
	
	 CDialog obj;
	bool edits; 
	void showgame(bool tf);
	int secs;
	char tm[5];
	CRgn regn,reg;
	bool moving,is_game_visible;
	CFont *m_Font1;
	CFont *m_Font2;
// Implementation
protected:
	HICON m_hIcon;
    void show_nums(bool aj);
	// Generated message map functions
	virtual BOOL OnInitDialog();
	bool Get_validity();
	void vis_dif();
	void button_graphics();
	void init_shows();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnHotItemChangeOk(NMHDR *pNMHDR, LRESULT *pResult);
public:
	afx_msg void OnBnSetfocusOk();
public:
	afx_msg void OnBnClickedOk();
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
public:
	afx_msg void OnBnClickedMin();
public:
	afx_msg void OnBnClickedButton1();
	
public:
	afx_msg void OnBnClickedButton3();
public:
	afx_msg void OnBnClickedButton2();
public:
	afx_msg void OnBnClickedNxt();
public:
	afx_msg void OnBnClickedEasy();
public:
	afx_msg void OnBnClickedDiff();
public:
	afx_msg void OnBnClickedMod();
public:
	afx_msg void OnBnClickedAsol();
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
public:
	afx_msg void OnBnClickedPrev();
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
public:
	afx_msg void OnBnClickedCancel();
public:
	afx_msg void OnBnClickedCancer();
public:
	afx_msg void OnBnClickedUndo();
public:
	afx_msg void OnBnClickedRedo();
public:
	afx_msg void OnBnClickedButton4();
public:
	afx_msg void OnBnClickedUndo1();
public:
	afx_msg void OnBnClickedButton6();
public:
	afx_msg void OnBnClickedButton8();
public:
	afx_msg void OnBnClickedRedo1();
public:
	afx_msg void OnBnClickedButton19();
public:
	afx_msg void OnBnClickedButton20();
public:
	afx_msg void OnBnClickedButton21();
public:
	afx_msg void OnBnClickedButton16();
public:
	afx_msg void OnBnClickedButton17();
public:
	afx_msg void OnBnClickedButton18();
public:
	afx_msg void OnBnClickedButton13();
public:
	afx_msg void OnBnClickedButton14();
public:
	afx_msg void OnBnClickedButton15();
public:
	afx_msg void OnBnClickedSave();
public:
	afx_msg void OnBnClickedClear();
public:
	afx_msg void OnBnClickedMusic();
};
