include(ExternalProject)

set(ARM_TOOLCHAIN_VERSION "20.1.0")
set(BASE_URL "https://github.com/arm/arm-toolchain/releases/download/release-${ARM_TOOLCHAIN_VERSION}-ATfE")
set(TAR_NAME "ATfE-${ARM_TOOLCHAIN_VERSION}-Linux-x86_64.tar.xz")
set(ARCHIVE_URL "${BASE_URL}/${TAR_NAME}")
set(SHA_URL "${ARCHIVE_URL}.sha256")

file(MAKE_DIRECTORY "${DOWNLOAD_DIR}" "${EXTRACT_DIR}")

ExternalProject_Add(
  arm-toolchain
  URL "${ARCHIVE_URL}"
  URL_HASH SHA256=c1179396608c07bf68f3014923cfdfcd11c8402a3732f310c23d07c9a726b275
  DOWNLOAD_NAME "${TAR_NAME}"
  SOURCE_DIR "${CMAKE_BINARY_DIR}/arm-toolchain"
  DOWNLOAD_EXTRACT_TIMESTAMP FALSE
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
  INSTALL_COMMAND ""
)

set(ARM_TOOLCHAIN_SYSROOT "${CMAKE_BINARY_DIR}/arm-toolchain" CACHE PATH "ARM toolchain sysroot")