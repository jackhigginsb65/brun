#include <iostream>
#include <string>
#include <cstdlib>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "brun-Usage: brun <file.c/cpp>\n";
		return 0;    
	}
	
	std::string filename = argv[1];
	std::string output = filename.substr(0, filename.find('.'));

	std::string compile_cmd;

	if (filename.find(".cpp") != std::string::npos) {
		compile_cmd = "g++ " + filename + " -o" + output;
	} else if (filename.find(".c") != std::string::npos) {
		compile_cmd = "gcc " + filename + " -o" + output;
	} else {
		std::cout << "brun: Source-code is not a C/C++ file\n";
		return 1;
	}

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
