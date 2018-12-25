// Sudoku SolverDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Sudoku Solver.h"
#include "Sudoku SolverDlg.h"
#include "BTSButton.h"
#include "Cgenerator.h"
#include "MyEdit.h"
#include "mmsystem.h"
#pragma comment(lib,"Winmm")
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
CMyEdit CSudokuSolverDlg::buts[9][9];
int CSudokuSolverDlg::undo[50][9][9];
bool CSudokuSolverDlg::sound;
int CSudokuSolverDlg::prevsoln[30][9][9];
int CSudokuSolverDlg::ucount;
int CSudokuSolverDlg::rcount;
CStatic *CSudokuSolverDlg::win;
CStatic *CSudokuSolverDlg::msg;
CString CSudokuSolverDlg::cf;
Matrix CSudokuSolverDlg::asolve;
Matrix CSudokuSolverDlg::nextans;
Matrix CSudokuSolverDlg::ans;
SudokuSolver CSudokuSolverDlg::nextsud;
COLORREF CSudokuSolverDlg::redcolor;
CMyEdit *CSudokuSolverDlg::focs;
CSudokuSolverDlg::CSudokuSolverDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSudokuSolverDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CSudokuSolverDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSudokuSolverDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_NOTIFY(BCN_HOTITEMCHANGE, IDOK, &CSudokuSolverDlg::OnBnHotItemChangeOk)
	ON_BN_SETFOCUS(IDOK, &CSudokuSolverDlg::OnBnSetfocusOk)
	ON_BN_CLICKED(IDOK, &CSudokuSolverDlg::OnBnClickedOk)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDMIN, &CSudokuSolverDlg::OnBnClickedMin)
	ON_BN_CLICKED(IDC_BUTTON1, &CSudokuSolverDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CSudokuSolverDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CSudokuSolverDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_NXT, &CSudokuSolverDlg::OnBnClickedNxt)
	ON_BN_CLICKED(IDC_EASY, &CSudokuSolverDlg::OnBnClickedEasy)
	ON_BN_CLICKED(IDC_DIFF, &CSudokuSolverDlg::OnBnClickedDiff)
	ON_BN_CLICKED(IDC_MOD, &CSudokuSolverDlg::OnBnClickedMod)
	ON_BN_CLICKED(IDC_ASOL, &CSudokuSolverDlg::OnBnClickedAsol)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_PREV, &CSudokuSolverDlg::OnBnClickedPrev)
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDCANCEL, &CSudokuSolverDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_CANCER, &CSudokuSolverDlg::OnBnClickedCancer)
	ON_BN_CLICKED(IDC_UNDO1, &CSudokuSolverDlg::OnBnClickedUndo1)
	ON_BN_CLICKED(IDC_BUTTON19, &CSudokuSolverDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CSudokuSolverDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON21, &CSudokuSolverDlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON16, &CSudokuSolverDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CSudokuSolverDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CSudokuSolverDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON13, &CSudokuSolverDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CSudokuSolverDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CSudokuSolverDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_SAVE, &CSudokuSolverDlg::OnBnClickedSave)
	ON_BN_CLICKED(IDC_CLEAR, &CSudokuSolverDlg::OnBnClickedClear)
	ON_BN_CLICKED(IDC_MUSIC, &CSudokuSolverDlg::OnBnClickedMusic)
END_MESSAGE_MAP()


// CSudokuSolverDlg message handlers

BOOL CSudokuSolverDlg::OnInitDialog()
{  
	    edits=false;
		is_game_visible=false;
		Bacground.LoadBitmapW(IDB_BITMAP13);
		Bacground.GetBitmap(&bm);
		bitmapSize = CSize(bm.bmWidth, bm.bmHeight);
		Invalidate(1);
	    CDialog::OnInitDialog();
        button_graphics();        
		m_Font1=new CFont();
		m_Font2=new CFont();
        m_Font1->CreatePointFont(170,_T("timesnewroman"));
		m_Font2->CreatePointFont(140,_T("ariel bold"));
		GetDlgItem(IDC_TIME)->SetFont(m_Font1);
		incx=15;incy=0;
	gapy=160;gapx=175;
	for(int i=0;i<9;i++)
	{for(int j=0;j<9;j++)
		{incx+=20;
	    if(j==3||j==6)
		gapx+=10;
		else
			gapx+=5;
		CSudokuSolverDlg::buts[i][j].Create(WS_CHILD|ES_NUMBER|WS_VISIBLE|ES_CENTER,CRect(gapx+incx,gapy+incy,gapx+incx+20,gapy+incy+20),this,0x100);
	    
	}
	incy+=20;
	incx=20;
	gapx=170;
	if(i==2||i==5)
		gapy+=10;
	else 
		gapy+=5;
	}
    SetWindowPos( NULL, 0,100,650,500,SWP_NOMOVE|SWP_NOOWNERZORDER );
    regn.CreateEllipticRgn(0,100,650,500 );
    SetWindowRgn(regn,TRUE);
    bluecolor=RGB(0,45,5); 
	redcolor=RGB(255,0,0);
    bluebrush.CreateSolidBrush(bluecolor);
	green=RGB(0,255,0);
	timec=RGB(0,255,0);
	init_shows();
	win=(CStatic *)GetDlgItem(IDC_TIME3);
	msg=(CStatic *)GetDlgItem(IDC_TIME2);
    showgame(false);
	vis_dif();
	SetClassLong(m_hWnd,GCL_HCURSOR,(LONG)LoadCursor(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDC_CURSOR1)));
	SetClassLong(GetDlgItem(IDOK)->m_hWnd,GCL_HCURSOR,(LONG)LoadCursor(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDC_CURSOR1)));
	show_nums(false);
	sound=true;
	return TRUE;  // return TRUE  unless you set the focus to a control
}
void CSudokuSolverDlg::button_graphics()
{
		m_btnMyButton.Id_Assigner(IDOK);
		cancel.Id_Assigner(IDCANCEL);
		mins.Id_Assigner(IDMIN);
		next.Id_Assigner(IDC_NXT);
		prev.Id_Assigner(IDC_PREV);
		newg.Id_Assigner(IDC_BUTTON1);
		endg.Id_Assigner(IDC_BUTTON2);
		abt.Id_Assigner(IDC_BUTTON3);
		mod.Id_Assigner(IDC_MOD);
		easy.Id_Assigner(IDC_EASY);
		diff.Id_Assigner(IDC_DIFF);
		asol.Id_Assigner(IDC_ASOL);
		cancer.Id_Assigner(IDC_CANCER);
		backtrack.Id_Assigner(IDC_UNDO1);
		one.Id_Assigner(IDC_BUTTON19);
		one.SubclassDlgItem(IDC_BUTTON19,this);
        two.Id_Assigner(IDC_BUTTON20);
		music.Id_Assigner(IDC_MUSIC);
		clear.Id_Assigner(IDC_CLEAR);
		clear.SubclassDlgItem(IDC_CLEAR,this);
		music.SubclassDlgItem(IDC_MUSIC,this);
		two.SubclassDlgItem(IDC_BUTTON20,this);
		three.Id_Assigner(IDC_BUTTON21);
		three.SubclassDlgItem(IDC_BUTTON21,this);
		four.Id_Assigner(IDC_BUTTON16);
		four.SubclassDlgItem(IDC_BUTTON16,this);
		five.Id_Assigner(IDC_BUTTON17);
		five.SubclassDlgItem(IDC_BUTTON17,this);
		six.Id_Assigner(IDC_BUTTON18);
		six.SubclassDlgItem(IDC_BUTTON18,this);
		seven.Id_Assigner(IDC_BUTTON13);
		seven.SubclassDlgItem(IDC_BUTTON13,this);
		eight.Id_Assigner(IDC_BUTTON14);
		eight.SubclassDlgItem(IDC_BUTTON14,this);
		nine.Id_Assigner(IDC_BUTTON15);
		savefile.Id_Assigner(IDC_SAVE);
		savefile.SubclassDlgItem(IDC_SAVE,this);
		nine.SubclassDlgItem(IDC_BUTTON15,this);
		backtrack.SubclassDlgItem(IDC_UNDO1,this);
		m_btnMyButton.SubclassDlgItem(IDOK,this);
		cancer.SubclassDlgItem(IDC_CANCER,this);
		next.SubclassDlgItem(IDC_NXT,this);
		prev.SubclassDlgItem(IDC_PREV,this);
		cancel.SubclassDlgItem(IDCANCEL,this);
		mins.SubclassDlgItem(IDMIN,this);
		newg.SubclassDlgItem(IDC_BUTTON1,this);
		endg.SubclassDlgItem(IDC_BUTTON2,this);
		abt.SubclassDlgItem(IDC_BUTTON3,this);
		easy.SubclassDlgItem(IDC_EASY,this);
		mod.SubclassDlgItem(IDC_MOD,this);
		diff.SubclassDlgItem(IDC_DIFF,this);
		asol.SubclassDlgItem(IDC_ASOL,this);
}
void CSudokuSolverDlg::init_shows()
{
	
	GetDlgItem(IDOK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_NXT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PREV)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TIME)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CANCER)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_UNDO1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TIME3)->ShowWindow(SW_HIDE);
}
void CSudokuSolverDlg::show_nums(bool aj)
{
if(!aj)
{
GetDlgItem(IDC_BUTTON13)->ShowWindow(SW_HIDE);
GetDlgItem(IDC_BUTTON14)->ShowWindow(SW_HIDE);
GetDlgItem(IDC_BUTTON15)->ShowWindow(SW_HIDE);
GetDlgItem(IDC_BUTTON16)->ShowWindow(SW_HIDE);
GetDlgItem(IDC_BUTTON17)->ShowWindow(SW_HIDE);
GetDlgItem(IDC_BUTTON18)->ShowWindow(SW_HIDE);
GetDlgItem(IDC_BUTTON19)->ShowWindow(SW_HIDE);
GetDlgItem(IDC_BUTTON20)->ShowWindow(SW_HIDE);
GetDlgItem(IDC_BUTTON21)->ShowWindow(SW_HIDE);
GetDlgItem(IDC_CLEAR)->ShowWindow(SW_HIDE);
GetDlgItem(IDC_UNDO1)->ShowWindow(SW_HIDE);
}
else
{
GetDlgItem(IDC_UNDO1)->ShowWindow(SW_SHOW);
GetDlgItem(IDC_BUTTON13)->ShowWindow(SW_SHOW);
GetDlgItem(IDC_BUTTON14)->ShowWindow(SW_SHOW);
GetDlgItem(IDC_BUTTON15)->ShowWindow(SW_SHOW);
GetDlgItem(IDC_BUTTON16)->ShowWindow(SW_SHOW);
GetDlgItem(IDC_BUTTON17)->ShowWindow(SW_SHOW);
GetDlgItem(IDC_BUTTON18)->ShowWindow(SW_SHOW);
GetDlgItem(IDC_BUTTON19)->ShowWindow(SW_SHOW);
GetDlgItem(IDC_BUTTON20)->ShowWindow(SW_SHOW);
GetDlgItem(IDC_BUTTON21)->ShowWindow(SW_SHOW);
GetDlgItem(IDC_CLEAR)->ShowWindow(SW_SHOW);
}
}
void CSudokuSolverDlg::showgame(bool tf)
{
for(int k=0;k<9;k++)
	for(int m=0;m<9;m++)	
	{Cgenerator::gen[k][m]=0;
	CSudokuSolverDlg::buts[k][m].EnableWindow(true);}
if(!tf)
is_game_visible=false;
if(tf)
{
is_game_visible=true;
for(int i=0;i<9;i++)
for(int j=0;j<9;j++)
{
CSudokuSolverDlg::buts[i][j].ShowWindow(SW_SHOW);
CSudokuSolverDlg::buts[i][j].SetWindowTextW(_T(""));
CSudokuSolverDlg::buts[i][j].SetFont(m_Font2);

}
GetDlgItem(IDC_SAVE)->ShowWindow(SW_SHOW);
GetDlgItem(IDC_TIME2)->ShowWindow(SW_SHOW);
GetDlgItem(IDC_MUSIC)->ShowWindow(SW_SHOW);
}
else
{for(int i=0;i<9;i++)
for(int j=0;j<9;j++)
CSudokuSolverDlg::buts[i][j].ShowWindow(SW_HIDE);
GetDlgItem(IDC_TIME2)->ShowWindow(SW_HIDE);
GetDlgItem(IDC_SAVE)->ShowWindow(SW_HIDE);
GetDlgItem(IDC_MUSIC)->ShowWindow(SW_HIDE);
}
}
void CSudokuSolverDlg::OnPaint()
{
	
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		
		CDialog::OnPaint();
	}
}

HCURSOR CSudokuSolverDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CSudokuSolverDlg::OnBnHotItemChangeOk(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMBCHOTITEM pHotItem = reinterpret_cast<LPNMBCHOTITEM>(pNMHDR);
	*pResult = 0;

}

void CSudokuSolverDlg::OnBnSetfocusOk()
{
	
}
bool CSudokuSolverDlg::Get_validity()
{
	return CSudokuSolverDlg::valid1;
}

void CSudokuSolverDlg::OnBnClickedOk()//when solve button is clicked
{
	rcount=0;
	if(sound)
	PlaySound(MAKEINTRESOURCE(IDR_WAVE2),AfxGetInstanceHandle(),SND_ASYNC |SND_RESOURCE);
	KillTimer(911);
	
	GetDlgItem(IDC_UNDO1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TIME)->ShowWindow(SW_HIDE);
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
		{
		CSudokuSolverDlg::buts[i][j].GetWindowTextW(cc);
		CMyEdit::m_matrix[i][j]=_wtoi(cc);
		
		}
	if(!asolve.setMatrix(CMyEdit::m_matrix)){
		GetDlgItem(IDOK)->ShowWindow(SW_SHOW);
	    GetDlgItem(IDC_UNDO1)->ShowWindow(SW_SHOW);
		Error e=asolve.getError();
		CString err(e.getErrorReport().c_str());
		GetDlgItem(IDC_TIME2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_TIME2)->SetWindowTextW(err);
		
	    }
	else{
		SudokuSolver sudoSolver(asolve);
		nextsud=sudoSolver;
		if(sudoSolver.hasMoreSolution())
		{	
		GetDlgItem(IDOK)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_NXT)->ShowWindow(SW_SHOW);
		ans=sudoSolver.nextSolution();
		ans.MatrixToArray(CMyEdit::m_matrix);
		display_ans();
		GetDlgItem(IDC_TIME2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_TIME2)->SetWindowTextW(_T("Sudoku Solved Successfully"));
		}
		else
		{
			GetDlgItem(IDC_UNDO1)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_TIME2)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_TIME2)->SetWindowTextW(_T("No solution is possoble for the given Matrix!!\nseems you messed up the matrix"));
		}


	}
}
void CSudokuSolverDlg::display_ans()
{
	CMyEdit::validity=false;
for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
		{
			CSudokuSolverDlg::buts[i][j].EnableWindow(0);
			itoa(CMyEdit::m_matrix[i][j],c,10);
	sout=c;
    if(CMyEdit::m_matrix[i][j]!=0)
	CSudokuSolverDlg::buts[i][j].SetWindowTextW(sout);
	
		}
		show_nums(false);
		CMyEdit::validity=true;
}
BOOL CSudokuSolverDlg::OnEraseBkgnd(CDC* pDC)
{
	
    CDC dcMemory;
    dcMemory.CreateCompatibleDC(pDC);
    CBitmap* pOldbitmap = dcMemory.SelectObject(&Bacground);
    CRect rcClient;
    GetClientRect(&rcClient);
    const CSize& sbitmap = bitmapSize;
    pDC->BitBlt(0,-20,sbitmap.cx+250,sbitmap.cy+150,&dcMemory,+20,-100,SRCCOPY);
    dcMemory.SelectObject(pOldbitmap);
    return TRUE;
}

HBRUSH CSudokuSolverDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{

	switch (nCtlColor)
    {
    case CTLCOLOR_STATIC:
		{
        pDC->SetTextColor(timec);
		pDC->SetBkMode(0);
		return (HBRUSH)GetStockObject(4);}
	case CTLCOLOR_EDIT:
		{ 			
		pDC->SetTextColor(redcolor);
		pDC->SetBkColor(bluecolor);
		return bluebrush;
		}		
		
	default:
		return (HBRUSH)GetStockObject(7);
		break;
    }
}

void CSudokuSolverDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	CDialog::OnLButtonDown(nFlags, point);
}

void CSudokuSolverDlg::OnBnClickedMin()//when minimize button is clicked
{
	ShowWindow(SW_MINIMIZE);
}
void CSudokuSolverDlg::color_numbers(bool val)
{
if(val)
redcolor=RGB(0,255,0);
else
redcolor=RGB(255,0,0);
}
void CSudokuSolverDlg::OnBnClickedButton1()//Endgame button clicked
{
	if(sound)
	PlaySound(MAKEINTRESOURCE(IDR_WAVE2),AfxGetInstanceHandle(),SND_ASYNC |SND_RESOURCE);
	showgame(false);
	GetDlgItem(IDOK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_NXT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TIME3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TIME2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TIME2)->SetWindowTextW(_T(""));
	GetDlgItem(IDC_PREV)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TIME)->ShowWindow(SW_HIDE);
	this->KillTimer(911);
	GetDlgItem(IDC_ASOL)->ShowWindow(SW_SHOW);
	CMyEdit::validity=false;	
	show_nums(false);
}

void CSudokuSolverDlg::OnBnClickedButton3()//when about button is clicked
{
	if(sound)
	PlaySound(MAKEINTRESOURCE(IDR_WAVE2),AfxGetInstanceHandle(),SND_ASYNC |SND_RESOURCE);
	obj.DestroyWindow();
	obj.Create(IDD_DIALOGBAR);
	obj.ShowWindow(SW_SHOW);
}

void CSudokuSolverDlg::OnBnClickedButton2()//newgame button clicked
{	
	if(sound)
	PlaySound(MAKEINTRESOURCE(IDR_WAVE2),AfxGetInstanceHandle(),SND_ASYNC |SND_RESOURCE);
	GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_ASOL)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EASY)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_DIFF)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MOD)->ShowWindow(SW_SHOW);
	}
void CSudokuSolverDlg::prevsol(bool aj)//prevsol function when nextbutton is pressed
{

if(!aj)
{if(rcount<=28&&rcount>=0)
for(int k=0;k<9;k++)
for(int m=0;m<9;m++)
{
buts[k][m].GetWindowTextW(cf);
prevsoln[rcount][k][m]=_wtoi(cf);
}
rcount++;
}
if(rcount>28)
{
	for(int i=1;i<30;i++)//if the stack is full then move one step left
	{
     for(int k=0;k<9;k++)
     for(int m=0;m<9;m++)
		 prevsoln[i-1][k][m]=prevsoln[i][k][m];	
	}
rcount--;}

}
void CSudokuSolverDlg::OnBnClickedNxt()
{
	if(sound)
	PlaySound(MAKEINTRESOURCE(IDR_WAVE2),AfxGetInstanceHandle(),SND_ASYNC |SND_RESOURCE);
	
	GetDlgItem(IDC_TIME2)->SetWindowTextW(_T(""));
	color_numbers(true);
	GetDlgItem(IDC_PREV)->ShowWindow(SW_SHOW);
	if(nextsud.hasMoreSolution())
	{
	prevsol(false);
	nextans=nextsud.nextSolution();
	nextans.MatrixToArray(CMyEdit::m_matrix);
	display_ans();
	}
	else
	{

		GetDlgItem(IDC_TIME2)->SetWindowTextW(_T("No more solutions available for the given Sudoku."));
	
	}

	}

void CSudokuSolverDlg::OnBnClickedEasy()
{
	if(sound)
	PlaySound(MAKEINTRESOURCE(IDR_WAVE2),AfxGetInstanceHandle(),SND_ASYNC |SND_RESOURCE);
    secs=0;
    GetDlgItem(IDC_TIME)->ShowWindow(SW_SHOW);
	this->vis_dif();
	showgame(true);
	Sleep(10);
	objg.generate(1);
    SetTimer (911,1100,NULL);
	for(int k=0;k<9;k++)
	for(int m=0;m<9;m++)
	{	
	itoa(Cgenerator::gen[k][m],c,10);
	sout=c;
    if(Cgenerator::gen[k][m]!=0)
	{CSudokuSolverDlg::buts[k][m].SetWindowTextW(sout);
	CSudokuSolverDlg::buts[k][m].EnableWindow(false);}
	}
	GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
	GetDlgItem(IDOK)->ShowWindow(SW_SHOW);
	CMyEdit::validity=true;
	ucount=0;
	undonow(true);
	show_nums(true);

}

void CSudokuSolverDlg::OnBnClickedDiff()
{
	if(sound)
	PlaySound(MAKEINTRESOURCE(IDR_WAVE2),AfxGetInstanceHandle(),SND_ASYNC |SND_RESOURCE);
secs=0;
    GetDlgItem(IDC_TIME)->ShowWindow(SW_SHOW);
	this->vis_dif();
	showgame(true);
	Sleep(10);
	objg.generate(4);
    SetTimer (911,1100,NULL);
	for(int k=0;k<9;k++)
	for(int m=0;m<9;m++)
	{	
	itoa(Cgenerator::gen[k][m],c,10);
	sout=c;
    if(Cgenerator::gen[k][m]!=0)
	{CSudokuSolverDlg::buts[k][m].SetWindowTextW(sout);
	CSudokuSolverDlg::buts[k][m].EnableWindow(false);
	}
	}
	GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
	GetDlgItem(IDOK)->ShowWindow(SW_SHOW);
	CMyEdit::validity=true;
	ucount=0;
	rcount=0;
	undonow(true);
	show_nums(true);

}
void CSudokuSolverDlg::vis_dif()
{
GetDlgItem(IDC_EASY)->ShowWindow(SW_HIDE);
GetDlgItem(IDC_MOD)->ShowWindow(SW_HIDE);
GetDlgItem(IDC_DIFF)->ShowWindow(SW_HIDE);
}
void CSudokuSolverDlg::OnBnClickedMod()
{
	if(sound)
	PlaySound(MAKEINTRESOURCE(IDR_WAVE2),AfxGetInstanceHandle(),SND_ASYNC |SND_RESOURCE);
	GetDlgItem(IDC_TIME)->ShowWindow(SW_SHOW);
	this->vis_dif();
	secs=0;
	SetTimer (911,1100,NULL);
	showgame(true);
	Sleep(10);
	objg.generate(3);
	for(int k=0;k<9;k++)
	for(int m=0;m<9;m++)
	{	
	itoa(Cgenerator::gen[k][m],c,10);
	sout=c;
    if(Cgenerator::gen[k][m]!=0)
	{CSudokuSolverDlg::buts[k][m].SetWindowTextW(sout);
	CSudokuSolverDlg::buts[k][m].EnableWindow(false);
	}
	}
	GetDlgItem(IDC_BUTTON1)->ShowWindow(SW_SHOW);
	GetDlgItem(IDOK)->ShowWindow(SW_SHOW);
	CMyEdit::validity=true;
	ucount=0;
	rcount=0;
	undonow(true);
	show_nums(true);
}

void CSudokuSolverDlg::OnBnClickedAsol()
{
	rcount=0;
	if(sound)
	PlaySound(MAKEINTRESOURCE(IDR_WAVE2),AfxGetInstanceHandle(),SND_ASYNC |SND_RESOURCE);
	GetDlgItem(IDC_ASOL)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_HIDE);
	show_nums(true);
	
	for(int k=0;k<9;k++)
	for(int m=0;m<9;m++)	
	{Cgenerator::gen[k][m]=0;
	CSudokuSolverDlg::buts[k][m].EnableWindow(true);}
	showgame(true);
	this->KillTimer(911);
	GetDlgItem(IDC_TIME)->ShowWindow(SW_HIDE);
	GetDlgItem(IDOK)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_CANCER)->ShowWindow(SW_SHOW);
}

void CSudokuSolverDlg::OnTimer(UINT_PTR nIDEvent)
{
	
	GetDlgItem(IDC_TIME)->ShowWindow(SW_SHOW);
	itoa(secs,tm,10);
	tout=tm;
	GetDlgItem(IDC_TIME)->SetWindowText(tout);
	if(secs%20==0)
    GetDlgItem(IDC_TIME)->ShowWindow(SW_HIDE);
	if(secs<9999)
	secs++;
	if(secs>200)
	timec=RGB(255,0,0);
	else if(secs>100)
	timec=RGB(235,80,80);
	CDialog::OnTimer(nIDEvent);

}

void CSudokuSolverDlg::OnBnClickedPrev()
{
	if(sound)
	PlaySound(MAKEINTRESOURCE(IDR_WAVE2),AfxGetInstanceHandle(),SND_ASYNC |SND_RESOURCE);
	color_numbers(true);
	GetDlgItem(IDC_TIME2)->SetWindowTextW(_T(""));
    for(int k=0;k<9;k++)
	for(int m=0;m<9;m++)
	{
	CMyEdit::m_matrix[k][m]=prevsoln[rcount][k][m];
	}
	nextans.setMatrix(prevsoln[rcount]);
	if(rcount>0)
	rcount--;
	else
	{GetDlgItem(IDC_TIME2)->SetWindowTextW(_T("First Solution reached"));
	GetDlgItem(IDC_PREV)->ShowWindow(SW_HIDE);
	}
	display_ans();
}

void CSudokuSolverDlg::OnLButtonUp(UINT nFlags, CPoint point)
{  
    
	
	CDialog::OnLButtonUp(nFlags, point);
}

void CSudokuSolverDlg::OnMouseMove(UINT nFlags, CPoint point)
{

	CDialog::OnMouseMove(nFlags, point);
}

void CSudokuSolverDlg::OnBnClickedCancel()//exit button is pressed
{
	if(is_game_visible)
	AfxMessageBox(_T("A Game is in progress. Please End the game before you Exit"));
	else
	OnCancel();
}

void CSudokuSolverDlg::OnBnClickedCancer()
{
	if(sound)
	PlaySound(MAKEINTRESOURCE(IDR_WAVE2),AfxGetInstanceHandle(),SND_ASYNC |SND_RESOURCE);
	showgame(false);
    show_nums(false);
	GetDlgItem(IDOK)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_CANCER)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_NXT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PREV)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_TIME)->ShowWindow(SW_HIDE);
	this->KillTimer(911);
	GetDlgItem(IDC_ASOL)->ShowWindow(SW_SHOW);
}

/*void CSudokuSolverDlg::redonow(bool aj)
{
	if(aj)
	{for(int k=0;k<9;k++)
      for(int m=0;m<9;m++)
		  redo[rcount][k][m]=Cgenerator::gen[k][m];
	}
	int k,m,i;
if(!aj&&rcount<=8&&rcount>=0)
{
rcount++;
for(k=0;k<9;k++)
     for(m=0;m<9;m++)
        redo[rcount][k][m]=undo[ucount][k][m];

}
if(!aj&&rcount>8)
{
for(int i=1;i<10;i++)//if the stack is full then move ane step left
	{
     for(int k=0;k<9;k++)
     for(int m=0;m<9;m++)
		 redo[i-1][k][m]=redo[i][k][m];	
	}
	rcount--;
}

}*/
void CSudokuSolverDlg::undonow(bool aj)
{int k,m,i;
	if(aj)
	{for(int k=0;k<9;k++)
      for(int m=0;m<9;m++)
		  undo[ucount][k][m]=Cgenerator::gen[k][m];
	}
	else if(!aj)
	{ 
		if(ucount<=45&&ucount>=0)
	{
		
	ucount++;
	for(k=0;k<9;k++)
     for(m=0;m<9;m++)
	  undo[ucount][k][m]=CMyEdit::m_matrix[k][m];
	 if(ucount>45)
	{
	for(int i=1;i<50;i++)//if the stack is full then move ane step left
	{
     for(int k=0;k<9;k++)
     for(int m=0;m<9;m++)
		 undo[i-1][k][m]=undo[i][k][m];	
	}
	ucount--;
    }
	}
	}
}
void CSudokuSolverDlg::OnBnClickedUndo1()
{
	if(sound)
	PlaySound(MAKEINTRESOURCE(IDR_WAVE2),AfxGetInstanceHandle(),SND_ASYNC |SND_RESOURCE);
	int k,m,i;
	CMyEdit::validity=false;
	for(k=0;k<9;k++)
	for(m=0;m<9;m++)
    CSudokuSolverDlg::buts[k][m].SetWindowTextW(_T(""));
	if(ucount>=1)
	ucount--;
    for(int k=0;k<9;k++)
	for(int m=0;m<9;m++)
	{	
	itoa(undo[ucount][k][m],c,10);
	sout=c;
	if(undo[ucount][k][m]!=0)
	CSudokuSolverDlg::buts[k][m].SetWindowTextW(sout);
	}
	CMyEdit::validity=true;
	
}

void CSudokuSolverDlg::OnBnClickedRedo1()
{
	/*if(rcount==0)
    GetDlgItem(IDC_REDO1)->ShowWindow(SW_HIDE);
	int k,m;
	CMyEdit::validity=false;
	for(k=0;k<9;k++)
	for(m=0;m<9;m++)
    CSudokuSolverDlg::buts[k][m].SetWindowTextW(_T(""));
	for(k=0;k<9;k++)
	for(m=0;m<9;m++)
	{	
	itoa(redo[rcount][k][m],c,10);
	sout=c;
    if(redo[rcount][k][m]!=0)
	CSudokuSolverDlg::buts[k][m].SetWindowTextW(sout);
	}
	CMyEdit::validity=true;
	for(k=0;k<9;k++)
	for(m=0;m<9;m++)

	if(rcount>=0&&rcount<9)
	rcount--;*/

}
void CSudokuSolverDlg::win_declare(bool aj)
{

}
void CSudokuSolverDlg::OnBnClickedButton19()
{
	if(focs)
	focs->SetWindowTextW(_T("1"));
}

void CSudokuSolverDlg::OnBnClickedButton20()
{if(focs)
	focs->SetWindowTextW(_T("2"));
}

void CSudokuSolverDlg::OnBnClickedButton21()
{if(focs)
	focs->SetWindowTextW(_T("3"));
}

void CSudokuSolverDlg::OnBnClickedButton16()
{if(focs)
	focs->SetWindowTextW(_T("4"));
}

void CSudokuSolverDlg::OnBnClickedButton17()
{if(focs)
	focs->SetWindowTextW(_T("5"));
}

void CSudokuSolverDlg::OnBnClickedButton18()
{if(focs)
    focs->SetWindowTextW(_T("6"));
}

void CSudokuSolverDlg::OnBnClickedButton13()
{if(focs)
	focs->SetWindowTextW(_T("7"));
}

void CSudokuSolverDlg::OnBnClickedButton14()
{if(focs)
	focs->SetWindowTextW(_T("8"));
}

void CSudokuSolverDlg::OnBnClickedButton15()
{if(focs)
	focs->SetWindowTextW(_T("9"));
}
void CSudokuSolverDlg::OnBnClickedSave()//when save butotn is clicked
{
	if(sound)
	PlaySound(MAKEINTRESOURCE(IDR_WAVE2),AfxGetInstanceHandle(),SND_ASYNC |SND_RESOURCE);
	strFilter="TEXT Files only bazinga  (*.txt)";
	CFileDialog obj(false,_T(".txt"),NULL,0,strFilter);
	if(obj.DoModal()==IDOK)
	{
	CString sss;
	try{
	fp.Open(obj.GetFileName(),CFile::modeNoTruncate|CFile::modeCreate|CFile::modeWrite);
	fp.SeekToEnd();
	fp.Write("\nSudoku Save file",18);
	for(int i=0;i<9;i++)
	{
		fp.Write("\n",1);
		for(int j=0;j<9;j++)
		{
			CSudokuSolverDlg::buts[i][j].GetWindowText(sss);
			if(sss!="")
            fp.Write(sss,1);
			else
            fp.Write("-",1);
			fp.Write("\t",1);
		}
	}
	GetDlgItem(IDC_TIME2)->SetWindowTextW(_T("Solution written to file successfully."));
	fp.Close();
	}
	catch(CFileException *e)
	{
	AfxMessageBox(_T("an error occured while writing to file. your file was not saved"));
	e->Delete();
	}}
	else
		return;

}

void CSudokuSolverDlg::OnBnClickedClear()
{
	if(focs)
	focs->SetWindowTextW(_T(""));
}

void CSudokuSolverDlg::OnBnClickedMusic()
{
if(sound)
{sound=false;
GetDlgItem(IDC_TIME2)->SetWindowText(_T("sound disabled.\nTo enable sound press it again"));
}
else
{sound=true;
GetDlgItem(IDC_TIME2)->SetWindowText(_T("sound enabled. \nTo disable sound press it again"));
PlaySound(MAKEINTRESOURCE(IDR_WAVE2),AfxGetInstanceHandle(),SND_ASYNC |SND_RESOURCE);
}
}
