
set(MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)

add_executable("Skillbox_cpp_30_3" "Skillbox_cpp_30_3.cpp" "http_lib.cpp")

target_include_directories("Skillbox_cpp_30_3" PUBLIC ${MY_INCLUDE})



# TODO: Добавьте тесты и целевые объекты, если это необходимо.
