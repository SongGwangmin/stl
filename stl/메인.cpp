//------------------------------------------------------
// 2026 1학기 화56수34                 3월 4일          (2주 1일)
//------------------------------------------------------
// 많은 자료를 처리하기
// -----------------------------------------------------
#include <iostream>
#include <random>
using namespace std;

#include "save.h"


default_random_engine dre;
uniform_int_distribution<int> uid{ 0, 999'9999 }; // 클래스인데도 <int> 뺄 수 있다



//--------
int main()
//--------
{
	// [문제] "int값1000만개.txt"에 저장한 int값을 읽어 화면에 저장하라

	std::ifstream in{ "int값1000만개.txt" };

	if (not in) {
		std::cout << "\" - 열 수 없습니다." << '\n';
		exit(20260304);
	}

	char n;
	while (in >> n) {
		cout << n;
	}

	save("메인.cpp");
}

