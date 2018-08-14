#include "stdafx.hpp"
#include "Main.hpp"

int main(int argc, char *argv[])
{
	CMain* cmain = new CMain(1920, 1080);

	cmain->GameLoop();

	return 0;
}
