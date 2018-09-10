# Install script for directory: E:/Geo3DML-beta/src/GMXMLFileIO

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "E:/Geo3DML-beta/lib/Debug/GMXMLFileIOd.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "E:/Geo3DML-beta/lib/Release/GMXMLFileIO.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "E:/Geo3DML-beta/lib/MinSizeRel/GMXMLFileIOs.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "E:/Geo3DML-beta/lib/RelWithDebInfo/GMXMLFileIOrd.lib")
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "E:/Geo3DML-beta/lib/Debug/GMXMLFileIOd.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "E:/Geo3DML-beta/lib/Release/GMXMLFileIO.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "E:/Geo3DML-beta/lib/MinSizeRel/GMXMLFileIOs.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "E:/Geo3DML-beta/lib/RelWithDebInfo/GMXMLFileIOrd.dll")
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/GMXMLFileIO" TYPE FILE FILES
    "E:/Geo3DML-beta/src/GMXMLFileIO/Export.h"
    "E:/Geo3DML-beta/src/GMXMLFileIO/FeatureClassXMLReader.h"
    "E:/Geo3DML-beta/src/GMXMLFileIO/FeatureClassXMLWriter.h"
    "E:/Geo3DML-beta/src/GMXMLFileIO/FeatureRelationXMLReader.h"
    "E:/Geo3DML-beta/src/GMXMLFileIO/FeatureRelationXMLWriter.h"
    "E:/Geo3DML-beta/src/GMXMLFileIO/FeatureXMLReader.h"
    "E:/Geo3DML-beta/src/GMXMLFileIO/Geo3DLayerXMLReader.h"
    "E:/Geo3DML-beta/src/GMXMLFileIO/Geo3DMapXMLReader.h"
    "E:/Geo3DML-beta/src/GMXMLFileIO/Geo3DMapXMLWriter.h"
    "E:/Geo3DML-beta/src/GMXMLFileIO/Geo3DProjectXMLReader.h"
    "E:/Geo3DML-beta/src/GMXMLFileIO/Geo3DProjectXMLWriter.h"
    "E:/Geo3DML-beta/src/GMXMLFileIO/Geo3DStyleXMLReader.h"
    "E:/Geo3DML-beta/src/GMXMLFileIO/Geo3DStyleXMLWriter.h"
    "E:/Geo3DML-beta/src/GMXMLFileIO/GeoFeatureXMLReader.h"
    "E:/Geo3DML-beta/src/GMXMLFileIO/GeoFeatureXMLWriter.h"
    "E:/Geo3DML-beta/src/GMXMLFileIO/GeologicFeatureXMLReader.h"
    "E:/Geo3DML-beta/src/GMXMLFileIO/GeometryXMLReader.h"
    "E:/Geo3DML-beta/src/GMXMLFileIO/GeometryXMLWriter.h"
    "E:/Geo3DML-beta/src/GMXMLFileIO/GeoModelXMLReader.h"
    "E:/Geo3DML-beta/src/GMXMLFileIO/GeoModelXMLWriter.h"
    "E:/Geo3DML-beta/src/GMXMLFileIO/GeoStyleXMLReader.h"
    "E:/Geo3DML-beta/src/GMXMLFileIO/MappedFeatureXMLReader.h"
    "E:/Geo3DML-beta/src/GMXMLFileIO/MetaDataxmlReader.h"
    "E:/Geo3DML-beta/src/GMXMLFileIO/SpatialRelationXMLReader.h"
    "E:/Geo3DML-beta/src/GMXMLFileIO/XMLBase64.h"
    "E:/Geo3DML-beta/src/GMXMLFileIO/XMLReader.h"
    "E:/Geo3DML-beta/src/GMXMLFileIO/XMLWriter.h"
    "E:/Geo3DML-beta/src/GMXMLFileIO/GMPolyData.h"
    "E:/Geo3DML-beta/src/GMXMLFileIO/GMStructuredPoints.h"
    "E:/Geo3DML-beta/src/GMXMLFileIO/GMUnstructuredGrid.h"
    "E:/Geo3DML-beta/src/GMXMLFileIO/GMCornerPointGrid.h"
    )
endif()

