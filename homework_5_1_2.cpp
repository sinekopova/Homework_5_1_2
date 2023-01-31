#include <algorithm>
#include <iostream>
#include <variant>
#include <vector>
#include <utility>


std::variant<int, std::string, std::vector<int>> get_variant();

int main()
{
	auto result = get_variant();

	if ( std::holds_alternative<std::vector<int>>(result) ) {
		auto v = std::get<std::vector<int>>(result);
		std::for_each(v.begin(), v.end(), [](const int& val) { std::cout << val << " "; });
		std::cout << std::endl;
	}
	else {
		auto ptr = std::get_if<int>(&result);
		if (ptr != nullptr) {
			std::cout << *ptr * 2 << "\n";
		}
		else {
			std::cout << std::get<std::string>(result) << "\n";
		}
	}
}

std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}
