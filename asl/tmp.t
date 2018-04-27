function mul
   return
endfunction

function main
  vars
    x 1
    y 1
  endvars

   readi x
   readi y
   %1 = 'x'
   writec %1
   %1 = '*'
   writec %1
   %1 = 'y'
   writec %1
   %1 = '*'
   writec %1
   %1 = '2'
   writec %1
   %1 = '='
   writec %1
   pushparam 
   pushparam x
   pushparam y
   call mul
   popparam 
   popparam 
   popparam mul
   %2 = 2
   %3 = mul * %2
   writei %3
   %4 = '.'
   writec %4
   writeln
   return
endfunction


