===
hex
===

.. image:: https://travis-ci.org/steinwurf/hex.svg?branch=master
    :target: https://travis-ci.org/steinwurf/hex
    
hex is a small header only library which provides a class called dump.
dump is a class that wraps a pointer and a size and provides an output stream
operator to print the content as a hexdump.

Use as Dependency in CMake
==========================

To depend on this project when using the CMake build system, add the following
in your CMake build script:

::

   add_subdirectory("/path/to/hex" hex)
   target_link_libraries(<my_target> steinwurf::hex)

Where ``<my_target>`` is replaced by your target.

License
=======

hex is available under the BSD license.
