#include <iostream>
#include <fstream>
#include <string>
class myLog {

public:
	myLog(std::string name) :name(name) {}
	~myLog() {
		closeMylog();
	}

	void openInputnMylog() {
		try {
			inFile.open(name);
			if (!inFile) {
				throw std::runtime_error("* "+ name +" *CAN'T OPEN INFILE OR INFILE DOESN'T EXISTS");

			}
			else {
				std::cout << "* "<<name << " * INPUT MYLOG IS OPENED" << std::endl;
			}
		}
		catch (std::runtime_error &e) {
			std::cout << e.what() << std::endl;
		}
	}

	void openOutputMylog() {
		outFile.open(name);
		std::cout << "* " << name << " * OUTPUT MYLOG IS OPENED" << std::endl;
	}

	void closeMylog() {
		if (inFile.is_open() || outFile.is_open()) {
			inFile.close();
			outFile.close();
			std::cout << "* " << name << " * MYLOG IS CLOSED" << std::endl;
		}
		else {
			std::cout << "* " << name << " * MYLOG DIDN'T NOT GET OPENED" << std::endl;
		}
	}


private:
	std::string name;
	std::ifstream inFile;
	std::ofstream outFile;
};
int main() {
	myLog hi("txt.log");
	myLog chao("fake.log");
	//chao.openInputnMylog();
	chao.closeMylog();
	hi.openInputnMylog();
	hi.closeMylog();
	myLog bye("bye.log");
	bye.openOutputMylog();
	bye.closeMylog();

	system("PAUSE");
	return 0;
}