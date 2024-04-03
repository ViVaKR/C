.global _start
.p2align 4

_start:
       mov    x2, xzr              ; initialize x2 with 0
loop:
       cmp    x2, #25              ; test if x2 > 16 ?
       b.cs   end_loop             ; if yes, end the loop
       add    x2, x2, #1           ; increase x2
       mov    x0, #1               ; arg[0] = 1 = STDOUT
       adr    x1, msg              ; arg[1] = string to print
       mov    x16, #4              ; Unix write system call, Supervisor Mode.
       svc    #0xFFFF                  ; call kernel to output the string
       b      loop
end_loop:
       mov x0, #0                  ; Use 0 return code
       mov x16, #1                 ; Unix exit system call
       svc #0xFFFF                 ; return 0, call kernel to end program

msg: .ascii "\nHello Kim Bum Jun World\n"


; MacOS Syscall
; #! /usr/bin/env zsh
; # arg example :  `./cat-syscall connect`
; cat /Library/Developer/CommandLineTools/SDKs/MacOSX14.4.sdk/usr/include/sys/syscall.h | grep $1
