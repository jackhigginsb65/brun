all:
	g++ brun.cpp -o brun
install:
	sudo mv brun /usr/local/bin/
clean:
	rm -f brun
