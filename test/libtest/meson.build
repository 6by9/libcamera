libtest_sources = files([
    'buffer_source.cpp',
    'camera_test.cpp',
    'test.cpp',
])

libtest_includes = include_directories('.')


test_includes_public = [
    libtest_includes,
]

test_includes_internal = [
    test_includes_public,
    libcamera_internal_includes,
]

libtest = static_library('libtest', libtest_sources,
                         dependencies : libcamera_dep,
                         include_directories : test_includes_internal)

test_libraries = [libtest]
