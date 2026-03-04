//-----------------------------------------------------------------------------------------------------------
// 한 학기 강의를 저장하는 함수
// 
// 2026/3/4																						송광민															
//-----------------------------------------------------------------------------------------------------------

#include "save.h"

void save(const std::string& fname)
{
	std::cout << '\"' << fname << "\" 저장합니다." << '\n';

	std::ifstream in{ fname };				// RAII


	if (not in) {
		std::cout << '\"' << fname << "\" - 열 수 없습니다." << '\n';
		exit(20260304);
	}

	std::ofstream out{ "2026 1학기 STL 화56수34.txt", std::ios::app };

	// 저장한 시간을 out에 기록하자
	//std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	// 시간을 한글로 작성한다면 어떻게 할지 따로 생각해봐라
	auto now = std::chrono::system_clock::now(); // deduction해서 auto로 쓰자

	auto UTC = std::chrono::system_clock::to_time_t(now);
	std::localtime(&UTC);
	using namespace std::chrono_literals; // using은 define을 대신하는 용도로 사용된다


	out << "======================================================================" << '\n';
	out << "저장시간 - " << now + 9h << '\n'; // c++ 14는 now가 오버로딩이 안됐다
	out << "======================================================================" << '\n';
	out << '\n';

	// in의 내용을 읽어서 out에 덧붙이자
	//std::copy(원본, 복사본);
	std::copy(std::istreambuf_iterator<char>{in}, {},
		std::ostream_iterator<char>{out});

	out << '\n';

}