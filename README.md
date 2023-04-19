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
        char, unsigned char     1 Byte
        short, unsigned short   2 Byte
        int, unsigned int       4 Byte
        long, unsigned long     4 Byte
        float                   4 Byte
        double                  8 Byte
        long double             8 Byte
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
>
> 컴파일 전에 프로그램의 소스에 특정한 작업을 수행
> 추가적인 작업, 작성한 소스코드를 변경하지는 않음
> 
> ( 종류 ) 
> 
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
| 이름 | 표준	| 상세 |
|---|---|---|
| <assert.h>      |     |assert 매크로를 포함하며, 이것은 프로그램의 디버깅 버전들에서 논리 오류들과 버그들의 다른 타입들을 탐지하는 것을 돕는데 사용된다.|
| <complex.h>	    | C99 | 복소수를 조작하는데 사용되는 함수들의 집합.|
| <ctype.h>		    |     | 타입에 따라 문자들을 분류하거나 대소문자를 전환하는데 사용되는 함수들의 집합을 정의한다. |
| <errno.h>		    |     | 라이브러리 함수들에 의해 리포트되는 오류 코드들을 테스팅할 때 사용된다.|
| <fenv.h>	      | C99 | 부동소수점 환경을 제어하는데 사용되는 함수들의 집합을 정의한다.|
| <float.h>		    |     | 부동소수점 라이브러리의 구현된 속성을 명시하는 매크로 상수를 정의한다.|
| <inttypes.h>	  | C99 | 정확한 정수형을 정의한다.|
| <iso646.h>	    | NA1 | 여러 표준 토큰들을 표현하기 위한 대체 방식들을 구현하는 여러 매크로들을 정의한다.|
| <limits.h>		  |     | 정수형 타입의 구현된 속성을 명시하는 매크로 상수를 정의한다.|
| <locale.h>		  |     | 지역화 함수 정의|
| <math.h>		    |     | 일반적인 수학 함수 정의|
| <setjmp.h>		  |     | setjmp 와 longjmp 매크로를 선언한다.|
| <signal.h>		  |     | 시그널 핸들링 함수를 정의한다.|
| <stdalign.h>	  | C11 | 객체들의 얼라인먼트를 질의하고 명시하기 위한.|
| <stdarg.h>		  |     | 함수에 전달되는 인자들에 접근하기 위한.|
| <stdatomic.h>	  | C11 | 스레드 사이에서 공유되는 데이터의 원자적 동작을 위한.|
| <stdbool.h>	    | C99 | 불린 데이터 형 정의|
| <stddef.h>		  |     | 여러 유용한 타입과 매크로 정의.|
| <stdint.h>	    | C99 | 정확한 정수형을 정의.|
| <stdio.h>		    |     | 핵심 입력과 출력 함수들을 정의한다.|
| <stdlib.h>		  |     | 숫자 변환 함수들, 슈도 랜덤 숫자 생성 함수들, 메모리 할당, 프로세스 제어 함수들을 정의한다.
| <stdnoreturn.h>	| C11 | 반환하지 않는 함수들을 명시하기 위한|
| <string.h>		  |     | 문자열 처리 함수들을 정의한다.|
| <tgmath.h>	    | C99 | 포괄형 수학 함수들을 정의한다.|
| <threads.h>	    | C11 | 다중 스레드들과 뮤텍스 그리고 제어 변수들을 관리하는 함수들을 정의한다.|
| <time.h>		    |     | 데이터와 시간 처리 함수들을 정의한다.|
| <uchar.h>	      | C11 | 유니코드 문자들과 이것을 조작하는 함수들|
| <wchar.h>	      | NA1 | wide 문자열 처리 함수들을 정의한다.|
| <wctype.h>	    | NA1 | 그들의 형에 따라 wide 문자들을 분류하거나 대소문자를 전환하는데 사용되는 함수들의 집합. |

---

### 변환문자

`%d` : 정수형  
`%c` : 문자형  
`%f` : 실수형  
`%s` : 문자열  
`%o` : 8진수  
`%x` : 16진수  
`%p` : 메모리 주소 출력  
`%%` : % 부호 출력  
`%u` : 10진수 양수 출력  

---

### 탈출/특수문자 ( Escape Sequence )

> Character combination consisting of a backslah -> `\`  
> followed by a letter or combination of digits.  
> They specify actions within a line or string of text.  
>
`\n` : (newline) 커서를 다음 줄로 이동 == `\r\n`  
`\r` : 커서를 줄 처음으로 이동  
`\b` : 백스페이스  
`\v` : 수직 탭  
`\t` : 수평 탭  
`\\` : 백슬레쉬 출력 -> `\`  
`\'` : 작은 따옴표 출력 -> `'`  
`\"` : 큰 따옴표 출력 -> `"`  

---

### 컴파일러간 차이점

> gcc, g++, llvm 및 clang은 모두 다양한 프로그래밍 언어로 코드를 컴파일하는 데 사용되는 서로 다른 컴파일러.
> 주요 차이점 개요  
>

- `gcc`(GNU Compiler Collection)는 C, C++, Objective-C, Fortran, Ada 등 여러 프로그래밍 언어를 위한 컴파일러 모음입니다. 가장 널리 사용되는 컴파일러 중 하나이며 많은 플랫폼에서 사용할 수 있습니다.

- `g++`는 gcc 컬렉션에 포함된 C++ 컴파일러입니다. C++ 코드를 컴파일하는 데 사용됩니다.

- `llvm`(Low-Level Virtual Machine)은 광범위한 프로그래밍 언어용 컴파일러를 구축하는 데 사용할 수 있는 컴파일러 인프라입니다. 컴파일러 및 기타 언어 관련 도구를 빌드하는 데 사용할 수 있는 재사용 가능한 라이브러리 및 도구 세트를 제공합니다.

- `clang`은 llvm 인프라를 기반으로 하는 C, C++ 및 Objective-C 컴파일러입니다. gcc/g++보다 더 빠른 컴파일 시간과 더 나은 오류 메시지를 제공하도록 설계되었습니다. Clang은 복잡한 C++ 코드를 gcc보다 더 잘 처리하는 능력으로도 알려져 있습니다.

> 요약하면 gcc와 g++는 동일한 컬렉션의 일부이며 각각 C 및 C++ 코드를 컴파일하는 데 주로 사용되지만 llvm과 clang은 여러 언어용 컴파일러를 빌드하는 데 사용할 수 있는 별도의 인프라입니다. Clang은 gcc/g++보다 더 빠른 컴파일 시간과 더 나은 오류 메시지로 유명합니다.


