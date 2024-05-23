add_executable(snake snake.cpp snake.h)

if (UNIX)

    find_package( Curses REQUIRED )
    include_directories( ${CURSES_INCLUDE_DIRS} )
    target_link_libraries(snake ${CURSES_LIBRARIES} )

endif(UNIX)