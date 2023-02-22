#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include<string.h>
#include "BMS.h"


TEST_CASE("Given Random Generated inputs when ParameterGenerationandProcessing called then current and voltage values is expected ") {
	int result = 0;
	ParameterGenerationandProcessing(&result);
	REQUIRE(result == 1 );
}
