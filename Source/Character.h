#ifndef _CHARACTER_
#define _CHARACTER_

#define STEP   4
namespace game_framework {
	class Character {
	private:
		CAnimation Character_down;	// �}��V�U���ʵe
		CAnimation Character_up;
		CAnimation Character_left;
		CAnimation Character_right;
		int  Animate_State;         // �}�Ⲿ�ʪ��A 1���U 2���W 3���� 4���k
		int  x, y;					// �}�⥪�W���y��
		int  move_step = STEP;      // �}��B��
		int  Explosion_range;       // �̤j�z���Z��
		bool isMovingDown;			// �O�_���b���U����
		bool isMovingLeft;			// �O�_���b��������
		bool isMovingRight;			// �O�_���b���k����
		bool isMovingUp;			// �O�_���b���W����
		int  map_simple[13][15];
		int  map[416][480];
		bool isMoveable(int, int);
		// int health;
		// int *Bombs;
		// int life;
	public:
		Character();
		int  GetX1();					// �}�⥪�W�� x �y��
		int  GetY1();					// �}�⥪�W�� y �y��
		int  GetX2();					// �}��k�U�� x �y��
		int  GetY2();					// �}��k�U�� y �y��
		int  GetStep();                 // �}��B��
		int  GetRange();                // �z���Z��
		void Initialize(int nx, int ny);// �]�w�}�⬰��l�� �藍�P�}��]�w��l��m
		void LoadBitmap();				// ���J�ϧ�
		void OnMove();					// ���ʸ}��
		void OnShow();					// �N�}��ϧζK��e��
		void SetMovingDown(bool flag);	// �]�w�O�_���b���U����
		void SetMovingLeft(bool flag);	// �]�w�O�_���b��������
		void SetMovingRight(bool flag); // �]�w�O�_���b���k����
		void SetMovingUp(bool flag);	// �]�w�O�_���b���W����
		void SetXY(int nx, int ny);		// �]�w�}�⥪�W���y��
		void SetRange(int);             // �]�w�z���Z��
		void LoadMap(int maps[13][15]);
		int  GetPosition(int, int);
	};
}

#endif // !_CHARACTER_