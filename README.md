# `C` Examples

## Ready Programming (macOS)

1. [brew install](https://formulae.brew.sh/) [cmake](https://cmake.org/)
2. Create _`C`_ Project Folder and Move To...
3. Editor _`VSCode`_ ShortCut : `CMD + SHIFT + P`
4. Search and select `CMake: Quick Start`
5. Enter Project `Name` and Select `Executable ...`
6. Etc : _`tasks.json`_, _`c_cpp_properties.json`_ & _`launch.json`_ Create by online references.
7. _Start_

### Demo : Within This `Demo/` Folder

1. `Print.c` : printf, escape sequence

### C 언어 주요 키워드 목록
- auto
- break
- case
- char
- const
- contnue
- default
- do
- double
- else
- enum
- extern
- float
- for
- goto
- if
- int
- long
- register
- retur
- shor
- signed
- sizeof
- static
- struct
- switch
- typdef
- union
- unisgned
- void
- volatile
- while

### 기본 규칙

- `main` 함수 : 프로그램의 시작 진입점 : 프로젝트에서 하나만 존재

```c

int main(void)
{
  return 0;
}

// - `int` : integer 의 약자로 정수를 반환하는 함수의무
// - `;` : 문장의 끝
// - `main(void) == main()` : 주로 void 생략함
// - `return` : 운영체제에게 돌려주는 의미로 0: 이상없이 끝남을 의미
// - `{ }` : 함수의 시작 과 끝 스코프 : CurlyBracket
// - `void` : 매개변수 없음 또는 함수에서 리턴 반환값이 없음
```

---

### VSCode User `Snippets` : 사용자 단축키 지정, 코드 생산성 향상목적

> `VSCode` -> `CMD(CTRL) + SHIFT + P` -> `Snippets: Configure User Snippets` -> `c.json (C)` 
>

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

