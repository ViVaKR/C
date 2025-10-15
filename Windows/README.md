# Cmake, Ninja (Windows)

## 프로젝트 초기 생성

```bash

# MSYS2 로 Ninja 설치
pacman -S mingw-w64-clang-x86_64-ninja


# PATH 포함
ninja --version



# 프로젝트 초기 생성시
# 이 프로젝트는 Ninja 를 사용해서 빌드할 거야 라고 초기 선언하는 것
cmake -G "Ninja" -S . _B build
# 코드 수정 후 빌드할 때 마다.
cmake --build build

```

```json
// vscode setting.json
  ....
  "cmake.cmakePath": "C:/Program Files/CMake/bin/cmake.exe",
  "cmake.generator": "Ninja",
  "cmake.configureSettings": {
    "CMAKE_MAKE_PROGRAM": "C:/MSys/clang64/bin/ninja.exe",
    "CMAKE_C_COMPILER": "C:/MSys/clang64/bin/clang.exe",
    "CMAKE_CXX_COMPILER": "C:/MSys/clang64/bin/clang++.exe",
  },
  ....
}

```

## VSCode Default Settings inside `.vscode`

- c_cpp_properties.json

```json
{
  "configurations": [
    {
      "name": "Clang64",
      "compilerPath": "C:/MSys/clang64/bin/clang.exe",
      "cStandard": "gnu23",
      "cppStandard": "gnu++23",
      "intelliSenseMode": "windows-clang-x64",
      "includePath": [
        "${workspaceFolder}/**"
      ],
      "defines": []
    }
  ],
  "version": 4
}


```

## 참고
