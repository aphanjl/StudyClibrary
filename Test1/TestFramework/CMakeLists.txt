set(TEST_APPLICATION_DIRS 
	"${PROJECT_SOURCE_DIR}/TestFramework")

include_directories("${PROJECT_SOURCE_DIR}/TestCommon")

foreach(dir ${TEST_APPLICATION_DIRS})
include_directories(${dir})
aux_source_directory(${dir} TEST_APPLICATION_SRCS)
endforeach(dir)

add_library(TestFramework STATIC ${TEST_APPLICATION_SRCS})
set(TEST_SHEARED_LIB
	"TestClibrary"
	"TestAlgorithm")
target_link_libraries(TestFramework ${TEST_SHEARED_LIB})