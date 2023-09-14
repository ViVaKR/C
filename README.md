# `C`

> 1972년 켄 톰슨과 데니스 리치에 의해 개발
>
> 운영체제인 유닉스 (UNIX) 개발에 사용

## Ready To Programming (macOS)

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

### 식별자 (Identifier)

- 변수, 형식, 함수 및 레이블에 제공하는 이름
- 식별자 이름은 키워드와 달라야 함

### 메인함수 기본사항

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

### 표준 입력 함수

- 표준 입력 장치 : 다양한 입력 장치 중에 사용하는 시스템이 가장 기본으로 생각하는 장치
- 표준 입력 함수 (Standard Inpu Funtion) : 표준 입력 장치로 부터 데이터를 입력 받기 위해 제공되는 함수
  - 장치의 입력을 읽는 것을 파일에서 데이터를 읽는 것처럼 구성
  - 표준 입력 버터 : 특정 키(주로 엔터키)를 누를 때 까지 사용자 입력을 임시로 저장하는 메모리
    - 키보드 입력 `abc`
    - 입력버퍼에 `abc` 저장
    - 엔터키 -> 문자를 한개만 입력받는 표준 입력 함수 호출
    - 입력버퍼에 `a` 만사용하고 입력버퍼에는 쓰지 못한 `b, c` 가 남음으로 문제가 발생할 소지가 있음
      - 입력 버퍼를 초기화 함수 : fflush, rewind, stdin 포인터와 함께 사용하여 정보제거
      -

---

### VSCode User `Snippets` : 사용자 단축키 지정

> 학습용 데모코드 생산성 향상 목적
>
> `VSCode` -> `CMD(CTRL) + SHIFT + P` -> `Snippets: Configure User Snippets` -> `c.json (C)`

```json
{
  "Viv Printf HelloWorld": {
    "prefix": "pfh", // 일반 문자
    "body": ["printf(\"${1:Hello World}\");$0"],
    "description": "Viv printf With Hello World"
  },
  "Viv Printf Number": {
    "prefix": "pfd", // 정수형
    "body": ["printf(\"${1:Text} %d\\n\",${2:var});$0"],
    "description": "Viv printf Number Type"
  },
  "Viv Printf Character": {
    "prefix": "pfc", // 문자형
    "body": ["printf(\"${1:Text} %c\\n\",${2:var});$0"],
    "description": "Viv printf Character Type"
  },
  "Viv Printf String": {
    "prefix": "pfs", // 문자열 형
    "body": ["printf(\"${1:Text} %s\\n\",${2:var});$0"],
    "description": "Viv printf String (char[]) Type"
  },
  "Viv Printf Float": {
    "prefix": "pff", // 실수 float 형
    "body": ["printf(\"${1:Text} %${2:.2f}\\n\",${3:var});$0"],
    "description": "Viv printf Float Type"
  },
  "Viv Printf Double": {
    "prefix": "pflf", // 실수 double 형
    "body": ["printf(\"${1:Text} %${2:.2lf}\\n\",${3:var});$0"],
    "description": "Viv printf Double Type"
  },
  "Viv Printf UnSigned": {
    "prefix": "pfu",
    "body": ["printf(\"${1:Text} %${2:u}\\n\",${3:var});$0"],
    "description": "Viv printf UnSigned Type"
  },
  "Viv Printf Hex": {
    "prefix": "pfx",
    "body": ["printf(\"${1:Text} %${2:x}\\n\",${3:var});$0"],
    "description": "Viv printf 16진수 Hex Type"
  },
  "Viv Printf Pointer": {
    "prefix": "pfp",
    "body": ["printf(\"${1:Text} %${2:p}\\n\",${3:var});$0"],
    "description": "Viv printf Pointer Type"
  },
  "Viv Printf Long Long Int": {
    "prefix": "pflld",
    "body": ["printf(\"${1:Text} %${2:lld}\\n\",${3:var});$0"],
    "description": "Viv printf long long int"
  },
  "Viv Printf Insert One Line Blank": {
    "prefix": "bk", // 빈 공간 삽입
    "body": ["printf(\"$1\\n\");$0"],
    "description": "Viv printf Blank"
  },
  "Viv Printf Insert Two Line Blank": {
    "prefix": "bbk", // 두칸 빈 공간 삽입
    "body": ["printf(\"$1\\n\\n\");$0"],
    "description": "Viv printf Insert Two Line Blank"
  },
  "Viv Scanf": {
    "prefix": "sf",
    "body": ["scanf(\"%${1:d}\", ${2:var});$0"],
    "description": "Viv scanf integer"
  },
  "Viv Scanf double": {
    "prefix": "sflf",
    "body": ["scanf(\"%lf\", ${1:var});$0"],
    "description": "Viv scanf double"
  },
  "Viv Clear Screen": {
    "prefix": "cls",
    "body": ["system(\"clear\");$0"],
    "description": "Viv termianl clear screen"
  },
  "Viv #include": {
    "prefix": "#i",
    "body": [
      "#include <stdio.h>",
      "#include <stdlib.h>",
      "#include \"stdbool.h\""
    ],
    "description": "Viv default #includes"
  },
  "Viv #include Viv Header": {
    "prefix": "#v",
    "body": ["#include \"../headers/vivstd.h\""],
    "description": "Viv #include Header"
  },
  "Viv Create Function Standard": {
    "prefix": "fc",
    "body": [
      "void ${1:name}()",
      "{",
      "\t/****** ${1:name} *****/",
      "\t$0",
      "}"
    ],
    "description": "Viv Create Function Standard"
  },
  "Viv For Loop Standard": {
    "prefix": "forv",
    "body": "for (int ${1:i} = ${2:0}; ${1:i} < ${3:10}; ${1:i}++) \n{\n\t${0}\n}",
    "description": "Cpp For Loop Standard"
  },
  "Viv Nested For Loop": {
    "prefix": "forn",
    "body": "for (int i = ${1:0}; i < ${2:10}; i++)\n{\n\tfor (int j = ${3:0}; j < ${4:10}; j++)\n\t{\n\t\t${0}\n\t}\n}",
    "description": "Cpp Nested For Loop"
  },
  "Viv For Loop Reverse": {
    "prefix": "forrv",
    "body": "for (int ${1:i} = ${2:10}; ${1:i} >= ${3:0}; --${1:i}) \n{\n\t${0}\n}",
    "description": "Cpp For Loop Reverse"
  }
}
```

### 변수 및 상수 일반사항

```c
/* [ 상수 ]
          숫자상수 : 정수, 실수
          문자상수 : ASCII 코드 값
          ASCII Code : 문자당 7비트를 사용하여 128개 표현 (기호, 제어코드, 알파벳대소문자, 숫자), 양의 정수
    */

    /* [ 변수 ]
       값을 저장하기 위해 메모리에 할당된 공간.
       저장된 값에 액세스하기 위해 변수의 이름을 참조합니다.
       해당 변수는 이제 포함된 값인 것처럼 동작합니다.
       그러나 저장하는 데이터 유형을 선언해야 합니다.
   */

    /* [ 기본 데이터 형식 ]
        char, unsigned char     1 byte
        short, unsigned short   2 byte
        int, unsigned int       4 byte
        long, unsigned long     4 byte
        long long               4 byte
        float                   4 byte
        double                  8 byte
        long double             8 byte or 12byte or 16byte
    */

    /* [ 변수명 ]
        데이터 저장영역 : 바이트 단위
        변수명 : 저장된 값의 메모리 영역의 이름, 메모리 영역에 저장된 상수를 쉽게 사용하기 위함
        선언방식 : `데이터타입 변수명;` char ch[];
        데이터 형식에 따라 메모리 할당
        &변수 : 엠퍼센드 기호를 통하여 변수의 메모리 주소를 가져올 수 있음
        변수명 표기법 : 관례로는 헝가리언 표기법을 사용함, 변수명 앞에 접두사 사용
        헝가리언 표기법 : 변수 및 함수의 인자 이름 앞에 데이터 타입을 명시하는 코딩 규칙
            - 첫 문자와 단어의 첫 문자는 대문자로 표기
            - 단어와 단어를 연결하여 표기
            - 변수명 앞에 접두사 사용
            - 현재에는 거의 사용하지 않음 (인텔리센스 기능의 발달)
    */

   /* [ 헝가리언 표기법의 접두사 ]

        (COMMON)
        b : byte, boolean
        n : int, short
        i : int, short 주로 인덱스로 사용할 때
        c : int, short 주로 크기로 사용
        l : long
        f : float
        d, db : double
        w : word
        dw : double word
        qw : quad word
        ch : char
        sz : NULL 로 끝나는 문자열
        str : C++ 문자열
        arr : 배열(문자열 제외) 다른 접두사와 조합 가능
        p : 포인터 (16비트, 32비트) 다른 접두사와 조합 가능
        lp : 포인터 (32비트, 64비트) 다른 접두사와 조합 가능
        psz : NULL 로 끝나는 문자열을 가리키는 포인터 (16, 32비트)
        lpsz : NULL 로 끝나는 문자열을 가리키는 포인터 (32, 64비트)
        fn : 함수 타입
        pfn : 함수 포인터 (16, 32비트)
        lpfn : 함수 포인터 (64비트)

        (OOP)
        g_ : 네임스페이스의 글로벌 변수
        m_ : 클래스 멤버변수
        s_ : 클래스 static 변수
        c_ : 함수의 static 변수

        (Windows API)
        h : 리소스 핸들 (HWND 를 제외한 모든 HANDLE 타입)

        (현재 추천방식)
        변수에 모든 의미를 충분히 담기 (약어 사용하지 않기)
            좋은 예 : string address, int salary
            나쁜 예 : string nam, string addr, int sal
        한글자로 된 변수명은 특별한 이유 (반복문 반복변수)가 없으면 사용하지 말것
        지역변수에는 변수명 앞에 밑줄을 사용하지 않는다
        멤버변수에 m_ 와 같은 헝가리안 보다는 밑줄을 사용
        키워드와 비슷한 이름을 사용하지 않는다
        boolean 타입은 is 와 같은 접수사를 사용한다.
        파일명은 클래스 명과 같아야 한다.
        파일명은 파스칼 표기법을 사용한다.

        (기타 다양한 표기법)
        파스칼 표기법 : 모든 단어의 첫번째 문자가 대문자이며 나머지는 소문자 C# 클래스 함수명 등 (예) PascalCaseExample
        카멜 표기법 : 최초 단어의 첫 문자는 소문자 이며 나머지는 파스칼 표기법과 동일 C# 지역변수, Java (예) camelCaseExample
        스네이크 표기법 : 단어와 단어 사이를 "_" 연결, (예) snake_case_example
        케밥 표기법 : 단어와 단어 사이를 "-" 로 연결 url, html tag 등 (예) kebab-case-example
        스크림이 스테이크 표기법 : 상수의 표현은 대문자에 snake case 로 표기함 (예) SCREAM_SNAKE_CASE
   */

```

---

### [ASCII CODE (wiki)](https://ko.wikipedia.org/wiki/ASCII)

---

### 전 처리기 지시문 (매크로)

> 컴파일 전에 프로그램의 소스에 특정한 작업을 수행
> 추가적인 작업, 작성한 소스코드를 변경하지는 않음
>
> ( 종류 )

```c
#define
#include : 컴파일할 때 포함 할 라이브러리 파일 지시
#pragma
#endif
#ifndef
#line
#elif
#error
#else
#if
#undef
```

---

### C 표준 라이브러리

| 이름            | 표준 | 상세                                                                                                                              |
| --------------- | ---- | --------------------------------------------------------------------------------------------------------------------------------- |
| <assert.h>      |      | assert 매크로를 포함하며, 이것은 프로그램의 디버깅 버전들에서 논리 오류들과 버그들의 다른 타입들을 탐지하는 것을 돕는데 사용된다. |
| <complex.h>     | C99  | 복소수를 조작하는데 사용되는 함수들의 집합.                                                                                       |
| <ctype.h>       |      | 타입에 따라 문자들을 분류하거나 대소문자를 전환하는데 사용되는 함수들의 집합을 정의한다.                                          |
| <errno.h>       |      | 라이브러리 함수들에 의해 리포트되는 오류 코드들을 테스팅할 때 사용된다.                                                           |
| <fenv.h>        | C99  | 부동소수점 환경을 제어하는데 사용되는 함수들의 집합을 정의한다.                                                                   |
| <float.h>       |      | 부동소수점 라이브러리의 구현된 속성을 명시하는 매크로 상수를 정의한다.                                                            |
| <inttypes.h>    | C99  | 정확한 정수형을 정의한다.                                                                                                         |
| <iso646.h>      | NA1  | 여러 표준 토큰들을 표현하기 위한 대체 방식들을 구현하는 여러 매크로들을 정의한다.                                                 |
| <limits.h>      |      | 정수형 타입의 구현된 속성을 명시하는 매크로 상수를 정의한다.                                                                      |
| <locale.h>      |      | 지역화 함수 정의                                                                                                                  |
| <math.h>        |      | 일반적인 수학 함수 정의                                                                                                           |
| <setjmp.h>      |      | setjmp 와 longjmp 매크로를 선언한다.                                                                                              |
| <signal.h>      |      | 시그널 핸들링 함수를 정의한다.                                                                                                    |
| <stdalign.h>    | C11  | 객체들의 얼라인먼트를 질의하고 명시하기 위한.                                                                                     |
| <stdarg.h>      |      | 함수에 전달되는 인자들에 접근하기 위한.                                                                                           |
| <stdatomic.h>   | C11  | 스레드 사이에서 공유되는 데이터의 원자적 동작을 위한.                                                                             |
| <stdbool.h>     | C99  | 불린 데이터 형 정의                                                                                                               |
| <stddef.h>      |      | 여러 유용한 타입과 매크로 정의.                                                                                                   |
| <stdint.h>      | C99  | 정확한 정수형을 정의.                                                                                                             |
| <stdio.h>       |      | 핵심 입력과 출력 함수들을 정의한다.                                                                                               |
| <stdlib.h>      |      | 숫자 변환 함수들, 슈도 랜덤 숫자 생성 함수들, 메모리 할당, 프로세스 제어 함수들을 정의한다.                                       |
| <stdnoreturn.h> | C11  | 반환하지 않는 함수들을 명시하기 위한                                                                                              |
| <string.h>      |      | 문자열 처리 함수들을 정의한다.                                                                                                    |
| <tgmath.h>      | C99  | 포괄형 수학 함수들을 정의한다.                                                                                                    |
| <threads.h>     | C11  | 다중 스레드들과 뮤텍스 그리고 제어 변수들을 관리하는 함수들을 정의한다.                                                           |
| <time.h>        |      | 데이터와 시간 처리 함수들을 정의한다.                                                                                             |
| <uchar.h>       | C11  | 유니코드 문자들과 이것을 조작하는 함수들                                                                                          |
| <wchar.h>       | NA1  | wide 문자열 처리 함수들을 정의한다.                                                                                               |
| <wctype.h>      | NA1  | 그들의 형에 따라 wide 문자들을 분류하거나 대소문자를 전환하는데 사용되는 함수들의 집합.                                           |

---

### 출력문자 (Format Character)  

`%d`, : 10진 정수 (부호 있음)
`%ld` : long (부호 있음)  
`%c` : 문자형  
`%f`, `lf` : 실수  
`ld` : long (부호 있음)
`lld` : long long (부호 있음)
`u` : 10진 정수 (부호 없음)
`lu` : long (부호 없음)
`%s` : 문자열  
`%o` : 8진수  
`%x` : 16진수  
`%p` : 메모리 주소  
`%u` : 10진 정수 (부호 없음)
`%e` : 실수를 지수 표기법으로 표기 (소문자)

`%-4d` : 4자리 공간을 확보하고왼쪽으로 정렬
`%#x` : 16진수 표기법인 0x 까지 출력

---

### 탈출/특수문자 ( Escape Sequence )

> Character combination consisting of a backslah -> `\`  
> followed by a letter or combination of digits.  
> They specify actions within a line or string of text.
>
> `\n` : (newline) 커서를 다음 줄로 이동 == `\r\n`  
> `\r` : 커서를 줄 처음으로 이동  
> `\b` : 백스페이스  
> `\v` : 수직 탭  
> `\t` : 수평 탭  
> `\\` : 백슬레쉬 출력 -> `\`  
> `\'` : 작은 따옴표 출력 -> `'`  
> `\"` : 큰 따옴표 출력 -> `"`

---

### 컴파일러간 차이점

> gcc, g++, llvm 및 clang은 모두 다양한 프로그래밍 언어로 코드를 컴파일하는 데 사용되는 서로 다른 컴파일러.
> 주요 차이점 개요

- `gcc`(GNU Compiler Collection)는 C, C++, Objective-C, Fortran, Ada 등 여러 프로그래밍 언어를 위한 컴파일러 모음입니다. 가장 널리 사용되는 컴파일러 중 하나이며 많은 플랫폼에서 사용할 수 있습니다.

- `g++`는 gcc 컬렉션에 포함된 C++ 컴파일러입니다. C++ 코드를 컴파일하는 데 사용됩니다.

- `llvm`(Low-Level Virtual Machine)은 광범위한 프로그래밍 언어용 컴파일러를 구축하는 데 사용할 수 있는 컴파일러 인프라입니다. 컴파일러 및 기타 언어 관련 도구를 빌드하는 데 사용할 수 있는 재사용 가능한 라이브러리 및 도구 세트를 제공합니다.

- `clang`은 llvm 인프라를 기반으로 하는 C, C++ 및 Objective-C 컴파일러입니다. gcc/g++보다 더 빠른 컴파일 시간과 더 나은 오류 메시지를 제공하도록 설계되었습니다. Clang은 복잡한 C++ 코드를 gcc보다 더 잘 처리하는 능력으로도 알려져 있습니다.

> 요약하면 gcc와 g++는 동일한 컬렉션의 일부이며 각각 C 및 C++ 코드를 컴파일하는 데 주로 사용되지만 llvm과 clang은 여러 언어용 컴파일러를 빌드하는 데 사용할 수 있는 별도의 인프라입니다. Clang은 gcc/g++보다 더 빠른 컴파일 시간과 더 나은 오류 메시지로 유명합니다.

---

### 포인터

- `메모리 주소를 저장`하는 변수
- 일반변수와 포인터 변수와의 차이점

| -           | 공통점  | 차이점           |
| ----------- | ------- | ---------------- |
| 일반 변수   | 값 저장 | 상수 저장        |
| 포인터 변수 | 값 저장 | 메모리 주소 저장 |

- (간접) 참조 연산자 : `*`, 선언된 변수가 포인터 변수임을 나타냄
- 참조 : `접근` 과 동일한 의미
- ( `*` ) 의 의미 : 포인터 변수에 저장된 메모리 주소로 접근한 메모리 영역의 데이터(값)을 의미
- 선언방식 : _int_ `*nVar;` _char_ `*cVar;` _float_ `*fVar;`
- 데이터 형에 관계없이 메모리 주소를 저장하므로 _`4바이트`_ 크기를 동일하게 가짐
- `*pVar` : 포인터 변수 `pVar` 에 저장된 메모리 주소에 접근하여 그 주소에 저장 된 값을 의미함
- `&` ( ampersand ): 주소연산자 변수의 메모리 주소
  - int nVar = 7;
  - int \*nPtr = &nVar;
  - 포인터 -> `nPtr`
- 포인터 역할 : 임의의 메모리에 접근하여 값을 저장하거나 읽는 역할
- 포인터를 활용한 메모리 생성과 해제
- 문자열 다루기

---

| 메모리 기본구조 |                                 |     |
| --------------- | ------------------------------- | --- |
| Stack           | 지역변수, 매개변수              |
| Heap            | 동적할당                        |
| Data            | 정적변수, 상수 (데이터세그먼트) |
| Code            | 함수코드 (코드세그먼트)         |

> 32비트 CPU / 4바이트 (8 \* 4 = 32) 표현범위 : 42.9억 ( 0 ~ FFFF FFFF)
>
> _`char`_ : | 1 |
>
> _`int`_ : | 1 | 1 | 1 | 1 |
>
> 주소연산자 : `&`

---

### 문자열 배열 vs 문자열 포인터

---

| 일반 배열                                                      | 포인터 배열                                                                    |
| -------------------------------------------------------------- | ------------------------------------------------------------------------------ |
| char a[] = "apple"                                             | char \*b = "banana",                                                           |
| a 와 apple 문자열 모두 스택영역에 있으며 a는 시작(0) 주소 상수 | 스택영역에는 변수 b -> data 영역에 상수로 "banana" 위치함                      |
| a -> `"a"`                                                     | b -> `"banana"`                                                                |
| (안됨)                                                         | `b = "change";` (됨)                                                           |
| -                                                              | `printf("%c", b);` -> `change`                                                 |
| 요소별로 할당 및 변경처리                                      | 새로운 문자상수 주소로 갱신 (기존 문자 상수가 가비지로 유지됨)                 |
| -                                                              | 즉, b에 지정된 값이 `banana` 에서 `change` 문자상수가 저장된 주소값으로 변경됨 |
| strcpy(a, "mango"); (됨)                                       | (안됨)                                                                         |
| n 차원 배열                                                    | 포인터 배열                                                                    |

---

### 배열포인터 vs 포인터배열

- 배열 포인터
  - int [\*p](5);
  - 각각 int 형 5개 크기의 배열들을 저장하는 포인터
- 포인터 배열
  - int \*p[5];
  - 배열의 첫번째 주소(포인터) 들을 저장하는 배열

### const 위치에따른 의미 차이

> `const int *p;` --> `*p` 값을 못바꿈  
> `int * const p;` --> `p` 값을 못바꿈  
> `const int * const p;` --> `*p`, `p` 값을 못바꿈

### 보수

1. 양수는 보수 처리 하지 않음
2. 가중치 x
3. +0, -0 공존
4. 연산결과 음수일 때 : 2의 보수 처리

### 함수내부의 지역변수

함수안에 선언한 변수나 매개변수
함수와 같은 수명을 가짐
지역변수는 스스로 초기화되지 않음

### 공용체

- 구초체와 같이 사용자 정의 자료형
- 공용체 (union)는 구조체와 문법 구조와 유사
- union 키워드 사용
- 용도 : 메모리를 절약하는 용도로 사용됨, 끝판왕

> 정의

```c
  typedef union ConvertData
  {
    char cData;       /* 1byte */
    short int sData;  /* 2byte */
    int iData;        /* 4byte */
  } CD;

  CD temp;
  temp.iData = 0x12345678;
  | 0x78 | 0x56 | 0x34 | 0x12 |

  /* union ConvertData temp; 와 동일 */
  // 공용체의 요소들은 할당된 메모리를 공유함
  // 공용체로 만든 자료형의 크기는 요소 중 가장 큰 요소의 크기와 동일
  // 즉, 가장 큰 4바이트가 ConvertData 의 크기가 되며
  // 공용체의 요소들은 서로 같은 메모리를 공유


```
