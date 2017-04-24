set(TEST_LOOP_DIRS 
	"${PROJECT_SOURCE_DIR}/TestLoop"
	"${PROJECT_SOURCE_DIR}/TestLoop/make")

foreach(dir ${TEST_LOOP_DIRS})
include_directories(${dir})
aux_source_directory(${dir} TEST_LOOP_SRCS)
endforeach(dir)

add_library(TestLoop SHARED ${TEST_LOOP_SRCS})
