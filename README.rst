===
hex
===

hex is a small header only library for printing the content of a object as a hexdump

Usage
-----

The ``hex::dump`` structure allows for printing a ``storage``

Header-only
...........

The library itself is header-only so essentially to use it you just have to clone the repository and setup the right include paths in the project where you would like to use it.

The library uses c++11 features such as variadic templates, so you need a relatively recent compiler to use it.

Unit testing
------------

The unit tests for the hex library are located in the ``test/src`` folder.

We use the Google Unit Testing Framwork (gtest) to drive the unit tests. To build and run the test run:

::

    python waf configure
    python waf

Depending on the platform you should see a test binary called ``hex_test`` in (extension also depends on operating system e.g `.exe` for windows):

::

   build/platform/test

Where ``platform`` is typically either linux, win32 or darwin depending on your operating system


License
-------

hex is available under the BSD license.
