//-----------------------------------------------------------------------------------------------------------
// 한 학기 강의를 저장하는 함수
// 
// 2026/3/4																						송광민															
//-----------------------------------------------------------------------------------------------------------

#include "save.h"
#include <format>
#include <string_view>

void save(const std::string& fname)
{
	std::cout << '\"' << fname << "\" 저장합니다." << '\n';

	std::ifstream in{ fname };				// RAII


	if (not in) {
		std::cout << '\"' << fname << "\" - 열 수 없습니다." << '\n';
		exit(20260304);
	}

	std::ofstream out{ "2026 1학기 STL 화56수34.txt", std::ios::app };

	auto now = std::chrono::system_clock::now();
	auto local = std::chrono::current_zone()->to_local(now);
	
	// 요일 계산을 위해 날짜 추출
	auto today = std::chrono::floor<std::chrono::days>(local);
	std::chrono::weekday wd{ today };
	
	constexpr std::string_view weekdays[] = { "일요일", "월요일", "화요일", "수요일", "목요일", "금요일", "토요일" };

	out << "======================================================================" << '\n';
	out << "저장시간 - " 
	    << std::format("{:%Y년 %m월 %d일} ", local)
	    << weekdays[wd.c_encoding()]
	    << std::format(" {:%H시 %M분 %S초}", local) << '\n';
	out << "======================================================================" << '\n';
	out << '\n';

	std::copy(std::istreambuf_iterator<char>{in}, {},
		std::ostream_iterator<char>{out});

	out << '\n';

}