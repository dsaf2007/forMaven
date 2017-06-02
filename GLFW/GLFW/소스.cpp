#include <iostream>
#include <vector>
#include <stdlib.h>
#include <GLFW/glfw3.h>
#include <algorithm>
#include "drawfunction.h"




class geometricobject
{
public:
	int start_x, start_y, end_x, end_y;
	int x0, y0, radius;

	void(geometricobject::*callback_)() = nullptr;

	void exec()
	{
		if (callback_ != nullptr)
			(this->*callback_)();
	}

	void drawbox()
	{
		drawLine(start_x, start_y, end_x, start_y, 1.0f, 0.0f, 0.0f);
		drawLine(start_x, start_y, start_x, end_y, 1.0f, 0.0f, 0.0f);
		drawLine(start_x, end_y, end_x, end_y, 1.0f, 0.0f, 0.0f);
		drawLine(end_x, start_y, end_x, end_y, 1.0f, 0.0f, 0.0f);
	}

	void drawcircle()
	{
		int err = 0;
		int x = radius;
		int y = 0;
		while (x > y)
		{
			drawPixel(x0 + x, y0 + y, 1.0f, 0.0f, 0.0f);
			drawPixel(x0 + y, y0 + x, 1.0f, 0.0f, 0.0f);
			drawPixel(x0 - y, y0 + x, 1.0f, 0.0f, 0.0f);
			drawPixel(x0 - x, y0 + y, 1.0f, 0.0f, 0.0f);
			drawPixel(x0 - x, y0 - y, 1.0f, 0.0f, 0.0f);
			drawPixel(x0 - y, y0 - x, 1.0f, 0.0f, 0.0f);
			drawPixel(x0 + y, y0 - x, 1.0f, 0.0f, 0.0f);
			drawPixel(x0 + x, y0 - y, 1.0f, 0.0f, 0.0f);

			y += 1;
			err += 1 + 2 * y;
			if (2 * (err - x) + 1 > 0)
			{
				x -= 1;
				err += 1 - 2 * x;
			}
		}
	}



};

	int main(void)
	{


		GLFWwindow* window;

		geometricobject circle1;
		circle1.x0 = 150;
		circle1.y0 = 150;
		circle1.radius = 100;
		circle1.callback_ = &geometricobject::drawcircle;

		geometricobject box1;
		box1.start_x = 100; box1.start_y = 100; box1.end_x = 200; box1.end_y = 200;
		box1.callback_ = &geometricobject::drawbox;

		geometricobject box2;
		box2.start_x = 300; box2.start_y = 100; box2.end_x = 400; box2.end_y = 200;
		box2.callback_ = &geometricobject::drawbox;

		geometricobject box3;
		box3.start_x = 280; box3.start_y = 80; box3.end_x = 420; box3.end_y = 220;
		box3.callback_ = &geometricobject::drawbox;

		std::vector<geometricobject*>obj_list;

		obj_list.push_back(new geometricobject(box1));
		obj_list.push_back(new geometricobject(circle1));
		obj_list.push_back(new geometricobject(box2));
		obj_list.push_back(new geometricobject(box3));


		/* Initialize the library */
		if (!glfwInit())
			return -1;

		/* Create a windowed mode window and its OpenGL context */
		window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
		if (!window)
		{
			glfwTerminate();
			return -1;
		}

		/* Make the window's context current */
		glfwMakeContextCurrent(window);




		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window))
		{
			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT);
			std::fill_n(pixels, width*height * 3, 1.0f);

	
			for (auto itr : obj_list)
			{
				itr->exec();
			}


			glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		}

		delete[] pixels;
		/*delete[] my_object;*/
		glfwTerminate();
		return 0;

	}
