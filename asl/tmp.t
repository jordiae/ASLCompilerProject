function fact
  params
    _return
    n
  endparams

  vars
    f 1
  endvars

     %1 = 1
     f = %1
  label startwhile1 :
     %2 = 1
     %3 = n <= %2
     %3 = not %3
     ifFalse %3 goto endwhile1
     %4 = f * n
     f = %4
     %5 = 1
     %6 = n - %5
     n = %6
     goto startwhile1
  label endwhile1 :
     _return = f
     return
endfunction

function main
  vars
    max 1
    i 1
    f 1
    end 1
  endvars

     %1 = 1
     end = %1
     readi max
     %2 = i <= max
     ifFalse %2 goto endif1
     %3 = 0
     end = %3
  label endif1 :
  label startwhile1 :
     %5 = not end
     ifFalse %5 goto endwhile1
     writei i
     %6 = '!'
     writec %6
     %6 = '='
     writec %6
     pushparam 
     pushparam i
     call fact
     popparam 
     popparam %7
     writei %7
     writeln
     %9 = i == max
     ifFalse %9 goto endif2
     %10 = 1
     end = %10
  label endif2 :
     goto startwhile1
  label endwhile1 :
     return
endfunction


