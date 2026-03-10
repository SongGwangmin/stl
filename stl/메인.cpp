//------------------------------------------------------
// 2026 1학기 화56수34                 3월 4일          (2주 1일)
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

template <class T> // 템플릿 선언
void change(T& x, T& y) // 템플릿 정의 - 동시에 해야 함
{
	T temp{ x };
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