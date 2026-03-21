#include <iostream>
#include <string>
#include <cstdlib>

std::string runCommand() {
	return 0;
}	

int brunprocess(bool del, bool conly, const std::string& filename, std::string& output) {
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

	if (del == true) {
		std::cout << "brun: Running...\n";
		system(("./" + output).c_str());
		system(("rm " + output).c_str());
		return 0;
	}
	if (conly == false) {
		system(("./" + output).c_str());
	}
	return 0;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "brun-Usage: brun <file.c/cpp>\n";
		return 0;    
	}

	bool del = false, conly = false;

	std::string filename;

	for (int i = 1; i < argc; i++) {
		std::string currentArg = argv[i];

		if (currentArg.front() != '-') {
			filename = currentArg;
		} else {
			if (currentArg == "-c" || currentArg == "-C") {
				conly = true;
			}
			if (currentArg == "-d" || currentArg == "-D") {
				del = true;
			}
		}
	}

	std::string output;

	if (filename.find(".") == std::string::npos) {
		std::cout << "brun: Error; Invalid filename '" << filename << "'. Check spelling?\n";
		return 1;
	} else {
		output = filename.substr(0, filename.find('.'));
	}
	brunprocess(del, conly, filename, output);
}
