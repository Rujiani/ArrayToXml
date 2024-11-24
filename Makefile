default:
	g++ main.cpp ArrayToXml.cpp CheckInput.cpp -O3 -o convertor -std=c++20
debug:
	g++ main.cpp ArrayToXml.cpp CheckInput.cpp -g -o convertor_debug -std=c++20
