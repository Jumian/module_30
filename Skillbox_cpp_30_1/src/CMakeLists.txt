
set(MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)

add_executable("Skillbox_cpp_30_1" "Skillbox_cpp_30_1.cpp" "http_lib.cpp")

target_include_directories("Skillbox_cpp_30_1" PUBLIC ${MY_INCLUDE})



# TODO: Добавьте тесты и целевые объекты, если это необходимо.
