# `C` Examples

## Ready Programming (macOS)

1. [brew install](https://formulae.brew.sh/) [cmake](https://cmake.org/)
2. Create _`C`_ Project Folder and Move To...
3. Editor _`VSCode`_ ShortCut : `CMD + SHIFT + P`
4. Search and select `CMake: Quick Start`
5. Enter Project `Name` and Select `Executable ...`
6. Etc _`tasks.json`_, _`c_cpp_properties.json`_ & _`launch.json`_ Create by online references.
7. _Start_

### Demo List : Within `Demo/` Folder

1. `Print.c` : printf, escape sequence

### VSCode User `Snippets`

```json
{
  "Viv Printf Number": {
    "prefix": "pfd",
    "body": ["printf(\"${1:Text} \\%d\\n\",${2:var});$0"],
    "description": "Viv printf number"
  },
  "Viv Printf Character": {
    "prefix": "pfc",
    "body": ["printf(\"${1:Text} \\%c\\n\",${2:var});$0"],
    "description": "Viv printf character (char)"
  },
  "Viv Printf String": {
    "prefix": "pfs",
    "body": ["printf(\"${1:Text} \\%s\\n\",${2:var});$0"],
    "description": "Viv printf string (char[])"
  },
  "Viv Printf Float": {
    "prefix": "pff",
    "body": ["printf(\"${1:Text} \\%${2:.2f}\\n\",${3:var});$0"],
    "description": "Viv printf float"
  },
  "Viv Printf Blank": {
    "prefix": "pfb",
    "body": ["printf(\"$1\\n\");$0"],
    "description": "Viv printf blank"
  },
  "Viv Scanf": {
    "prefix": "sf",
    "body": ["scanf(\"%d\", ${1:var});$0"],
    "description": "Viv blank line with scanf"
  },
  "Viv Clear Screen": {
    "prefix": "cls",
    "body": ["system(\"clear\");$0"],
    "description": "Viv termianl clear screen"
  },
  "Viv #include": {
    "prefix": "#i",
    "body": ["#include <stdio.h>", "#include <stdlib.h>"],
    "description": "Viv default #includes"
  },
  "Viv function": {
    "prefix": "fc",
    "body": ["void ${1:name}()", "{", "\t$0", "}"],
    "description": "Viv create function"
  }
}
```

### [Ref : Bro Code](https://youtu.be/87SH2Cn0s9A)
