#include <random>
using namespace std;


class DataGenerator {
	public:
		void generateArray(int* result, int type, int length);
	private:
		default_random_engine generator;
		void generateRandomUniformArray(int* result, int length);
		void generateRandomNormalArray(int* result, int length);
		void generateAscOrderedArray(int* result, int length);
		void generateDescOrderedArray(int* result, int length);
};