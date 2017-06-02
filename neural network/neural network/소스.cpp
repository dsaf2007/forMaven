#include <iostream>
#include <time.h>

class layer1
{
public:
	float a0, b0;

	layer1()
		:a0(1.0f), b0(0.0f)
	{

	}

	float gety(const float& x_input)
	{
		return a0*x_input + b0;
	}
};

class layer2
{
public:
	float a1, b1;

	class layer2()
		:a1(0.0f), b1(0.0f)
	{

	}

	float gety(const float& x_input)
	{
		return a1*x_input + b1;
	}
};


float getRandomNumber(const float min, const float max)
{
	float temp = (float)rand() / (float)RAND_MAX;

	temp = min + (max - min)*temp;

	return temp;
}
void main()
{

	srand((unsigned int)time(NULL));
	layer1 lh;
	layer2 lh2;

	float x_data[5] = { 0.1,0.2,0.3,0.4,0.5 };
	float y_data[5] = { 4,5,6,7,8 };



	const double lr = 0.001;

	for (int tr = 0; tr < 10000; tr++)
	{
		for (int i = 0; i < 5; i++)
		{

			const double error2 = y_data[i] - lh2.gety(lh.gety(x_data[i]));
			const double sqr2 = 0.5*error2*error2;

			const double dse_da1 = 1.0*error2*-lh.gety(x_data[i]);
			const double dse_db1 = 1.0*error2*-1;

			const double dse_da0 = 1.0*error2*-lh2.a1*x_data[i];
			const double dse_db0 = 1.0*error2*-(lh2.a1);

			lh2.a1 -= dse_da1*lr;
			lh2.b1 -= dse_db1*lr;

			lh.a0 -= dse_da0*lr;
			lh.b0 -= dse_db0*lr;

			


		}
	}


	std::cout << "a:" << lh.a0 << " " << "b:" << lh.b0 << " " << lh.gety(0.6) << std::endl;
	std::cout << std::endl;

	
	std::cout << "a:" << lh2.a1*lh.a0 << " " << "b:" << lh2.a1*lh.b0+lh2.b1 <<" "<< lh2.gety(lh.gety(0.7)) << std::endl;

}
