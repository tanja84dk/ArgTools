# ARG Decrypt Tool Project

My small project creating a decrypting tool to use in ARG ( Alternate Reality Game )

At this time its able to encrypt and decrypt base32, base64 and 8Bit binary ( Ceaser Chipher is under early development ) encoded text but more to come

> #### What does the tool?
>
> - Right now the tool is able to encode and decode base32, base64 and 8Bit binary ( Ceaser Chipher is under early development ) encoding from txt file and input.

> #### About The Tool
>
> - Because of the length of 8Bit Binary strings its then only posible to encode and decode from a .txt file.
>   All output from encoding and decoding will be saved in seperate .txt files in the directory and they are prepended date and time stamp to not overwrite any of your results

## Compiling from source

- git clone --recurse-submodules https://github.com/tanja84dk/ArgTools
- Test compiled with VS Code and Clang15.0.7, GCC 11.3.0 and CMake 3.21.0 on Debian 12 (Bookworm)

## Used External libraries

- [**_Cpp-Tanja84dk-Tools_**](https://github.com/tanja84dk/Cpp-Tanaj84dk-Tools) created by [**_tanja84dk_**](https://github.com/tanja84dk)
- [**_Cpp-Tanja84dk-Crypt_**](https://github.com/tanja84dk/Cpp-Tanja84dk-Crypt) created by [**_tanja84dk_**](https://github.com/tanja84dk)
- [**_fmtlib_**](https://github.com/fmtlib/fmt) created by [**_fmtlib_**](https://github.com/fmtlib)

## Used third-party tools

- [**_Clang_**](https://clang.llvm.org) for compilation with code sanitizers
- [**_CMake_**](https://cmake.org) for build automation

## License

See the 'LICENSE' for details. In summary ArgTools is licensed under the MIT License.

## Additional Licenses

- [**_Cpp-Tanja84dk-Tools_**](https://github.com/tanja84dk/Cpp-Tanaj84dk-Tools) created by [**_tanja84dk_**](https://github.com/tanja84dk) is licended under [**_MIT License_**](https://github.com/tanja84dk/Cpp-Tanaj84dk-Tools/blob/master/LICENSE)
- [**_Cpp-Tanja84dk-Crypt_**](https://github.com/tanja84dk/Cpp-Tanaj84dk-Tools) created by [**_tanja84dk_**](https://github.com/tanja84dk) is licended under [**_MIT License_**](https://github.com/tanja84dk/Cpp-Tanaj84dk-Crypt/blob/main/LICENSE)
- [**_fmtlib_**](https://github.com/fmtlib/fmt) created by [**_fmtlib_**](https://github.com/fmtlib) in licensed under [**_MIT License_**](https://github.com/fmtlib/fmt/blob/10.0.0/LICENSE.rst)
