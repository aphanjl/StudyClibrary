set(TEST_CLASS_DIRS 
	"${PROJECT_SOURCE_DIR}/TestClass")

foreach(dir ${TEST_CLASS_DIRS})
include_directories(${dir})
aux_source_directory(${dir} TEST_CLASS_SRCS)
endforeach(dir)

add_library(TestClass STATIC ${TEST_CLASS_SRCS})
