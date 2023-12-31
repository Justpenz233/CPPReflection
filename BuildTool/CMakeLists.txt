set(BUILD_TOOL_DIR "${CMAKE_CURRENT_SOURCE_DIR}" CACHE STRING "BUILD TOOL DIR")
add_subdirectory(meta_parser)

## Precompile and generate header files
## should set path where header should place and target lists
function(PreCompile GeneratedPath Targets)
    set(BuildHeaders)
    set(INCLUDE_DIRS)
    set(GENERATED_DIR ${GeneratedPath})

    foreach(Target ${Targets})
        get_target_property(TargetHeader ${Target} PARSE_HEADERS)
        list(APPEND BuildHeaders ${TargetHeader})

        get_target_property(TargetIncludeDir ${Target} INCLUDE_DIRECTORIES)
        get_target_property(TargetLocationDir ${Target} SOURCE_DIR)

        if(TargetIncludeDir)
            string(JOIN ";" INCLUDE_DIRS "${INCLUDE_DIRS}" "${TargetIncludeDir}")
        endif()
        string(JOIN ";" INCLUDE_DIRS "${INCLUDE_DIRS}" "${TargetLocationDir}")
        string(REPLACE ";" "," INCLUDE_DIRS "${INCLUDE_DIRS}")
    endforeach()   

    include(${BUILD_TOOL_DIR}/precompile/precompile.cmake)

    add_dependencies(PiccoloPreCompile PiccoloParser)
    foreach(Target ${Targets})
        add_dependencies(${Target} PiccoloPreCompile)
    endforeach()   

endfunction()