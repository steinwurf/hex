News for hex
============

This file lists the major changes between versions. For a more detailed list of
every change, see the Git log.

Latest
------
* Minor: Added cmake support.

4.1.1
-----
* Patch: Fix version name.

4.1.0
-----
* Minor: Added a constructor to create a hex::dump object from std::vector.
* Minor: Added the parse_hex_string helper function to create a byte vector
  from a hexadecimal string representation.

4.0.0
-----
* Major: Upgrade to waf-tools 4
* Minor: Upgrade to gtest 4

3.0.0
-----
* Major: Correct use flag from ``hex`` to ``hex_includes``.
* Patch: Fix naming of test files.

2.0.0
-----
* Major: Removed dependency on storage to ease reuseability.

1.0.0
-----
* Major: Initial release.
