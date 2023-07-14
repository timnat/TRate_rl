#make bash file executable
#compile c++ code
CXX = g++
CXXFLAGS= -Wformat -O3

TRate_rl:
	chmod +x TRate_rl.sh

	$(CXX) -o $@ $(CXXFLAGS) TRate_rl.cpp
	
clean:
