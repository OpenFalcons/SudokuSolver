// BTSButton.cpp : implementation file
//

#include "stdafx.h"
#include "Sudoku Solver.h"
#include "BTSButton.h"
#include "mmsystem.h"
#pragma comment(lib,"Winmm")

// CBTSButton

IMPLEMENT_DYNAMIC(CBTSButton,CButton)

CBTSButton::CBTSButton()
{
m_nTimerID=0;
m_bOverControl=false; 
init=false;

}
void CBTSButton::Id_Assigner(int nid)
{
niD=nid;
}
CBTSButton::~CBTSButton()
{
}


BEGIN_MESSAGE_MAP(CBTSButton, CButton)
	ON_WM_TIMER()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()



// CBTSButton message handlers



void CBTSButton::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
    CPoint p(GetMessagePos());
    ScreenToClient(&p);

    // Get the bounds of the control (just the client area)
    CRect rect;
    GetClientRect(rect);

    // Check if the mouse is inside the control
    if (!rect.PtInRect(p))
    {
        m_bOverControl = FALSE;
        KillTimer(m_nTimerID);
        Invalidate();
    }
	CButton::OnTimer(nIDEvent);
}

void CBTSButton::OnMouseMove(UINT nFlags, CPoint point)
{
	
if (!m_bOverControl)                  
    {
        m_bOverControl = TRUE;             
        Invalidate();                      
        SetTimer(m_nTimerID,100,NULL);    
    }
	CButton::OnMouseMove(nFlags, point);
}

void CBTSButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
if(!init)
{
	if(niD==IDOK)
{
norm.LoadBitmapW(IDB_SOLVE1);
push.LoadBitmapW(IDB_SOLVE1);
hover.LoadBitmapW(IDB_SOLVE2);
}
else if(niD==IDCANCEL)
 {
norm.LoadBitmapW(IDB_BITM);
push.LoadBitmapW(IDB_BITM);
hover.LoadBitmapW(IDB_BIT);
 }
else if(niD==IDMIN)
 {
norm.LoadBitmapW(IDB_BITMAP20);
push.LoadBitmapW(IDB_BITMAP20);
hover.LoadBitmapW(IDB_BITMAP19);
 }
else if(niD==IDC_NXT)
 {
norm.LoadBitmapW(IDB_BITMAP22);
push.LoadBitmapW(IDB_BITMAP22);
hover.LoadBitmapW(IDB_BITMAP23);
 }
else if(niD==IDC_PREV)
 {
norm.LoadBitmapW(IDB_BITMAP24);
push.LoadBitmapW(IDB_BITMAP24);
hover.LoadBitmapW(IDB_BITMAP25);
 }
else if(niD==IDC_BUTTON1)
 {
norm.LoadBitmapW(IDB_BITMAP17);
push.LoadBitmapW(IDB_BITMAP17);
hover.LoadBitmapW(IDB_BITMAP26);
 }
else if(niD==IDC_BUTTON2)
 {
norm.LoadBitmapW(IDB_BITMAP27);
push.LoadBitmapW(IDB_BITMAP27);
hover.LoadBitmapW(IDB_BITMAP28);
 }
else if(niD==IDC_BUTTON3)
 {
norm.LoadBitmapW(IDB_ABOUT1);
push.LoadBitmapW(IDB_ABOUT1);
hover.LoadBitmapW(IDB_ABOUT2);
 }
else if(niD==IDC_EASY)
 {
norm.LoadBitmapW(IDB_EASY1);
push.LoadBitmapW(IDB_EASY1);
hover.LoadBitmapW(IDB_EASY2);
 }
else if(niD==IDC_MOD)
 {
norm.LoadBitmapW(IDB_MOD1);
push.LoadBitmapW(IDB_MOD1);
hover.LoadBitmapW(IDB_MOD2);
 }
else if(niD==IDC_DIFF)
 {
norm.LoadBitmapW(IDB_DIF1);
push.LoadBitmapW(IDB_DIF1);
hover.LoadBitmapW(IDB_DIF2);
 }
else if(niD==IDC_ASOL)
 {
norm.LoadBitmapW(IDB_ASOL1);
push.LoadBitmapW(IDB_ASOL1);
hover.LoadBitmapW(IDB_ASOL2);
 }
else if(niD==IDC_CANCER)
 {
norm.LoadBitmapW(IDB_CANCEL2);
push.LoadBitmapW(IDB_CANCEL2);
hover.LoadBitmapW(IDB_CANCEL1);
 }
else if(niD==IDC_UNDO1)
 {
norm.LoadBitmapW(IDB_BACKTRACK1);
push.LoadBitmapW(IDB_BACKTRACK1);
hover.LoadBitmapW(IDB_BACKTRACK2);
 }
else if(niD==IDC_BUTTON13)
 {
norm.LoadBitmapW(IDB_7);
push.LoadBitmapW(IDB_7);
hover.LoadBitmapW(IDB_7M);
 }
else if(niD==IDC_BUTTON14)
 {
norm.LoadBitmapW(IDB_8);
push.LoadBitmapW(IDB_8);
hover.LoadBitmapW(IDB_8M);
 }
else if(niD==IDC_BUTTON15)
 {
norm.LoadBitmapW(IDB_9);
push.LoadBitmapW(IDB_9);
hover.LoadBitmapW(IDB_9M);
 }
else if(niD==IDC_BUTTON16)
 {
norm.LoadBitmapW(IDB_4);
push.LoadBitmapW(IDB_4);
hover.LoadBitmapW(IDB_4M);
 }
else if(niD==IDC_BUTTON17)
 {
norm.LoadBitmapW(IDB_5);
push.LoadBitmapW(IDB_5);
hover.LoadBitmapW(IDB_5M);
 }
else if(niD==IDC_BUTTON18)
 {
norm.LoadBitmapW(IDB_6);
push.LoadBitmapW(IDB_6);
hover.LoadBitmapW(IDB_6M);
 }
else if(niD==IDC_BUTTON19)
 {
norm.LoadBitmapW(IDB_1);
push.LoadBitmapW(IDB_1);
hover.LoadBitmapW(IDB_1M);
 }
else if(niD==IDC_BUTTON20)
 {
norm.LoadBitmapW(IDB_2M);
push.LoadBitmapW(IDB_2M);
hover.LoadBitmapW(IDB_2);
 }
else if(niD==IDC_BUTTON21)
 {
norm.LoadBitmapW(IDB_3M);
push.LoadBitmapW(IDB_3M);
hover.LoadBitmapW(IDB_3);
 }
else if(niD==IDC_SAVE)
 {
norm.LoadBitmapW(IDB_SAVE);
push.LoadBitmapW(IDB_SAVE);
hover.LoadBitmapW(IDB_SAVEM);
 }
else if(niD==IDC_MUSIC)
 {
norm.LoadBitmapW(IDB_MUS1);
push.LoadBitmapW(IDB_MUS1);
hover.LoadBitmapW(IDB_MUS2);
 }
else if(niD==IDC_CLEAR)
 {
norm.LoadBitmapW(IDB_CLEAR1);
push.LoadBitmapW(IDB_CLEAR1);
hover.LoadBitmapW(IDB_CLEAR2);
 }

	init=true;
}
	CDC* pDC   = CDC::FromHandle(lpDrawItemStruct->hDC);
    CRect rect =lpDrawItemStruct->rcItem;
    UINT state =lpDrawItemStruct->itemState;
	CDC memDC;
	memDC.CreateCompatibleDC(NULL);
	CPoint size(rect.Width(),rect.Height());
	CPoint org(0,0);
	if(state & ODS_SELECTED)
	{
		
		memDC.SelectObject(push);
        pDC->DPtoLP(&org);
	    pDC->BitBlt(-2,-2,size.x+3, size.y+5,&memDC, org.x, org.y,SRCCOPY);
	}
    else 
	{  	memDC.SelectObject(norm);
		pDC->DPtoLP(&org);
	    pDC->BitBlt(-2,-2,size.x+2,size.y+4,&memDC, org.x, org.y,SRCAND|SRCPAINT);
		
	}
	if(m_bOverControl&&!(state&ODS_SELECTED))
	 {
	 
	   memDC.SelectObject(hover);
       pDC->DPtoLP(&org);
	   pDC->BitBlt(-2,-2,size.x+2, size.y+4,&memDC, org.x, org.y,SRCCOPY);
	}
   }

void CBTSButton::PreSubclassWindow()
{
	// TODO: Add your specialized code here and/or call the base class

	CButton::PreSubclassWindow();
	ModifyStyle(0,BS_OWNERDRAW);
	
}
