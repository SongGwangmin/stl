//------------------------------------------------------
// 2026 1학기 화56수34                 3월 4일          (1주 2일)
//------------------------------------------------------
// template
// -----------------------------------------------------
#include <iostream>

#include "save.h"
using namespace std; // 강의를 위해 어쩔 수 없이 사용

class Dog{
public:
	Dog() = default;
	Dog(const Dog& d) { // 만들 필요가 없었다. 컴파일러가 만들어주는 복사 생성자가 완벽하게 작동하기 때문이다.
				age = d.age;
	}

	Dog(int a) : age{ a } {}
	
	Dog& operator=(const Dog& d) { // 만들 필요가 없었다. 컴파일러가 만들어주는 복사 대입 연산자가 완벽하게 작동하기 때문이다.
				age = d.age;
				return *this;
	}

	friend std::ostream& operator << (std::ostream& out, const Dog& d)
	{
		out << d.age;

		return out;
	}

	


private:
	int age{};

};

void change(int& x, int& y) // 레퍼런스 가면을 씌우면 코드가 깔끔해진다
{
	int temp{ x };
	x = y;
	y = temp;
}

void change(Dog& x, Dog& y)
{
	Dog temp{ x };
	x = y;
	y = temp;
}

//--------
int main()
//--------
{
	{
		int a{ 1 }, b{ 2 };
		// [문제] change를 호출해서 다음과 같이 출력되게 하라

		change(a, b);

		cout << a << ", " << b << endl; // 2, 1
	}

	{
		Dog a{ 1 }, b{ 2 };
		// [문제] change를 호출해서 다음과 같이 출력되게 하라

		change(a, b);

		cout << a << ", " << b << endl; // 2, 1
	}


	save("메인.cpp");
}