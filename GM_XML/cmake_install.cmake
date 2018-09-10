# Install script for directory: E:/Geo3DML-beta/src/GM_XML

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "E:/ShGeo3DML")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "E:/Geo3DML-beta/lib/Debug/GM_XMLd.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "E:/Geo3DML-beta/lib/Release/GM_XML.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "E:/Geo3DML-beta/lib/MinSizeRel/GM_XMLs.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "E:/Geo3DML-beta/lib/RelWithDebInfo/GM_XMLrd.lib")
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "E:/Geo3DML-beta/lib/Debug/GM_XMLd.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "E:/Geo3DML-beta/lib/Release/GM_XML.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "E:/Geo3DML-beta/lib/MinSizeRel/GM_XMLs.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "E:/Geo3DML-beta/lib/RelWithDebInfo/GM_XMLrd.dll")
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/GM_XML" TYPE FILE FILES
    "E:/Geo3DML-beta/src/GM_XML/Export.h"
    "E:/Geo3DML-beta/src/GM_XML/AbstractFeature.h"
    "E:/Geo3DML-beta/src/GM_XML/AbstractGeometry.h"
    "E:/Geo3DML-beta/src/GM_XML/AbstractGML.h"
    "E:/Geo3DML-beta/src/GM_XML/AbstractSpatialReferenceSystem.h"
    "E:/Geo3DML-beta/src/GM_XML/AbstractTexture.h"
    "E:/Geo3DML-beta/src/GM_XML/CoverageStyle.h"
    "E:/Geo3DML-beta/src/GM_XML/FeatureClass.h"
    "E:/Geo3DML-beta/src/GM_XML/FeatureRelation.h"
    "E:/Geo3DML-beta/src/GM_XML/FeatureStyle.h"
    "E:/Geo3DML-beta/src/GM_XML/Geo3DLayer.h"
    "E:/Geo3DML-beta/src/GM_XML/Geo3DMap.h"
    "E:/Geo3DML-beta/src/GM_XML/Geo3DMapMetaData.h"
    "E:/Geo3DML-beta/src/GM_XML/Geo3DProject.h"
    "E:/Geo3DML-beta/src/GM_XML/Geo3DProjectMetaData.h"
    "E:/Geo3DML-beta/src/GM_XML/Geo3DStyle.h"
    "E:/Geo3DML-beta/src/GM_XML/GeologicFeature.h"
    "E:/Geo3DML-beta/src/GM_XML/GeologicRelation.h"
    "E:/Geo3DML-beta/src/GM_XML/GeoModel.h"
    "E:/Geo3DML-beta/src/GM_XML/GeoModelMetaData.h"
    "E:/Geo3DML-beta/src/GM_XML/GeoSceneStyle.h"
    "E:/Geo3DML-beta/src/GM_XML/GeoSymbolizer.h"
    "E:/Geo3DML-beta/src/GM_XML/gmmlDisplayErrorandWarning.h"
    "E:/Geo3DML-beta/src/GM_XML/gmmlSystem.h"
    "E:/Geo3DML-beta/src/GM_XML/gmmlSystemInfo.h"
    "E:/Geo3DML-beta/src/GM_XML/MappedFeature.h"
    "E:/Geo3DML-beta/src/GM_XML/SpatialRelation.h"
    )
endif()

