/*
 * mygame.h: ���ɮ��x�C��������class��interface
 * Copyright (C) 2002-2008 Woei-Kae Chen <wkc@csie.ntut.edu.tw>
 *
 * This file is part of game, a free game development framework for windows.
 *
 * game is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * game is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *	 2004-03-02 V4.0
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *   2005-09-13
 *      Rewrite the codes for CBall and CEraser.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *   2006-02-08 V4.2
 *      1. Rename OnInitialUpdate() -> OnInit().
 *      2. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      3. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress.
*/

#include "CEraser.h"
#include "CBall.h"
#include "CBouncingBall.h"
#include "Character.h"
#include "Bomb.h"
#include "Obstacle.h"
#include "CoinsAnimation.h"


namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// Constants
	/////////////////////////////////////////////////////////////////////////////

	enum AUDIO_ID {				// �w�q�U�ح��Ī��s��
		AUDIO_DING,				// 0
		AUDIO_LAKE,				// 1
		AUDIO_NTUT				// 2
	};

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C���}�Y�e������
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateInit : public CGameState {
	public:
		CGameStateInit(CGame *g);
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnKeyDown(UINT, UINT, UINT); 				// �B�z��LUp���ʧ@
		void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
	protected:
		void OnMove();
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		CMovingBitmap logo;								// csie��logo

		CMovingBitmap scr_start;
		CMovingBitmap scr_load;
		CMovingBitmap scr_preferences;
		CMovingBitmap scr_about;
		CMovingBitmap scr_exit;

		POINT p;
	};

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////
	/*
	class CGameStateRun : public CGameState {
	public:
		CGameStateRun(CGame *g);
		~CGameStateRun();
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();  								// �C������Ȥιϧγ]�w
		void OnKeyDown(UINT, UINT, UINT);
		void OnKeyUp(UINT, UINT, UINT);
		void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnLButtonUp(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
		void OnMouseMove(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@ 
		void OnRButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnRButtonUp(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@

	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		const int		NUMBALLS;	// �y���`��
		CMovingBitmap	background;	// �I����
		CMovingBitmap	help;		// ������
		CBall			*ball;		// �y���}�C
		CMovingBitmap	corner;		// ������
		CEraser			eraser;		// ��l
		CInteger		hits_left;	// �ѤU��������
		CBouncingBall   bball;		// ���мu�����y
		
	};
	*/
	class GameStage_1 : public CGameState {
	public:
		GameStage_1(CGame* g);
		~GameStage_1();
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();                                  // �C������Ȥιϧγ]�w
		void OnKeyDown(UINT, UINT, UINT);               // ��L�ʧ@
		void OnKeyUp(UINT, UINT, UINT);
	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
		void setBomb(int);
		void mapChange(int,int,int);                            // �a���ܰ�&�q��character
		void BombState();
		void setBombRange(int,int,int,int);                                    // �z���ɳ]�m�d��
		void GetCoins();				//�����I������
		void CoinState();				//�����ʵe
	private:
		int bg[13][15];              //0�a�O 1�۶� 2����� 4���z�u 5�z����
		int coins_pos[5][2];         //�w����m
		CMovingBitmap block_0;
		CMovingBitmap block_1;
		Obstacle*     block_2;
		int           block_2_pos[42][2];
		CMovingBitmap panel;
		CMovingBitmap border;
		Character     character_1;   //Range undone
		CMovingBitmap character_2;   //���O�����
		CMovingBitmap AI;
		//CMovingBitmap coins;
		int coins_num;	//�����`��
		int sc;		//�����Y��X�Ӫ���
		CoinsAnimation* coin_Ani;

		Bomb*         Bomb_ch1;
		CInteger count_down;

		int* tempTime = 0;
		int timer;
	};

	/////////////////////////////////////////////////////////////////////////////
	//�C���L�{�����Ȱ��e��
	/////////////////////////////////////////////////////////////////////////////

	class CGamestatePause : public CGameState {
	public:
		CGamestatePause(CGame* g);
		void OnInit();
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnMouseMove(UINT nFlags, CPoint point);
		//void setTemp(int t);
	protected:
		void OnShow();
	private:
		CMovingBitmap bg;
		CMovingBitmap scr_resume;
		CMovingBitmap scr_saveGame;
		CMovingBitmap scr_preferences;
		CMovingBitmap scr_quitToMenu;
		CMovingBitmap scr_exit;
		POINT p;

		//static int temp_time;
	};

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���C�����������A(Game Over)
	// �C��Member function��Implementation���n����
	/////////////////////////////////////////////////////////////////////////////

	class CGameStateOver : public CGameState {
	public:
		CGameStateOver(CGame *g);
		void OnBeginState();							// �]�w�C�������һݪ��ܼ�
		void OnInit();
	protected:
		void OnMove();									// ���ʹC������
		void OnShow();									// ��ܳo�Ӫ��A���C���e��
	private:
		int counter;	// �˼Ƥ��p�ƾ�
	};
	////////////////////////////////////////////////////////////////////////////
//Prefences�e��
////////////////////////////////////////////////////////////////////////////
	class GamePrefences : public CGameState {
	public:
		GamePrefences(CGame* g);
		void OnBeginState();
		void OnInit();
		void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnMouseMove(UINT nFlags, CPoint point);
	protected:
		void OnShow();
	private:
		CMovingBitmap bg;
		CMovingBitmap scr;
		CMovingBitmap scr_ok;
		CMovingBitmap scr_cancel;

		CMovingBitmap scr_FS_yes;
		CMovingBitmap scr_FS_no;

		CMovingBitmap scr_FR;

		CMovingBitmap scr_SF_yes;
		CMovingBitmap scr_SF_no;

		CMovingBitmap scr_Vsync_yes;
		CMovingBitmap scr_Vsync_no;

		POINT p;
	};

	////////////////////////////////////////////////////////////////////////////
	//About�e��
	////////////////////////////////////////////////////////////////////////////
	class GameAbout : public CGameState {
	public:
		GameAbout(CGame* g);
		void OnBeginState();
		void OnInit();
		void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
		void OnMouseMove(UINT nFlags, CPoint point);
	protected:
		void OnShow();
	private:
		CMovingBitmap bg;
		CMovingBitmap scr_back;

		POINT p;
	};
}