namespace game_framework {
	class CoinsAnimation {
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
		CAnimation glod;
		bool Active, exp;     //00���� 11���� 10����
		int x, y;
	};
}
