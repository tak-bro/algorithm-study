class Ball
{
	public: static int maxBall(int v0) {
			double g = 9.81;
			double h = 0;
			double hd = 0;
			double t = 0;
			int tans = 0;
			while (true) {
				h = double(v0)*1000/60/60*t - 0.5*g*t*t;
				t = t+0.1;

				if (h<hd) {
					return tans-1;
				}

				tans = tans+1;
				hd = h;
			}
		}
};
