# Algorithm

/*

* lldb
 x -s1 -fx -c60 -l20 &str

memory read -fd -s1 -c60 -l20 &str

register read --formant binary x1

register read --format i
re r -f i
register read/d
re r -a
register read --all

memory read --size 4 --format x --count 4 0xbffff3c0
x -s4 -fx -c4 0xbffff3c0
me r -s4 -fx -c4 0xbffff3c0
memory read `argv[0]

Save to file
memory read --outfile /tmp/mem.txt --count 512 0xbffff3c0
me r -o /tmp/mem.txt -c512 0xbffff3c0
x/512bx -o /tmp/mem.txt 0xbffff3c0

starting a 0x10000 and ending a 0x2000 to a file
memory read --outfile /tmp/mem.bin --binary 0x1000 0x2000
me r -o /tmp/mem.bin -b 0x1000 0x2000

command script import lldb.macosx.heap

ptr_refs EXPR
ptr_refs str
ptr_refs &str
cstr_refs CSTRING

disassemble --frame
di -f

disassemble --name main
di -n main

disassemble --frame --bytes
di -f -b

disassemble --line
di -l

image list
image lookup --address 0x1ec4

frame variable
frame variable i

frame variable -fd &str[1]

* /
