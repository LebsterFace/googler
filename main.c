#include "./utils.h"

int main(int argc, char* argv[]) {
	if (argc < 1) return 0;
	char* encoded = urlencode(get_arguments(argc, argv));

	char* command = "start https://www.google.com/search?q=";
	char* concatenated = malloc(strlen(command) + strlen(encoded) + 1);
	strcpy(concatenated, command);
	strcat(concatenated, encoded);
	
	system(concatenated);
}