set(TEST_SOURCE_DIRS 
	"${PROJECT_SOURCE_DIR}/TestAlgorithm")

include_directories("${PROJECT_SOURCE_DIR}/TestCommon")

foreach(dir ${TEST_SOURCE_DIRS})
include_directories(${dir})
aux_source_directory(${dir} TEST_SOURCE_SRCS)
endforeach(dir)

add_library(TestAlgorithm SHARED ${TEST_SOURCE_SRCS})
