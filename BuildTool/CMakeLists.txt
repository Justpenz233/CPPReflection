add_subdirectory(meta_parser)

function(PreCompile project1 Header1)
    set(BuildHeaders ${Header1})
    get_target_property(INCLUDE_DIRS_1 ${project1} INCLUDE_DIRECTORIES)

    set(INCLUDE_DIRS "${ENGINE_SOURCE_DIR}")
    string(JOIN ";" INCLUDE_DIRS "${INCLUDE_DIRS}" "${INCLUDE_DIRS_1}")
    string(REPLACE ";" "," INCLUDE_DIRS "${INCLUDE_DIRS}")

    include(${BUILD_TOOL_DIR}/precompile/precompile.cmake)
    add_dependencies(PiccoloPreCompile PiccoloParser)
    add_dependencies(${project1} PiccoloPreCompile)
endfunction()