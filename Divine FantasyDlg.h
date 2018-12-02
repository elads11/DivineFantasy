
// Divine FantasyDlg.h : header file
//

#pragma once
#include <string>
#include <iostream>
#include "Player.h"
#include <stdlib.h>
#include "Mage.h"
#include "Warlock.h"
#include "Wizard.h"
#include "Warrior.h"
#include "Knight.h"
#include "Assassin.h"
#include <stack>
#include <vector>
#include "Command.h"

// CDivineFantasyDlg dialog
class CDivineFantasyDlg : public CDialogEx
{
// Construction
public:
	CDivineFantasyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_DIVINEFANTASY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeresponse();
	afx_msg void OnBnClickedStart();
	afx_msg void OnBnClickeddiceroll();
	afx_msg void OnStnClickeddiceroll();
	int m_roll;
	int type;
	int m_isPressed;
	int numPlayerTurn;
	void addPlayer(int player_type);
	void Execute(int dice_result);
	void setLoc(Player &p, int dice_result);
	void encounter(Player &p);
//	afx_msg void OnEnChangeplayerturn();
	int m_turn;
	int player1_type;
	int player2_type;
	CString player1_name;
	CString player2_name;
	CString terrain;
	CString info;
	
	afx_msg void OnBnClickedundo();
	afx_msg void OnBnClickedredo();
	
	CTypedPtrArray<CObArray, Player*> players;
	stack<Command*> commands, undoes;
	afx_msg void OnBnClickedsave();
	afx_msg void OnBnClickedsave2();

	CBitmap end, market, gate, village;

	int m_2gold;
	int m_2hp;
	int m_2kills;
	int m_2stat;
	int m_2sword1;
	int m_2sword2;
	int m_2sword3;
	int m_1hp;
	int m_1gold;
	int m_1kills;
	int m_1stat;
	int m_1sword1;
	int m_1sword2;
	int m_1sword3;
};
