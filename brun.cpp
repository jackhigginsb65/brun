#include <iostream>
#include <string>
#include <cstdlib>

#define BRUN_MSG "\033[31m[brun]\033[0m "

int run(const std::string& cmd, bool verbose) {
	if (verbose) {
		std::cout << BRUN_MSG << cmd << "\n";
	}
	return system(cmd.c_str());
}

int brunprocess(bool del, bool conly, bool verbose, const std::string& filename) {
	std::string compile_cmd, output;

	if (filename.find(".") == std::string::npos) {
		std::cout << BRUN_MSG << "Error; Invalid filename '" << filename << "'. Check spelling?\n";
		return 1;
	} else {
		output = filename.substr(0, filename.find_last_of('.'));
	}

	if (filename.size() >= 4 && filename.substr(filename.size() - 4) == ".cpp" || filename.substr(filename.size() - 4) == ".cxx" || filename.substr(filename.size() - 3) == ".cc") {
		compile_cmd = "g++ " + filename + " -o " + output;
	} else if (filename.size() >= 2 && filename.substr(filename.size() - 2) == ".c") {
		compile_cmd = "gcc " + filename + " -o " + output;
	} else {
		std::cout << BRUN_MSG << "Source-code is not a C/C++ file\n";
		return 1;
	}

	std::cout << BRUN_MSG << "Compiling...\n";
	int compile_result = run(compile_cmd, verbose);

	if (compile_result != 0) {
		std::cout << BRUN_MSG << "Compilation failed.\n";
		return 1;
	}

	if (del) {
		std::cout << BRUN_MSG << "Running...\n";
		run("./" + output, verbose);
		run("rm " + output, verbose);
		return 0;
	}
	if (!conly) {
		std::cout << BRUN_MSG << "Running...\n";
		run("./" + output, verbose);
	}
	return 0;
}

void help() {
	std::cout <<
		"brun - Basic Run\n\n"
		"Compile and run C/C++ source files quickly\n\n"
		"Usage:\n"
		"   brun [options] <file>\n\n"
		"Options\n"
		"   -c    Compile only\n"
		"   -d    Delete executable after running\n"
		"   -v    Verbose mode, for debugging\n\n"
		"   --help      Display help page\n"
		"   --version   Display version\n\n"
		"Supported files:\n"
		"   .c     (compiles with gcc)\n"
		"   .cpp   (compiles with g++)\n\n"
		"   If compilation fails, brun will stop and display the compiler errors\n\n"
		"Examples:\n"
		"   brun hello.cpp\n"
		"   brun -d program.c\n"
		"   brun -v hello.cpp -c\n\n"
		"Project:\n"
		"   https://github.com/jackhigginsb65/brun\n";
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << BRUN_MSG << "Usage: brun <file.c/cpp>\n";
		return 0;    
	}
	bool del = false, conly = false, verbose = false;
	
	const std::string version = "2.3.2";
	std::string filename;

	for (int i = 1; i < argc; i++) {
		std::string arg = argv[i];

		if (arg == "--help" || arg == "-h") {
			help();
			return 0;
		} else if (arg == "--version") {
			std::cout << BRUN_MSG << "version " << version << "\n";
			return 0;	
		} else if (arg == "-c" || arg == "-C") {
			conly = true;
		} else if (arg == "-v" || arg == "-V") {
			verbose = true;
		} else if (arg == "-d" || arg == "-D") {
			del = true;
		} else {
			filename = arg;
		}
	}
	if (filename.empty()) {
		std::cout << BRUN_MSG << "No file specified\n";
		return 1;
	}
	brunprocess(del, conly, verbose, filename);
}
