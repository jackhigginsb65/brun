
brun (Basic Run) is a simple and lightweight CLI tool that compiles and runs C/C++ files.

![brun logo](assets/logo.png)

## Build, installation, and cleanup

Run the commands: make -> sudo make install -> make clean

## Usage and flags

brun works similarily to compiling with gcc, 'brun example.c' is nearly equivalent to 'gcc example.c -o example',
the only difference being is that brun will automatically run the program after compilation (unless -c flag is present)

brun has two flags that can be applied anywhere in the command.
    -d  ;  delete compiled file after running it
    -c  ;  only compiles and doesn't run the program

Example: brun -c example.cpp

## Extra

If you include both flags in the command, only -d will apply

Note from creator: -d is especially useful, think of it as a quick run feature :)

## Questions or suggestions?

Contact me at jackhigginsb65@gmail.com
