#make bash file executable
#compile c++ code
CXX = g++
CXXFLAGS= -Wformat -O3

TR_rl:
	chmod +x TRate_rl.sh

	$(CXX) -o $@ $(CXXFLAGS) TR_rl.cpp
	
clean:
