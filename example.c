#include "easylog.h"

int main(int argc, char *argv[])
{
	printf("writing 3 lines to " ELDEFAULTLOGDIR " DEBUG INFO VERBOSE\n");

	int i;
	for (i = 0; i < 3; ++i) {
		easylog("DEBUG", "%s", "Testing the debug messages");
		easylog("INFO", "%s", "Testing the info messages");
		easylog("VERBOSE", "%s", "Testing the verbose messages");
	}
	return 0;
}
