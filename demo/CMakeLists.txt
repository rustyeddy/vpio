add_executable(demo main.cc)

include_directories("../include")

target_link_libraries(demo vpio)
target_link_libraries(demo wiringPi)
