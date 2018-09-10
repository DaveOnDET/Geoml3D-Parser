# Install script for directory: E:/Geo3DML-beta/src/vtklibxml2

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "E:/Geo3DML-beta/lib/Debug/vtklibxml2d.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "E:/Geo3DML-beta/lib/Release/vtklibxml2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "E:/Geo3DML-beta/lib/MinSizeRel/vtklibxml2s.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "E:/Geo3DML-beta/lib/RelWithDebInfo/vtklibxml2rd.lib")
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "E:/Geo3DML-beta/lib/Debug/vtklibxml2d.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "E:/Geo3DML-beta/lib/Release/vtklibxml2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "E:/Geo3DML-beta/lib/MinSizeRel/vtklibxml2s.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "E:/Geo3DML-beta/lib/RelWithDebInfo/vtklibxml2rd.dll")
  endif()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtklibxml2" TYPE FILE FILES
    "E:/Geo3DML-beta/src/vtklibxml2/libxml.h"
    "E:/Geo3DML-beta/src/vtklibxml2/config.h"
    "E:/Geo3DML-beta/src/vtklibxml2/elfgcchack.h"
    "E:/Geo3DML-beta/src/vtklibxml2/trio.h"
    "E:/Geo3DML-beta/src/vtklibxml2/triodef.h"
    "E:/Geo3DML-beta/src/vtklibxml2/trionan.h"
    "E:/Geo3DML-beta/src/vtklibxml2/triop.h"
    "E:/Geo3DML-beta/src/vtklibxml2/triostr.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/c14n.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/catalog.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/chvalid.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/debugXML.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/dict.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/DOCBparser.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/encoding.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/entities.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/globals.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/hash.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/HTMLparser.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/HTMLtree.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/list.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/nanoftp.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/nanohttp.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/parser.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/parserInternals.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/pattern.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/relaxng.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/SAX.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/SAX2.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/schemasInternals.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/schematron.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/threads.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/tree.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/uri.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/valid.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/vssver2.scc"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/vtk_libxml2_mangle.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/xinclude.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/xlink.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/xmlautomata.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/xmlerror.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/xmlexports.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/xmlIO.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/xmlmemory.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/xmlmodule.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/xmlreader.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/xmlregexp.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/xmlsave.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/xmlschemas.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/xmlschemastypes.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/xmlstring.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/xmlunicode.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/xmlversion.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/xmlversion.h.in"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/xmlwin32version.h.in"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/xmlwriter.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/xpath.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/xpathInternals.h"
    "E:/Geo3DML-beta/src/vtklibxml2/libxml/xpointer.h"
    )
endif()

