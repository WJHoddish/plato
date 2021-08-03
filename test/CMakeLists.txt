set( FOLDER_LIST
        widget
        )

foreach ( folder ${FOLDER_LIST} )
    gtest_folder( ${folder} main.cpp gtest gtest_main ${REQUIRED_LIBS_QUALIFIED} )
endforeach ()
