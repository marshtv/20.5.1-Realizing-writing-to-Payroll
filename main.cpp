#include <fstream>
#include <iostream>
#include <string>

int main() {
	char proceed = 'y';
	std::string first_name, last_name, date, currency = "RUB";
	int payment;
	std::ofstream payroll_file("F:\\__C++\\Skillbox\\20\\20.5.1 Realizing writing to Payroll\\Files\\payroll.txt", std::ios::app);

	std::cout << "Please, input first data to payroll!" << std::endl;

	while (proceed == 'y') {
		std::cout << "----------------------------------------------------" << std::endl;
		std::cout << "First name:";
		std::cin >> first_name;
		payroll_file.width(10);
		payroll_file << first_name;
		std::cout << "Last name:";
		std::cin >> last_name;
		payroll_file.width(15);
		payroll_file << last_name;
		std::cout << "Date (DD.MM.YYYY):";
		std::cin >> date;
		while (	std::stoi(date.substr(0, 2)) <= 0 ||
				std::stoi(date.substr(0, 2)) > 31 ||
				std::stoi(date.substr(3, 2)) <= 0 ||
				std::stoi(date.substr(3, 2)) > 12 ||
				std::stoi(date.substr(6, 4)) > 2022 ) {
			std::cout << "ERROR format of date! Please, try again!" << std::endl;
			std::cout << "Date (DD.MM.YYYY):";
			std::cin >> date;
		}
		payroll_file.width(12);
		payroll_file << date;
		std::cout << "Payment:";
		std::cin >> payment;
		payroll_file.width(10);
		payroll_file << payment << " " << currency << std::endl;

		std::cout << "----------------------------------------------------" << std::endl;
		std::cout << "Do you want to proceed input data to payroll? (y/n):" << std::endl;
		std::cin >> proceed;
	}
	payroll_file.close();

	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "Good by!" << std::endl;
	return 0;
}
