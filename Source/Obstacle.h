namespace game_framework {
	class Obstacle {
	public:
		void Initialize();
		void Initialize(int, int);
		void LoadBitmap();
		void OnMove();
		void OnShow();
		void setActive();
		//void setExp(bool);
		void setTopLeft(int, int);
		bool getActive();
		bool getExp();
	private:
		CAnimation block;
		bool Active, exp;     //00���� 11�z���ʵe 10����
		int x, y;
	};
}