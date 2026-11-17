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
		if (!s1.empty()) {
			slv.push_back(s1);
		}
		begin = end + 1;
		end = s.find_first_of(" ", begin);
	}
	end = s.size();
	s1 = s.substr(begin, end - begin);
	slv.push_back(s1);
	return slv;
}

void slov_sort_vozr(std::vector<std::string>& slov) {
	for (int i = 0; i < slov.size(); i++) {
		for (int j = 0; j < slov.size() - 1 - i; j++) {
			if (slov[j].size() > slov[j + 1].size())
				std::swap(slov[j], slov[j + 1]);
			else if (slov[j].size() == slov[j + 1].size()) {
				if (slov[j] > slov[j + 1]) {
					std::swap(slov[j], slov[j + 1]);
				}
			}
		}
	}
}

void slov_sort_ubiv(std::vector<std::string>& slov) {
	for (int i = 0; i < slov.size(); i++) {
		for (int j = 0; j < slov.size() - 1 - i; j++) {
			if (slov[j].size() < slov[j + 1].size())
				std::swap(slov[j], slov[j + 1]);
			else if (slov[j].size() == slov[j + 1].size()) {
				if (slov[j] < slov[j + 1]) {
					std::swap(slov[j], slov[j + 1]);
				}
			}
		}
	}
}

int main() {
	std::cout << "Vvedite stroky" << std::endl;
	std::string s, vybor;
	std::vector <std::string> slov;
	getline(std::cin, s);
	std::cout << "Vyberite po vozrastaniu ili ubybaniu" << std::endl;
	std::cin >> vybor;
	slov = slova(s);
	if (vybor == "vozrastaniu") {
		slov_sort_vozr(slov);
	}
	else if (vybor == "ubybaniu") {
		slov_sort_ubiv(slov);
	}
	else {
		std::cout << "error";
		return 1;
	}
	for (int i = 0; i < slov.size(); i++) {
		std::cout << slov[i] << std::endl;
	}
	return 0;
}