'a'   SPACE   a
'z'   SPACE   z
'A'   SPACE   A
'Z'   SPACE   Z
'7'   SPACE   7
'a'   SPACE   a
'a'   SPACE   a
'z'   SPACE   z
'A'   SPACE   A
'Z'   SPACE   Z
'\n'   SPACE   \
'\n'   SPACE   \
'9'   SPACE   9
'\n'   SPACE   \
function main
  vars
    c1 1
    c2 1
    c3 1
    c4 1
    tmp 1
    b 1
  endvars

     %1 = 'a'
     c1 = %1
     %2 = 'z'
     c2 = %2
     %3 = 'A'
     c3 = %3
     %4 = 'Z'
     c4 = %4
     %5 = '7'
     tmp = %5
  label startwhile1 :
     %6 = 'a'
     %7 = tmp == %6
     %7 = not %7
     ifFalse %7 goto endwhile1
     readc tmp
     %8 = 'a'
     %9 = tmp < %8
     %9 = not %9
     %10 = 'z'
     %11 = tmp <= %10
     %12 = %9 and %11
     ifFalse %12 goto endif1
     %13 = 'M'
     writec %13
     %13 = 'I'
     writec %13
     %13 = 'N'
     writec %13
     %13 = 'U'
     writec %13
     %13 = 'S'
     writec %13
  label endif1 :
     %14 = 'A'
     %15 = tmp < %14
     %15 = not %15
     %16 = 'Z'
     %17 = tmp <= %16
     %18 = %15 and %17
     ifFalse %18 goto endif2
     %19 = 'M'
     writec %19
     %19 = 'A'
     writec %19
     %19 = 'Y'
     writec %19
     %19 = 'U'
     writec %19
     %19 = 'S'
     writec %19
  label endif2 :
     writeln
     goto startwhile1
  label endwhile1 :
     writec tmp
     %21 = '\'
     writec %21
     tmp = c4
     writec tmp
     %22 = '\'
     writec %22
     %23 = '9'
     writec %23
     %24 = '\'
     writec %24
     return
endfunction


