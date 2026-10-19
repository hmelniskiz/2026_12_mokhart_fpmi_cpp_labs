#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> slova(std::string& s) {
	std::string s1;
	std::vector <std::string> slv;
	size_t begin = 0;
	size_t end = s.find_first_of(" ");
	while (end != std::string::npos) {
		s1 = s.substr(begin, end - begin);
		slv.push_back(s1);
		begin = end + 1;
		end = s.find_first_of(" ", begin);
		if (end == std::string::npos) {
			end = s.size();
			s1 = s.substr(begin, end - begin);
			slv.push_back(s1);
			break;
		}
	}
	return slv;
}

int main() {
	std::cout << "Vvedite stroky" << std::endl;
	std::string s;
	std::vector <std::string> slov;
	getline(std::cin, s);
	slov = slova(s);

	for (int i = 0; i < slov.size(); i++) {
		for (int j = 0; j < slov.size() - 1 - i; j++) {
			if (slov[i].size() > slov[i + 1].size())
				std::swap(slov[i], slov[i + 1]);
			else if (slov[i].size() == slov[i + 1].size()) {
				if (slov[i] > slov[i + 1]) {
					std::swap(slov[i], slov[i + 1]);
				}
			}
		}
	}


	for (int i = 0; i < slov.size(); i++) {
		std::cout << slov[i] << std::endl;
	}
	return 0;
}