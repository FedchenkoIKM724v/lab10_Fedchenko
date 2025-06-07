#include <iostream>
#include "windows.h";

#include <string>;

struct Faculty {
	std::string name;
	int num;
};
void print_data(Faculty faculty) {
	std::cout << "Faculty: " << faculty.name << ", Academic debt: " << faculty.num << "\n";
}
Faculty print_max(Faculty *faculties, int num) {
	Faculty max = faculties[0];
	for (int i = 1; i < num; i++) {
		if (faculties[i].num > max.num) {
			max = faculties[i];
		}
		
	}
	return max;
}
Faculty print_min(Faculty* faculties, int num) {
	Faculty min = faculties[0];
	for (int i = 1; i < num; i++) {
		if (faculties[i].num < min.num) {
			min = faculties[i];
		}
	}
	return min;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int num1;
	std::cout << "Enter amount of faculties: ";
	std::cin >> num1;
	Faculty* faculties = new Faculty[num1];
	for (int i = 0; i < num1; i++) {
		std::cout << "Enter the name of " << i+1 <<" faculty: \n";
		std::cin >> faculties[i].name;
		std::cout << "Enter the amount of academic debt: \n";
		std::cin >> faculties[i].num;
	}
	for (int i = 0; i < num1; i++) {
		print_data(faculties[i]);
	}
	Faculty max_faculty = print_max(faculties, num1);
	Faculty min_faculty = print_min(faculties, num1);
	std::cout << "Faculty with max academic debt: ";
	print_data(max_faculty);
	std::cout << "Faculty with min academic debt: ";
	print_data(min_faculty);
	
	delete[] faculties;
	return 0;
}