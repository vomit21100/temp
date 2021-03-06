#ifndef _CHARACTER_
#define _CHARACTER_

#define STEP   4
namespace game_framework {
	class Character {
	private:
		CAnimation Character_down;	// 腳色向下的動畫
		CAnimation Character_up;
		CAnimation Character_left;
		CAnimation Character_right;
		int  Animate_State;         // 腳色移動狀態 1為下 2為上 3為左 4為右
		int  x, y;					// 腳色左上角座標
		int  move_step = STEP;      // 腳色步數
		int  Explosion_range;       // 最大爆炸距離
		bool isMovingDown;			// 是否正在往下移動
		bool isMovingLeft;			// 是否正在往左移動
		bool isMovingRight;			// 是否正在往右移動
		bool isMovingUp;			// 是否正在往上移動
		int  map_simple[13][15];
		int  map[416][480];
		bool isMoveable(int, int);
		// int health;
		// int *Bombs;
		// int life;
	public:
		Character();
		int  GetX1();					// 腳色左上角 x 座標
		int  GetY1();					// 腳色左上角 y 座標
		int  GetX2();					// 腳色右下角 x 座標
		int  GetY2();					// 腳色右下角 y 座標
		int  GetStep();                 // 腳色步數
		int  GetRange();                // 爆炸距離
		void Initialize(int nx, int ny);// 設定腳色為初始值 對不同腳色設定初始位置
		void LoadBitmap();				// 載入圖形
		void OnMove();					// 移動腳色
		void OnShow();					// 將腳色圖形貼到畫面
		void SetMovingDown(bool flag);	// 設定是否正在往下移動
		void SetMovingLeft(bool flag);	// 設定是否正在往左移動
		void SetMovingRight(bool flag); // 設定是否正在往右移動
		void SetMovingUp(bool flag);	// 設定是否正在往上移動
		void SetXY(int nx, int ny);		// 設定腳色左上角座標
		void SetRange(int);             // 設定爆炸距離
		void LoadMap(int maps[13][15]);
		int  GetPosition(int, int);
	};
}

#endif // !_CHARACTER_