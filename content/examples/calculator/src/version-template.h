// CMake will replace all keys between @...@ by the value

// these exist as CMake variables
#define VERSION_MAJOR @PROJECT_VERSION_MAJOR@
#define VERSION_MINOR @PROJECT_VERSION_MINOR@
#define VERSION_PATCH @PROJECT_VERSION_PATCH@

// this is not a CMake variable, we need to set it ourselves
#define GIT_HASH      "@GIT_HASH@"
