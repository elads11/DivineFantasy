
// Divine FantasyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Divine Fantasy.h"
#include "Divine FantasyDlg.h"
#include "afxdialogex.h"
#include <string>
#include <iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDivineFantasyDlg dialog




CDivineFantasyDlg::CDivineFantasyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDivineFantasyDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_roll = 0;
	//  m_player_turn = _T("");
	m_isPressed = 0;
	m_turn = 0;
	player1_name = _T("");
	player2_name = _T("");
	terrain = _T("");
	info = _T("");
	end.LoadBitmapW(IDB_BITMAP1);
	market.LoadBitmapW(IDB_BITMAP2);
	gate.LoadBitmapW(IDB_BITMAP6);
	village.LoadBitmapW(IDB_BITMAP8);



	m_2gold = 0;
	m_2hp = 0;
	m_2kills = 0;
	m_2stat = 0;
	m_2sword1 = 0;
	m_2sword2 = 0;
	m_2sword3 = 0;
	m_1hp = 0;
	m_1gold = 0;
	m_1kills = 0;
	m_1stat = 0;
	m_1sword1 = 0;
	m_1sword2 = 0;
	m_1sword3 = 0;
}

void CDivineFantasyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, txt_dice_roll, m_roll);
	//  DDX_LBString(pDX, lbl_player_turn, m_player_turn);
	DDX_Text(pDX, lbl_player_turn, m_turn);
	DDX_Text(pDX, lbl_player1_name, player1_name);
	DDX_Text(pDX, lbl_player2_name, player2_name);
	DDX_Text(pDX, lbl_terrain, terrain);
	DDX_Text(pDX, lbl_event, info);
	DDX_Text(pDX, second_gold, m_2gold);
	DDX_Text(pDX, second_hp, m_2hp);
	DDX_Text(pDX, second_kills, m_2kills);
	DDX_Text(pDX, second_stat, m_2stat);
	DDX_Text(pDX, second_sword1, m_2sword1);
	DDX_Text(pDX, second_sword2, m_2sword2);
	DDX_Text(pDX, second_sword3, m_2sword3);
	DDX_Text(pDX, first_hp, m_1hp);
	DDX_Text(pDX, first_gold, m_1gold);
	DDX_Text(pDX, first_kills, m_1kills);
	DDX_Text(pDX, first_stat, m_1stat);
	DDX_Text(pDX, first_sword1, m_1sword1);
	DDX_Text(pDX, first_sword2, m_1sword2);
	DDX_Text(pDX, first_sword3, m_1sword3);
}

BEGIN_MESSAGE_MAP(CDivineFantasyDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(btn_START, &CDivineFantasyDlg::OnBnClickedStart)
	ON_BN_CLICKED(btn_dice_roll, &CDivineFantasyDlg::OnBnClickeddiceroll)
	ON_STN_CLICKED(txt_dice_roll, &CDivineFantasyDlg::OnStnClickeddiceroll)
	ON_BN_CLICKED(btn_undo, &CDivineFantasyDlg::OnBnClickedundo)
	ON_BN_CLICKED(btn_redo, &CDivineFantasyDlg::OnBnClickedredo)
	ON_BN_CLICKED(btn_save, &CDivineFantasyDlg::OnBnClickedsave)
	ON_BN_CLICKED(btn_save2, &CDivineFantasyDlg::OnBnClickedsave2)
END_MESSAGE_MAP()


// CDivineFantasyDlg message handlers

BOOL CDivineFantasyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDivineFantasyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}
// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDivineFantasyDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CRect rec;
	GetClientRect(&rec);
	int startX = 0;
	int startY = 0;
	int tileSize = 72;
	CBrush brush;
	CPen pen;
	pen.CreatePen(PS_SOLID, 1, RGB(000,000,000));
	brush.CreateSolidBrush(RGB(100,50,50));
	dc.SelectObject(&pen);
	dc.SelectObject(&brush);
	for (int i=0; i<5; i++){
		for (int j=0; j<5; j++){
			dc.Rectangle(startX, startY,startX+tileSize,startY+tileSize);
			startX += tileSize;
		}
		startX = 0;
		startY += tileSize;
	}
	CDC memDc;
	memDc.CreateCompatibleDC(&dc);
	memDc.SelectObject(&end);
	dc.BitBlt(144, 144, 72, 72, &memDc, 0, 0, SRCCOPY);
	memDc.SelectObject(&market);
	dc.BitBlt(144, 288, 72, 72, &memDc, 0, 0, SRCCOPY);
	memDc.SelectObject(&gate);
	dc.BitBlt(72, 144, 72, 72, &memDc, 0, 0, SRCCOPY);
	memDc.SelectObject(&village);
	dc.BitBlt(0, 0, 72, 72, &memDc, 0, 0, SRCCOPY);


	if (m_isPressed == 1){
		players[0]->Draw(&dc,1);
		players[1]->Draw(&dc,2);
	}
	
	

	CDialogEx::OnPaint();
	
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDivineFantasyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDivineFantasyDlg::OnLbnSelchangeresponse()
{
	// TODO: Add your control notification handler code here
}


void CDivineFantasyDlg::OnBnClickedStart()
{
	try{
		m_isPressed = 1;

		//Default Values
		player1_type = 0;
		player2_type = 0;

		if (IsDlgButtonChecked(Radio1) == BST_CHECKED)
			player1_type = 1;
		else if (IsDlgButtonChecked(Radio2) == BST_CHECKED)
			player1_type = 2;
		else if (IsDlgButtonChecked(Radio3) == BST_CHECKED)
			player1_type = 3;
		else if (IsDlgButtonChecked(Radio4) == BST_CHECKED)
			player1_type = 4;

		if (IsDlgButtonChecked(Radio5) == BST_CHECKED)
			player2_type = 1;
		else if (IsDlgButtonChecked(Radio6) == BST_CHECKED)
			player2_type = 2;
		else if (IsDlgButtonChecked(Radio7) == BST_CHECKED)
			player2_type = 3;
		else if (IsDlgButtonChecked(Radio8) == BST_CHECKED)
			player2_type = 4;

		addPlayer(player1_type);
		addPlayer(player2_type);

		numPlayerTurn = 0;
		UpdateData(true);
		player1_name = players[0]->getName().c_str();
		player2_name = players[1]->getName().c_str();
		UpdateData(false);
		Invalidate();		
	}
	catch(const std::exception& e) {	}
}

void CDivineFantasyDlg::addPlayer(int player_type){
	Player * p;
	if (player_type == 1)
		p = new Knight();
	else if (player_type == 2)
		p = new Assassin();
	else if (player_type == 3)
		p = new Wizard();
	else if (player_type == 4)
		p = new Warlock();
	p->setPosX(18);
	p->setPosY(0);
	p->loc = 0;
	p->level = 1;
	p->player_type = player_type;
	players.Add(p);
}

void CDivineFantasyDlg::OnBnClickeddiceroll()
{
	m_isPressed = 1;
	UpdateData(true);
	srand(time(NULL));
	m_roll = rand() % 6 +1;
	m_turn = (numPlayerTurn + 1) % 2 + 1;
	UpdateData(false);	
	Execute(m_roll);
	Invalidate();	
}

void CDivineFantasyDlg::OnStnClickeddiceroll()
{

}

//Game engine function, sets the location of the players based on dice roll and decided on the encounter type before passing it to the encounter function
void CDivineFantasyDlg::Execute(int dice_result){	
	setLoc(*players[numPlayerTurn],dice_result);
	encounter(*players[numPlayerTurn]);
	Command *c = new Command(players, players[numPlayerTurn], numPlayerTurn);
	c->perform();
	commands.push(c);

	//stats update
	UpdateData(true);
	m_1hp = players[0]->getHP();
	m_1gold = players[0]->getGold();
	m_1kills = players[0]->getMonstersKilled();
	m_1stat = players[0]->getExtraStat();
	m_1sword1 = players[0]->artefacts[0];
	m_1sword2 = players[0]->artefacts[1];
	m_1sword3 = players[0]->artefacts[2];
	m_2hp = players[1]->getHP();
	m_2gold = players[1]->getGold();
	m_2kills = players[1]->getMonstersKilled();
	m_2stat = players[1]->getExtraStat();
	m_2sword1 = players[1]->artefacts[0];
	m_2sword2 = players[1]->artefacts[1];
	m_2sword3 = players[1]->artefacts[2];
	UpdateData(false);

	numPlayerTurn = (numPlayerTurn + 1) % 2; // this is the end of the function, indicating that it's the next players turn
}

//sets the location of the players on the map based on dice roll
void CDivineFantasyDlg::setLoc(Player &p,int dice_roll){
	if (players[numPlayerTurn]->level == 1){
		players[numPlayerTurn]->loc = (players[numPlayerTurn]->loc + dice_roll) % 16;

		switch(p.loc){
		case(0):{ players[numPlayerTurn]->setPosX(18); players[numPlayerTurn]->setPosY(0); UpdateData(true); terrain = std::string("Village").c_str(); UpdateData(false); break; }
		case(1):{ players[numPlayerTurn]->setPosX (90); players[numPlayerTurn]->setPosY(0); UpdateData(true); terrain = std::string("Fields").c_str(); UpdateData(false); break; }
		case(2):{ players[numPlayerTurn]->setPosX(162); players[numPlayerTurn]->setPosY(0); UpdateData(true); terrain = std::string("Fields").c_str(); UpdateData(false); break; }
		case(3):{ players[numPlayerTurn]->setPosX(234); players[numPlayerTurn]->setPosY(0); UpdateData(true); terrain = std::string("Fields").c_str(); UpdateData(false); break; }
		case(4):{ players[numPlayerTurn]->setPosX(306); players[numPlayerTurn]->setPosY(0); UpdateData(true); terrain = std::string("Fields").c_str(); UpdateData(false); break; }
		case(5):{ players[numPlayerTurn]->setPosX (306); players[numPlayerTurn]->setPosY(72); UpdateData(true); terrain = std::string("Fields").c_str(); UpdateData(false); break; }
		case(6):{ players[numPlayerTurn]->setPosX(306); players[numPlayerTurn]->setPosY(144); UpdateData(true); terrain = std::string("Shrine").c_str(); UpdateData(false); break; }
		case(7):{ players[numPlayerTurn]->setPosX(306); players[numPlayerTurn]->setPosY(216); UpdateData(true); terrain = std::string("Fields").c_str(); UpdateData(false); break; }
		case(8):{ players[numPlayerTurn]->setPosX(306); players[numPlayerTurn]->setPosY(288); UpdateData(true); terrain = std::string("Fields").c_str(); UpdateData(false); break; }
		case(9):{ players[numPlayerTurn]->setPosX(234); players[numPlayerTurn]->setPosY(288); UpdateData(true); terrain = std::string("Fields").c_str(); UpdateData(false); break; }
		case(10):{ players[numPlayerTurn]->setPosX(162); players[numPlayerTurn]->setPosY(288); UpdateData(true); terrain = std::string("Market").c_str(); UpdateData(false); break; }
		case(11):{ players[numPlayerTurn]->setPosX(90); players[numPlayerTurn]->setPosY(288); UpdateData(true); terrain = std::string("Fields").c_str(); UpdateData(false); break; }
		case(12):{ players[numPlayerTurn]->setPosX(18); players[numPlayerTurn]->setPosY(288); UpdateData(true); terrain = std::string("Fields").c_str(); UpdateData(false); break; }
		case(13):{ players[numPlayerTurn]->setPosX(18); players[numPlayerTurn]->setPosY(216); UpdateData(true); terrain = std::string("Fields").c_str(); UpdateData(false); break; }
		case(14):{ players[numPlayerTurn]->setPosX(18); players[numPlayerTurn]->setPosY(144); UpdateData(true); terrain = std::string("Cursed Farm").c_str(); UpdateData(false); break; }
		case(15):{ players[numPlayerTurn]->setPosX(18); players[numPlayerTurn]->setPosY(72); UpdateData(true); terrain = std::string("Fields").c_str(); UpdateData(false); break; }
		}
	}
	if (players[numPlayerTurn]->level == 2){
		players[numPlayerTurn]->loc = (players[numPlayerTurn]->loc + dice_roll) % 8;
		switch(p.loc){
		case(0):{ players[numPlayerTurn]->setPosX(90); players[numPlayerTurn]->setPosY(72); UpdateData(true); terrain = std::string("Castle").c_str(); UpdateData(false); break; }
		case(1):{ players[numPlayerTurn]->setPosX(162); players[numPlayerTurn]->setPosY(72); UpdateData(true); terrain = std::string("Haunted Fort").c_str(); UpdateData(false); break; }
		case(2):{ players[numPlayerTurn]->setPosX(234); players[numPlayerTurn]->setPosY(72); UpdateData(true); terrain = std::string("High Lands").c_str(); UpdateData(false); break; }
		case(3):{ players[numPlayerTurn]->setPosX(234); players[numPlayerTurn]->setPosY(144); UpdateData(true); terrain = std::string("High Lands").c_str(); UpdateData(false); break; }
		case(4):{ players[numPlayerTurn]->setPosX(234); players[numPlayerTurn]->setPosY(216); UpdateData(true); terrain = std::string("High Lands").c_str(); UpdateData(false); break; }
		case(5):{ players[numPlayerTurn]->setPosX(162); players[numPlayerTurn]->setPosY(216); UpdateData(true); terrain = std::string("Holy Land").c_str(); UpdateData(false); break; }
		case(6):{ players[numPlayerTurn]->setPosX(90); players[numPlayerTurn]->setPosY(216); UpdateData(true); terrain = std::string("High Lands").c_str(); UpdateData(false); break; }
		case(7):{ players[numPlayerTurn]->setPosX(90); players[numPlayerTurn]->setPosY(144); UpdateData(true); terrain = std::string("Gate").c_str(); UpdateData(false); break; }
		}

	}
	if (players[numPlayerTurn]->level == 3){
		players[numPlayerTurn]->setPosX(162);
		players[numPlayerTurn]->setPosY(144);
		Invalidate();
		UpdateData(true); terrain = std::string("Throne Room").c_str(); UpdateData(false);
		if (numPlayerTurn == 0)
			MessageBoxA(0, "PLAYER 1 WON!","Victory", MB_OK);
		if (numPlayerTurn == 1)
			MessageBoxA(0, "PLAYER 2 WON!","Victory", MB_OK);
	}
	Invalidate();
}

//if 0-> call neutralEnc(), if 1 ->call goodEnc(), if 2 ->call badEnc()
void CDivineFantasyDlg::encounter(Player &p){
	//make sure to change the player's level to 2 if he got the first 2 artefacts
	if (p.level == 1){
		if (p.loc == 10){ //market
			if (p.getGold() >= 10){ //need at least 10 gold for the 2nd artefact
				p.artefacts[1] = 1;
				UpdateData(true);
				info = std::string("You find the Divine Sword's tip in the market, and buy it!").c_str();
				UpdateData(false);
			}
		}
		else if (p.loc == 6 && p.getAllignment() == 1) //Shrine - for good, if hp atleast 20, get first sword
		{
			if (p.getHP() >= 20){ //need at least 20 hp for the 1st artefact
				p.artefacts[0] = 1;
				UpdateData(true);
				info = std::string("You pick the Divine Sword's blade while at the Shrine!").c_str();
				UpdateData(false);
			}
		}
		else if (p.loc == 14 && p.getAllignment() == 2) //Cursed Farm - for bad, if hp atleast 20, get first sword
		{
			if (p.getHP() >= 20){ //need at least 20 hp for the 1st artefact
				p.artefacts[0] = 1;
				UpdateData(true);
				info = std::string("You pick the Divine Sword's blade while at the Cursed Farm!").c_str();
				UpdateData(false);
			}
		}
		else{ //Normal Tile - player gets an encounter and will permorm accordingly with his perform function
				srand(time(NULL));
				type = rand() % 20; //determine the nature of the encounter: gives bonuses, attacked by enemy or reduces stats
				if (type == 0){ //0 - HP + 1
					p.setHP(p.getHP() + 1);
					UpdateData(true);
					info = std::string("You are feeling refreshened: Hp + 1").c_str();
					UpdateData(false);
				}
				else if (type == 1){ //1 - HP + 2 
					p.setHP(p.getHP() + 2);
					UpdateData(true);
					info = std::string("You have been blessed: Hp + 2").c_str();
					UpdateData(false);
				}				
				else if (type == 2){ //2 - GOLD + 1 
					p.setGold(p.getGold() + 1);
					UpdateData(true);
					info = std::string("What is that? You pocket just grew! Gold + 1").c_str();
					UpdateData(false);
				}
				else if (type == 3){ //3 - GOLD + 2 
					p.setGold(p.getGold() + 2);
					UpdateData(true);
					info = std::string("All that is shiny is gold! Gold + 2").c_str();
					UpdateData(false);
				}
				else if (type >= 4 && type <8){ //4-7 - attacked by weak enemy, 20% chance to lose 1 hp (can't drop below 1), otherwise enemy slain, adds 1 to monsters killed
					srand(time(NULL));
					int stuff = rand() % 5;
					if (stuff == 0){
						p.setHP(p.getHP() - 1);
						if (p.getHP() == 0)
							p.setHP(1);
						UpdateData(true);
						info = std::string("The monster hit you hard! You lose 1 HP").c_str();
						UpdateData(false);
					}
					else{
						p.setMonstersKilled(p.getMonstersKilled() + 1);
						UpdateData(true);
						info = std::string("You slay the weak monster! One more for you collection").c_str();
						UpdateData(false);
					}
				}
				else if (type == 8){ //8 - get first artefact replica suddenly
					if (p.artefacts[1] == 0){
						p.artefacts[0] = 1;
						UpdateData(true);
						info = std::string("Out of nowhere you get a replica of the first artefact!").c_str();
						UpdateData(false);
					}
				}
				else if (type == 9){ //9 - get second artefact replica suddenly
					if (p.artefacts[1] == 0){
						p.artefacts[1] = 1;
						UpdateData(true);
						info = std::string("Out of nowhere you get a replica of the second artefact!").c_str();
						UpdateData(false);
					}
				}
				else{
					UpdateData(true);
					info = std::string("").c_str();
					UpdateData(false);
				}
				p.perform();
		}
		if (p.artefacts[0] == 1 && p.artefacts[1] == 1){
			p.level = 2;
			p.loc = 0;
		}

	}

	//in level 2, a player gets the third artefact if he reaches shrine(good) or haunted house(bad). Then he proceeds to gate and wins.
	else if (p.level == 2){
		if(p.loc == 5 && p.getAllignment() == 1){
			p.artefacts[2] = 1;
			UpdateData(true);
			info = std::string("Congratulations! You found the Sword's Hilt!").c_str();
			UpdateData(false);
		}
		else if(p.loc == 1 && p.getAllignment() == 2){
			p.artefacts[2] = 1;
			UpdateData(true);
			info = std::string("Congratulations! You found the Sword's Hilt!").c_str();
			UpdateData(false);
		}
		if(p.loc == 7 && p.artefacts[2] == 1){
			UpdateData(true);
			info = std::string("You step through the Gate with the Divine Sword!").c_str();
			UpdateData(false);
			p.level = 3;
		}
	}
} 


//UNDO
void CDivineFantasyDlg::OnBnClickedundo()
{
	//if(!commands.empty()){
	//	numPlayerTurn = (numPlayerTurn + 1) % 2;
	//	UpdateData(true);
	//	m_turn = numPlayerTurn+1;
	//	UpdateData(false);
	//
	//	
	//	
	//	//Command *c = commands.top();
	//	//c->rollback();
	//	//undoes.push(c);
	//	//commands.pop();
	//}
	Invalidate();
}

//REDO
void CDivineFantasyDlg::OnBnClickedredo()
{
	numPlayerTurn = (numPlayerTurn + 1) % 2;
	UpdateData(true);
	m_turn = numPlayerTurn+1;
	UpdateData(false);
	
	/*Command *c = undoes.top();
	players[numPlayerTurn] = c->myTurns.ElementAt(myTurns.GetSize() - 3);
	c->perform();
	commands.push(c);
	*///undoes.pop();
	Invalidate();
}

//SAVE
void CDivineFantasyDlg::OnBnClickedsave()
{
	CFile file(L"FILE.$$", CFile::modeWrite | CFile::modeCreate);
	CArchive ar(&file, CArchive::store);
	ar << players[0];
	ar << players[1];
	ar << numPlayerTurn;
}

//LOAD
void CDivineFantasyDlg::OnBnClickedsave2()
{
	UpdateData(true);
	CFile file(L"FILE.$$", CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	CObject *p1;
	CObject *p2;
	ar >> p1 >> p2 >> numPlayerTurn;
	players[0]=((Player*)p1);
	players[1]=((Player*)p2);
	m_isPressed = true;
	Invalidate();
	m_turn = (numPlayerTurn+1)%2 + 1;
	m_1hp = players[0]->getHP();
	m_1gold = players[0]->getGold();
	m_1kills = players[0]->getMonstersKilled();
	m_1stat = players[0]->getExtraStat();
	m_1sword1 = players[0]->artefacts[0];
	m_1sword2 = players[0]->artefacts[1];
	m_1sword3 = players[0]->artefacts[2];
	m_2gold = players[1]->getGold();
	m_2hp = players[1]->getHP();
	m_2kills = players[1]->getMonstersKilled();
	m_2stat = players[1]->getExtraStat();
	m_2sword1 = players[1]->artefacts[0];
	m_2sword2 = players[1]->artefacts[1];
	m_2sword3 = players[1]->artefacts[2];
	UpdateData(false);
}
