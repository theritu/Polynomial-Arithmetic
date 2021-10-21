

CC = g++
all: polynomialTestApp
 
polynomialTestApp: polynomialTestApp.o
	$(CC) $^ $(LDFLAGS) -o $@

polynomialTestApp.o: polynomialTestApp.cpp Terms.h Node.h Node.tcc Polynomial.h Polynomial.tcc
	$(CC) -std=c++11 -c $< -o $@ 

clean:
	rm -rf *.o
	rm polynomialTestApp