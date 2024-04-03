# Note

## lldb debug

-> clang -g vivakr.c -o ./debug/vivakr

-> lldb ./prog
-> (lldb) run # error stop
-> (lldb) target create prog # re-launch

list 10

## break points

-> (lldb) b hi.cpp : 4

b main
br s -n main
br s -f helloworld.cpp -l 23
b test.c:12
b helloworld.cpp:29
breakpoint set --method main
br s -M main
lldb ./a.out

(lldb) b list
(lldb) br del 4
(lldb) br del

-> (lldb) list 10 # view source line numberSZF DEXGRCTHVJKL;',/L$$

## Step Into

-> (lldb) si # 지시 수준 신호 단계.
-> (lldb) s # 소스 레벨 신호 단계.

## back trace

-> (lldb) bt # 어떻게 해당 라인에 도달하였는지 알려줌

## Continue

-> (lldb) c

## Next

-> (lldb) n # next step

## Re Launch

-> (lldb) target create prog

-> (lldb) run

## GUI

-> (lldb) gui # after break point and run
-->  n or s key movement
--> tab key and space -> view variable

## Stepping Around

Step Over
(lldb) next
(lldb) n

Step Into
(lldb) step
(lldb) s

## Step

- Step into : 호출 되는 함수까지 포함 하여 한줄 한줄 실행
	만약 현재 코드라인이 함수라면, 해당 함수 내부로 진입한 이후
	한 줄씩 실행함
	즉, 함수 내부로 진입함

- Step over : 함수 단위로 코드를 실행
	현재 코드라인을 실행하고 다음 라인으로 이동 하되
	만약 현재 코드라인이 함수라면, 해당 함수를 실행은 하되
	디버거는 함수 안에서 먼추지 않는다.
	즉, 함수는 실행하면서 지나감
	특정 함수가 잘 동작하는지만을 확인할 때 사용함

- Step out : 함수에서 나감.
	만약 현재 코드라인이 함수 안이라면, 해당 함수는 끝까지 실행하고 반환하고 멈춤
	함수 안에서 한 줄 한 줄 디버깅하면서 더이상 오류가 없어 함수 실행을 멈출때

s : step into
si : thread step-inst
n : next, thread step-over
ni : thread step-inst-over
finish
r

(lldb) c

thread backtrace
bt

register read
register write rax 123

clang++ -O3 hi.cpp -o hi

`cmake -DCMAKE_BUILD_TYPE=Debug`

lldb a.out
lldb -- a.out argument1

## Running

```bash

(lldb) run
(lldb) r

(lldb) break set -f hi.cpp -l #
(lldb) br s -f hi.cpp -l #
(lldb) b hi.cpp :

```

```bash

# 화면으로 읽기
memory read -s1 -fu -c 8 0x000000013c904080

# 파일로 출력
memory read -o /tmp/mem.txt -c512 0x000000013c904080

long *values = new long[9]{...};

(lldb) expr typedef struct { long values[9]; } l9; *(l9 *)values

memory read -s1 -fx -c 8 0x13af043c8


(lldb)  memory read --size 8 --format x --count 1 ($rbp+0x20)
0x7fff5e348660: 0x0000000000000008
(lldb)  memory read --size 8 --format x --count 1 ($rbp+0x18)
0x7fff5e348658: 0x000000000000000a
(lldb)  memory read --size 8 --format x --count 1 ($rsp+0x8)
0x7fff5e348438: 0x000000000000000a
(lldb)  memory read --size 8 --format x --count 1 ($rsp+0x10)
0x7fff5e348440: 0x0000000000000008



$ lldb hello
$ lldb
$ file /path/to/file/hello

# argument
$ lldb -- programe -arg1 arg2

$ help di
$ breakpoint set -n main

$ breakpoint set -f main.cc -l 39
$ breakpoint list (br l)
$ breakpoint delete 4

# delete all
$ br del

$ watch set var global
$ wa l

# Start the application
$ r

# Single Step
$ s

# Step in (source level) :  해당 함수 내부로 진입한 이후 한 줄씩 짚어가며 넘어간다.
$ s

# Step over (source level) : 함수안으로 들어가지 않고 잘 동작하는지만 확인함, 함수 전체를 실행하면서 지남.
$ n

# Step out : 현재 함수내부안이라면 해당 함수는 끝까지 실행하고 반환하고 해당 함수를 마친다. 스택을 팝하는 동작
$

# Continue : 다름 브레이크 포인트까지 쭉 진행

# Step in (instruction level)
$ si

# Step over (instruction level)

# Step over (instruction level)


( Exampine memory )

# On the stack
$ x -s4 -fx -c24 $xsp

x/24wx $rsp

register read

frame variable (fr v)
frame variable <var-name>

ld
tr (thread backtrace)

bt

thread list

# Diassembly
di -n main

ps aux | grep "program_name"
$ leaks <pid>

objdump -d hello.0
objdump -s hello.o # memory view


```
