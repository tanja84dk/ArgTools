# ARG Decrypt Tool Project

My small project creating a decrypting tool to use in ARG ( Alternate Reality Game )

At this time its able to encrypt and decrypt base32, base64 and 8Bit binary ( Ceaser Chipher is under early development ) encoded text but more to come

> #### What does the tool?
>
> - Right now the tool is able to encode and decode base32, base64 and 8Bit binary ( Ceaser Chipher is under early development ) encoding from txt file and input.

> #### About The Tool
>
> - Because of the length of 8Bit Binary strings its then only posible to encode and decode from a .txt file.  
>     
>   All output from encoding and decoding will be saved in seperate .txt files in the directory and they are prepended date and time stamp to not overwrite any of your results

## Compiling from source
 - git clone --recurse-submodules https://github.com/tanja84dk/ArgTools
 - Test compiled with VS Code and Clang12.0.1, GCC 7.5.0 and CMake 3.21.0 on Ubuntu 18.04.5 LTS

## Used External libraries
 - [**Base64**](https://github.com/rhymu8354/Base64) created by [***Richard Walters***](https://github.com/rhymu8354)
 - [**Utf8**](https://github.com/rhymu8354/Utf8) created by [***Richard Walters***](https://github.com/rhymu8354)
 - [***googletest***](https://github.com/google/googletest) created by [***Google***](https://github.com/google)
 - [***Cpp-Tanja84dk-Tools***](https://github.com/tanja84dk/Cpp-Tanaj84dk-Tools) created by [***tanja84dk***](https://github.com/tanja84dk)

## Used third-party tools
- [**Clang**](https://clang.llvm.org) for compilation with code sanitizers
- [**CMake**](https://cmake.org) for build automation

## License

See the 'LICENSE' for details. In summary ArgTools is licensed under the MIT License.

## Additional Licenses

 - [**Base64**](https://github.com/rhymu8354/Base64) created by [***Richard Walters***](https://github.com/rhymu8354) is licended under [***MIT License***](https://github.com/rhymu8354/Base64/blob/main/LICENSE.txt)
 - [**Utf8**](https://github.com/rhymu8354/Utf8) created by [***Richard Walters***](https://github.com/rhymu8354) is licended under [***MIT License***](https://github.com/rhymu8354/Utf8/blob/main/LICENSE.txt)
 - [***googletest***](https://github.com/google/googletest) created by [***Google***](https://github.com/google) is licended under [***BSD 3-Clause "New" or "Revised" License***](https://github.com/google/googletest/blob/master/LICENSE)
 - [***Cpp-Tanja84dk-Tools***](https://github.com/tanja84dk/Cpp-Tanaj84dk-Tools) created by [***tanja84dk***](https://github.com/tanja84dk) is licended under [***MIT License***](https://github.com/tanja84dk/Cpp-Tanaj84dk-Tools/blob/master/LICENSE)
 