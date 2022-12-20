all:principal selectSort bubbleSort

principal:principal.cc
	g++ -o principal principal.cc

selectSort:selectSort.cc
	g++ -o selectSort selectSort.cc

bubbleSort:bubbleSort.cc
	g++ -o bubbleSort bubbleSort.cc