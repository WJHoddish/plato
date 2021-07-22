set( FOLDER_LIST
        )

foreach ( folder ${FOLDER_LIST} )
    gtest_folder( ${folder} main.cpp gtest gtest_main )
endforeach ()
