#include <iostream>
#include <fstream>
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

void slov_sort(std::vector<std::string>& slov) {
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

int main() {
	std::string s;
	std::vector <std::string> slov;
	std::ifstream fin;
	std::ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");
	if (!fin.is_open() || !fout.is_open()) {
		std::cout << "Error";
		return 1;
	}
		while (std::getline(fin, s)) {
			slov = slova(s);
			slov_sort(slov);
				for (int i = 0; i < slov.size(); i++) {
					fout << slov[i] << " ";
				}
				fout << "\n";
			}
	return 0;
}