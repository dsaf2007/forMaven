/////////////////////////////////////////////////////////////////////////////
// Authored by Jeong-Mo Hong for CSE4060 course at Dongguk University CSE  //
// jeongmo.hong@gmail.com                                                  //
// Do whatever you want license.                                           //
/////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "NeuralNetwork.h"

void main()
{
	VectorND< VectorND<D> > x_input_arr;
	x_input_arr.initialize(4);
	x_input_arr[0].initialize(2);
	x_input_arr[0][0] = 0.0; x_input_arr[0][1] = 0.0;

	x_input_arr[1].initialize(2);
	x_input_arr[1][0] = 0.0; x_input_arr[1][1] = 1.0;

	x_input_arr[2].initialize(2);
	x_input_arr[2][0] = 1.0; x_input_arr[2][1] = 0.0;

	x_input_arr[3].initialize(2);
	x_input_arr[3][0] = 1.0; x_input_arr[3][1] = 1.0;

	VectorND< VectorND<D> >y_target_arr(4);
	y_target_arr[0].initialize(2);
	y_target_arr[0][0] = 0.0f; y_target_arr[0][1] = 0.0f;

	y_target_arr[1].initialize(2);
	y_target_arr[1][0] = 1.0f; y_target_arr[1][1] = 1.0f;

	y_target_arr[2].initialize(2);
	y_target_arr[2][0] = 1.0f; y_target_arr[2][1] = 1.0f;

	y_target_arr[3].initialize(2);
	y_target_arr[3][0] = 0.0f; y_target_arr[3][1] = 0.0f;

	/*VectorND<D>y_target_arr(4);
	y_target_arr[0] = 0.0;
	y_target_arr[1] = 1.0;
	y_target_arr[2] = 1.0;
	y_target_arr[3] = 0.0;*/


	VectorND<D> y_temp(4);

	NeuralNetwork nn_;
	nn_.initialize(2, 2, 1);
	nn_.alpha_ = 0.1;

	for (int i = 0; i < 1000; i++)
	{
		for (int e = 0; e < 4; e++)
		{
			nn_.setInputVector(x_input_arr[e]);
			nn_.propForward();

			nn_.copyOutputVector(y_temp);
			std::cout << y_target_arr[e] << "!!! " << y_temp << std::endl;

			nn_.propBackward(y_target_arr[e]);
		} std::cout << std::endl;
	}

	VectorND< VectorND<D> > test_data(4);
	test_data[0].initialize(2);
	test_data[0][0] = 0.5; test_data[0][1] = 0.5;

	test_data[1].initialize(2);
	test_data[1][0] = 0.7; test_data[1][1] = 0.8;

	test_data[2].initialize(2);
	test_data[2][0] = 0.8; test_data[2][1] = 0.7;

	test_data[3].initialize(2);
	test_data[3][0] = 0.1; test_data[3][1] = 1000;

	std::cout << "end step 1" << std::endl << std::endl;

	std::cout << "start step2" << std::endl << std::endl;

	for (int e = 0; e < 4; e++)
	{
		nn_.setInputVector(test_data[e]);
		nn_.propForward();
		nn_.copyOutputVector(y_temp);
		std::cout << y_temp << std::endl;
	}



}
