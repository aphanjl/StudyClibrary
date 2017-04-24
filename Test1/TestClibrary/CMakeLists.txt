set(TEST_CLIBRARY_DIRS 
	"${PROJECT_SOURCE_DIR}/TestClibrary")

include_directories("${PROJECT_SOURCE_DIR}/TestCommon")

foreach(dir ${TEST_CLIBRARY_DIRS})
include_directories(${dir})
aux_source_directory(${dir} TEST_CLIBRARY_SRCS)
endforeach(dir)

add_library(TestClibrary SHARED ${TEST_CLIBRARY_SRCS})
