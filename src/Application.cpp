﻿#include "SDL_Local.h"
#include "Huffman.h"
#include "RGB12.h"
#include "InputHandler.h"

#include <iostream>
#include <array>
#include <string>

int main(int argc, char *argv[])
{
	InputHandler real(argc, argv);

	auto test = real.get("test");
	if (!test.empty() && test[0] == "InputHandler")
	{
		char **arr = new char*[9];
		arr[0] = "exe.xd";
		arr[1] = "obrazek.bmp";
		arr[2] = "-input";
		arr[3] = "obrazek2.bmp";
		arr[4] = "-output";
		arr[5] = "obrazek";
		arr[6] = "-alg";
		arr[7] = "Huffman";
		arr[8] = "-grayscale";
		InputHandler cli(9, arr);
		cli.print();
	}

	// Initialize SDL
	try
	{
		SDL sdl(SDL_INIT_VIDEO | SDL_INIT_TIMER);
	}
	catch (const RuntimeError &err)
	{
		std::cerr << "Error while initializing SDL:  " << err.what() << std::endl;
		return 1;
	}

	/*if (cli.option("open"))
	{
		std::string filename;
		while (cli.get(filename))
		{
			// VERY SIMPLE OPENING
			BMP bmp;
			bmp.load(filename);
			if (bmp.image.empty())
			{
				RGB12 rgb;
				rgb.load(filename);
				rgb.preview();
			}
			else bmp.preview();
		}
	}*/

	#ifndef  __linux
		system("PAUSE");
	#endif // ! __linux

	// Return sucess
	return EXIT_SUCCESS;
}
