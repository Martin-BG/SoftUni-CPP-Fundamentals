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

set(E_2018_01_09_PREP "${EXAMS}2018.01.09-ExamPrep/")
add_executable(E_2018_01_09_PREP_T01.Sequence "${E_2018_01_09_PREP}01. Sequence.cpp")
add_executable(E_2018_01_09_PREP_T02.CopyPaste "${E_2018_01_09_PREP}02. CopyPaste.cpp")
add_executable(E_2018_01_09_PREP_T03.Visitors "${E_2018_01_09_PREP}03. Visitors.cpp")
add_executable(E_2018_01_09_PREP_T04.Emails "${E_2018_01_09_PREP}04. Emails.cpp")

set(E_2018_01_14 "${EXAMS}2018.01.14/")
add_executable(E_2018_01_14_T01.Extremes "${E_2018_01_14}01. Extremes.cpp")
add_executable(E_2018_01_14_T02.Compression "${E_2018_01_14}02. Compression.cpp")
add_executable(E_2018_01_14_T03.Data "${E_2018_01_14}03. Data.cpp")
add_executable(E_2018_01_14_T04.Interference "${E_2018_01_14}04. Interference.cpp")

set(E_2018_01_28 "${EXAMS}2018.01.28/")
add_executable(E_2018_01_28_T01.Unused "${E_2018_01_28}01. Unused.cpp")
add_executable(E_2018_01_28_T02.Decompression "${E_2018_01_28}02. Decompression.cpp")
add_executable(E_2018_01_28_T03.Entities "${E_2018_01_28}03. Entities.cpp")
add_executable(E_2018_01_28_T04.Decryption "${E_2018_01_28}04. Decryption.cpp")

set(E_2018_07_15 "${EXAMS}2018.07.15/")
add_executable(E_2018_07_15_T01.Secret "${E_2018_07_15}01. Secret.cpp")
add_executable(E_2018_07_15_T02.FormatLines "${E_2018_07_15}02. FormatLines.cpp")
add_executable(E_2018_07_15_T03.Code "${E_2018_07_15}03. Code.cpp")
add_executable(E_2018_07_15_T04.Antimatter "${E_2018_07_15}04. Antimatter.cpp")

set(E_2018_07_29 "${EXAMS}2018.07.29/")
add_executable(E_2018_07_29_T01.Diff "${E_2018_07_29}01. Diff.cpp")
add_executable(E_2018_07_29_T02.Glitches "${E_2018_07_29}02. Glitches.cpp")
add_executable(E_2018_07_29_T03.Ranges "${E_2018_07_29}03. Ranges.cpp")
add_executable(E_2018_07_29_T04.Social "${E_2018_07_29}04. Social.cpp")
