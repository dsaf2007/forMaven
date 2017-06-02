#include <iostream>
#include <time.h>

class hypothesis
{
public:
	float a, b;

	hypothesis()
		:a(0.0f), b(0.0f)
	{

	}

	float gety(const float& x_input)
	{
		return a*x_input + b;
	}
};

class hypothesis2
{
public:
	float a, b, c;

	hypothesis2()
		:a(1.0f), b(1.0f), c(1.0f)
	{

	}

	float gety(const float& x_input)
	{
		return a*x_input*x_input + b*x_input + c;
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
	hypothesis lh;
	hypothesis2 lh2;

	float x_data[100000];
	float y_data[100000];
	

	for (int i = 0; i < 100000; i++)
	{
		x_data[i] = getRandomNumber(0.0f,2.0f);
		y_data[i] = 3.0*x_data[i] + 1 + rand() / RAND_MAX;
	}
	const double lr = 000000000.1;

	for (int tr = 0; tr < 10; tr++)
	{
		for (int i = 0; i < 100000; i++)
		{
			//error=정답-실제나온값.
			const double error = y_data[i] - lh.gety(x_data[i]);
			const double sqr = 0.5*error*error;

			//2번 문제에 대한 error
			const double error2 = y_data[i] - lh2.gety(x_data[i]);
			const double sqr2 = 0.5*error2*error2;
			//1번 문제에 대한 a,b값의 미분
			const double dse_da = 2.0*error*-x_data[i];
			const double dse_db = 2.0*error*-1;
			//2번 문제에 대한 a,b,c 값에 대한 미분
			const double dse_da2 = 2.0*error2*-x_data[i] * x_data[i];
			const double dse_db2 = 2.0*error2*-x_data[i];
			const double dse_dc2 = 2.0*error2*-1;
			//선형하강법.
			lh.a -= dse_da*lr;
			lh.b -= dse_db*lr;

			lh2.a -= dse_da2*lr;
			lh2.b -= dse_db2*lr;
			lh2.c -= dse_dc2*lr;

		
		}

	}std::cout << "추론된 lh의 a값과 b값과 gety(2.5)을 출력합니다" << std::endl;
	std::cout << "a:" << lh.a << " " << "b:" << lh.b << " "<<lh.gety(2.5)<<std::endl;
	std::cout<<std::endl;
	
	std::cout << "추론된 lh2의 a값과 b값과 c값 그리고 gety(2.5)을 출력합니다" << std::endl;
	std::cout << "a:" << lh2.a << " " << "b:" << lh2.b << " " << "c:" << lh2.c << " " << lh.gety(2.5) << std::endl;
	
}