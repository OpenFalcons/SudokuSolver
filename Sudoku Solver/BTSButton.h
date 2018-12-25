#pragma once


// CBTSButton

class CBTSButton : public CButton
{
	DECLARE_DYNAMIC(CBTSButton)

public:
	CBTSButton();
	void Id_Assigner(int id);
	virtual ~CBTSButton();
	bool m_bOverControl;
	UINT m_nTimerID;
	CBitmap norm,hover,push;
	int niD;
	bool init;

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
protected:
	virtual void PreSubclassWindow();
};


