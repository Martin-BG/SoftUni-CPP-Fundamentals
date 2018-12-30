cmake_minimum_required(VERSION 3.13)
project(CPP_Fundamentals)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

#######################################
set(L05 "05. STL Associative Containers/")

set(E05_EXERCISE "${L05}Exercise/")
add_executable(E05_T01.EvenOddInMap "${E05_EXERCISE}01. EvenOddInMap.cpp")
add_executable(E05_T02.FilterByNameOrAge "${E05_EXERCISE}02. FilterByNameOrAge.cpp")
add_executable(E05_T03.FindPointIfInsideOrOutside "${E05_EXERCISE}03. FindPointIfInsideOrOutside.cpp")
add_executable(E05_T04.CarProgram "${E05_EXERCISE}04. CarProgram.cpp")

#######################################
set(EXAMS "07. Exams/")

set(E_2018_07_15 "${EXAMS}2018.07.15/")
add_executable(E_2018_07_15_T01.Secret "${E_2018_07_15}01. Secret.cpp")
add_executable(E_2018_07_15_T02.FormatLines "${E_2018_07_15}02. FormatLines.cpp")
add_executable(E_2018_07_15_T03.Code "${E_2018_07_15}03. Code.cpp")
add_executable(E_2018_07_15_T04.Antimatter "${E_2018_07_15}04. Antimatter.cpp")

set(E_2018_07_29 "${EXAMS}2018.07.29/")
add_executable(E_2018_07_29_T03.Ranges "${E_2018_07_29}03. Ranges.cpp")
