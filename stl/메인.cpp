//------------------------------------------------------
// 2026 1학기 화56수34                 3월 3일          (1주 1일)
//------------------------------------------------------
// vs버전 - 17.14.27 (추가로 업데이트 해야 함)
// 컴파일 환경 - Release / x64
// 프로젝트 설정 - 일반 - /std::c++lastest
//			   - c/c++ - SDL 설정 - 아니요
// -----------------------------------------------------
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

void save(const std::string& ); // 함수의 선언문: 이름, 인자의 타입과 개수, 반환되는 타입

//--------
int main()
//--------
{
	std::cout << "2026년 3월 3일" << '\n';
	// c++ 표준 상에서는 retrun 0;이 없어도 0을 반환, 안넣는게 표준

	

	save("메인.cpp");						// "메인.cpp"를 저장
}

void save(const std::string& fname)
{
	std::cout << '\"' << fname << "\" 저장합니다." << '\n';

	std::ifstream in{ fname };				// RAII

	if (not in) {
		std::cout << '\"' << fname << "\" - 열 수 없습니다." << '\n';
		exit(20260303);
	}

	char c;
	in >> std::noskipws;						// 공백도 읽어들임
	while (in >> c)
		std::cout << c;
}