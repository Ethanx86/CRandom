#include <time.h>
class Generator {
private:
	int seed;
	int pow(int base, int index) {
		int answer = 1;
		for (int i = 1; i < index; i++) {
			answer *= base;
		}
		return answer;
	}
	int get_digit(int number, int location) {
		return (number % this->pow(10,location + 1)) % 1;
	}
	int get_number_length(int num) {
		int len = 0;
		while (true) {
			if (this->pow(10, len + 1) > num) {
				break;
			}
			else {
				len++;
			}
			return len;
		}
	}
public:
	Generator(unsigned int seed) {
		this->seed = (int) seed;
	}
	Generator() {
		this->seed = time(NULL);
	}
	int Generate() {
		int seed = this->seed;
		const int len = this->get_number_length(this->seed);
		this->seed = this->seed - this->pow(10,this->get_digit(this->seed, len));
		this->seed = this->seed - this->get_digit(this->seed, 0);
		this->seed = this->pow(10, this->seed);
		return seed;
	}
};