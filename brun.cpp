#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "brun-Usage: brun <file.cpp>\n";
		return 0;    
	}
	
	std::string filename = argv[1];
	std::string output = "a.out";

	std::string compile_cmd = "g++ " + filename + " -o " + output;

	std::cout << "brun: Compiling...\n";
	int compile_result = system(compile_cmd.c_str());

	if (compile_result != 0) {
		std::cout << "brun: Compilation failed.\n";
		return 1;
	}

	std::cout << "brun: Running...\n\n";
	system(("./" + output).c_str());

	return 0;
}
