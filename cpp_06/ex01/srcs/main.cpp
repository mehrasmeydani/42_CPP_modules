#include "../header/Serializer.hpp"
#include "../header/Data.hpp"
#include <iostream>
#include <cstring>
#include <sstream>

static int g_passed = 0;
static int g_failed = 0;
static bool g_verbose = false;

static std::string intToString(int n) {
	std::ostringstream oss;
	oss << n;
	return oss.str();
}

static void printResult(bool passed, const std::string& testName, const std::string& details = "") {
	if (passed) {
		std::cout << "\033[32m[PASS]\033[0m " << testName << "\n";
		if (g_verbose && !details.empty())
			std::cout << "    " << details << "\n";
		g_passed++;
	} else {
		std::cout << "\033[31m[FAIL]\033[0m " << testName << "\n";
		if (!details.empty())
			std::cout << "    " << details << "\n";
		g_failed++;
	}
}

static void testBasicSerialization() {
	std::cout << "========== BASIC SERIALIZATION ==========\n";

	Data data;
	data.i = 42;
	uintptr_t raw = Serializer::serialize(&data);
	Data* result = Serializer::deserialize(raw);

	printResult(result == &data, "Round-trip preserves pointer address");
	printResult(result->i == 42, "Data.i preserved", "i = " + intToString(result->i));
}

static void testNullPointer() {
	std::cout << "\n========== NULL POINTER ==========\n";

	Data* nullData = NULL;
	uintptr_t raw = Serializer::serialize(nullData);
	Data* result = Serializer::deserialize(raw);

	printResult(raw == 0, "Null pointer serializes to 0");
	printResult(result == NULL, "Deserialize 0 returns NULL");
}

static void testMultipleObjects() {
	std::cout << "\n========== MULTIPLE OBJECTS ==========\n";

	Data data1; data1.i = 1;
	Data data2; data2.i = 2;
	Data data3; data3.i = 3;

	uintptr_t raw1 = Serializer::serialize(&data1);
	uintptr_t raw2 = Serializer::serialize(&data2);
	uintptr_t raw3 = Serializer::serialize(&data3);

	printResult(raw1 != raw2 && raw2 != raw3 && raw1 != raw3,
		"Different objects have different serialized values");

	Data* res1 = Serializer::deserialize(raw1);
	Data* res2 = Serializer::deserialize(raw2);
	Data* res3 = Serializer::deserialize(raw3);

	printResult(res1 == &data1 && res2 == &data2 && res3 == &data3,
		"All pointers correctly restored");

	printResult(res1->i == 1 && res2->i == 2 && res3->i == 3,
		"All data values correct");
}

static void testHeapAllocation() {
	std::cout << "\n========== HEAP ALLOCATION ==========\n";

	Data* heapData = new Data();
	heapData->i = 999;
	uintptr_t raw = Serializer::serialize(heapData);
	Data* result = Serializer::deserialize(raw);

	printResult(result == heapData, "Heap pointer round-trip works");
	printResult(result->i == 999, "Heap data value preserved");

	delete heapData;
}

static void testModifyAfterDeserialize() {
	std::cout << "\n========== MODIFY AFTER DESERIALIZE ==========\n";

	Data data;
	data.i = 100;
	uintptr_t raw = Serializer::serialize(&data);
	Data* result = Serializer::deserialize(raw);

	result->i = 200;

	printResult(data.i == 200, "Modification through deserialized pointer affects original");
}

static void testAddressPreservation() {
	std::cout << "\n========== ADDRESS PRESERVATION ==========\n";

	Data data;
	Data* originalPtr = &data;
	uintptr_t expectedRaw = reinterpret_cast<uintptr_t>(originalPtr);

	uintptr_t actualRaw = Serializer::serialize(originalPtr);
	printResult(actualRaw == expectedRaw, "Serialized value equals reinterpret_cast result");

	Data* restoredPtr = Serializer::deserialize(actualRaw);
	printResult(restoredPtr == originalPtr, "Deserialized pointer equals original");
}

static void testArrayOfData() {
	std::cout << "\n========== ARRAY OF DATA ==========\n";

	Data arr[3];
	arr[0].i = 10;
	arr[1].i = 20;
	arr[2].i = 30;

	uintptr_t raw0 = Serializer::serialize(&arr[0]);
	uintptr_t raw1 = Serializer::serialize(&arr[1]);
	uintptr_t raw2 = Serializer::serialize(&arr[2]);

	Data* res0 = Serializer::deserialize(raw0);
	Data* res1 = Serializer::deserialize(raw1);
	Data* res2 = Serializer::deserialize(raw2);

	printResult(res0 == &arr[0] && res1 == &arr[1] && res2 == &arr[2],
		"Array element pointers preserved");
	printResult(res0->i == 10 && res1->i == 20 && res2->i == 30,
		"Array element data preserved");
}

static void runUnitTests() {
	testBasicSerialization();
	testNullPointer();
	testMultipleObjects();
	testHeapAllocation();
	testModifyAfterDeserialize();
	testAddressPreservation();
	testArrayOfData();

	std::cout << "\n==========================================\n";
	std::cout << "Results: \033[32m" << g_passed << " passed\033[0m, \033[31m" << g_failed << " failed\033[0m\n";
	if (g_failed == 0)
		std::cout << "\033[32mAll tests passed!\033[0m\n";
}

int main(int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && std::strcmp(argv[1], "test") == 0)) {
		g_verbose = false;
		runUnitTests();
	} else if (argc == 2 && std::strcmp(argv[1], "verbose") == 0) {
		g_verbose = true;
		runUnitTests();
	} else {
		std::cerr << "Usage: " << argv[0] << " [test|verbose]\n";
		std::cerr << "       test    - run unit tests (pass/fail only)\n";
		std::cerr << "       verbose - run unit tests with details\n";
		return 1;
	}
	return g_failed > 0 ? 1 : 0;
}
