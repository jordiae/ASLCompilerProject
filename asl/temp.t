function f1
  params
    a
    b
  endparams

  vars
    c 1
    d 1
    found 1
  endvars

     %1 = 0
     found = %1
     %2 = 0.7
     %4 = float a
     %3 = %4 +. %2
     c = %3
     %5 = 0
     d = %5
     %6 = a + d
     %8 = float %6
     %7 = %8 <=. c
     %7 = not %7
     %9 = not found
     %10 = %9 or %7
     ifFalse %10 goto endif1
  label startwhile1 :
     %11 = 0
     %12 = b <= %11
     %12 = not %12
     ifFalse %12 goto endwhile1
     %13 = 1
     %14 = b - %13
     b = %14
     %15 = 1
     found = %15
     goto startwhile1
  label endwhile1 :
  label endif1 :
     %16 = 11
     %17 = b <= %16
     ifFalse %17 goto endif2
     %18 = 2
     %20 = float %18
     %19 = %20 *. c
     %21 = 1
     %23 = float %21
     %22 = %19 +. %23
     c = %22
  label endif2 :
     writef c
     writeln
     return
endfunction

function main
  vars
    a 1
    b 1
  endvars

   %1 = 4
   a = %1
   %2 = 2
   %3 = %2 * a
   %4 = 1
   %5 = %3 + %4
   b = %5
   pushparam b
   %6 = 3
   %7 = %6 + b
   pushparam %7
   call f1
   popparam 
   popparam 
   return
endfunction


