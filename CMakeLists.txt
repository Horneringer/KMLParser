cmake_minimum_required(VERSION 3.12)

project(KMLParser)


add_executable(TESTS
test1.cpp
test2.cpp
KMLParser.cpp
KMLParser.h
)


target_include_directories(TESTS PUBLIC include)

set (CMAKE_PREFIX_PATH "c:/Qt/Qt5.15.2/5.15.2/msvc2019_64/")
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

target_link_libraries(TESTS Qt5::Core)


set(MSVC_WARNINGS
        /W4 # Baseline reasonable warnings
        /w14242 # 'identifier': conversion from 'type1' to 'type1', possible loss of data
        /w14254 # 'operator': conversion from 'type1:field_bits' to 'type2:field_bits', possible loss of data
        /w14263 # 'function': member function does not override any base class virtual member function
        /w14265 # 'classname': class has virtual functions, but destructor is not virtual instances of this class may not
        # be destructed correctly
        /w14287 # 'operator': unsigned/negative constant mismatch
        /we4289 # nonstandard extension used: 'variable': loop control variable declared in the for-loop is used outside
        # the for-loop scope
        /w14296 # 'operator': expression is always 'boolean_value'
        /w14311 # 'variable': pointer truncation from 'type1' to 'type2'
        /w14545 # expression before comma evaluates to a function which is missing an argument list
        /w14546 # function call before comma missing argument list
        /w14547 # 'operator': operator before comma has no effect; expected operator with side-effect
        /w14549 # 'operator': operator before comma has no effect; did you intend 'operator'?
        /w14555 # expression has no effect; expected expression with side- effect
        /w14619 # pragma warning: there is no warning number 'number'
        /w14640 # Enable warning on thread un-safe static member initialization
        /w14826 # Conversion from 'type1' to 'type_2' is sign-extended. This may cause unexpected runtime behavior.
        /w14905 # wide string literal cast to 'LPSTR'
        /w14906 # string literal cast to 'LPWSTR'
        /w14928 # illegal copy-initialization; more than one user-defined conversion has been implicitly applied
        /permissive- # standards conformance mode for MSVC compiler.
        )
target_compile_options(TESTS PRIVATE ${MSVC_WARNINGS})

set_target_properties(TESTS
        PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
        )


        add_executable(WINDOW WIN32
        KMLParser.cpp
        KMLParser.h
        window.cpp)

        target_link_libraries(WINDOW Qt5::Core Qt5::Widgets)