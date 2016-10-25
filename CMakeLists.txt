cmake_minimum_required(VERSION 3.5)
project(DeteccaoColisao)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c sprite.h startup.h brick.h coin.h definitions.h sound.h .idea/ranking.h ranking.h enemy.h gameTimer.h itemblock.h)


INCLUDE_DIRECTORIES( /usr/local/include )

LINK_DIRECTORIES( /usr/local/lib )
add_executable(DeteccaoColisao ${SOURCE_FILES})
TARGET_LINK_LIBRARIES(DeteccaoColisao allegro_acodec
        allegro_audio
        allegro_color
        allegro_dialog
        allegro_image
        allegro_main
        allegro_memfile
        allegro_physfs
        allegro_primitives
        allegro_ttf
        allegro_font
        allegro)